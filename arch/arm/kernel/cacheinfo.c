/*
 *  ARM cacheinfo support
 *
 *  Copyright (C) 2014 ARM Ltd.
 *  All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 * kind, whether express or implied; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/bitops.h>
#include <linux/cacheinfo.h>
#include <linux/cpu.h>
#include <linux/compiler.h>
#include <linux/of.h>

#include <asm/cputype.h>
#include <asm/processor.h>
#include <asm/system_info.h>

#define cache_is_armv7() \
	(cpu_architecture() >= CPU_ARCH_ARMv7 && !armv6_extended())
#define MAX_CACHE_LEVEL		(cache_is_armv7() ? 7 : 1)

#define CTR_CTYPE_SHIFT		24
#define CTR_CTYPE_MASK		(1 << CTR_CTYPE_SHIFT)

struct ctr_info {
	unsigned int cpuid_part;
	unsigned int ctr;
};

/*
 *  Cache Type Register
 *  +---------------------------------+
 *  | 31 29 | 28 25 |24| 23 12 | 11 0 |
 *  +---------------------------------+
 *  | 0 0 0 | Ctype | S| Dsize | Isize|
 *  +---------------------------------+
 * The table below encodes only Dsize and Isize
 */
static struct ctr_info cache_ctr_list[] = {
	{0x4400a100, 0x0016A16A }, /* SA-110:  32kB D$, 32kB I$ */
	{0x4400a110, 0x0012A16A }, /* SA-1100: 16kB D$, 32kB I$ */
	{0x6900b110, 0x0012A16A }, /* SA-1110: 16kB D$, 32kB I$ */
};

/*
 * List of CPUs reported as ARMv7 but don't implement CLIDR,
 * CSSELR and CCSIDR. Cache information is still available from CTR
 */
static int armv6_ext_cpuid_part[] = {
	0x4100b020, /* ARM11MP */
	0x4100b760, /* ARM1176 */
};

static bool armv6_extended(void)
{
	int i, cpuid_part = read_cpuid_part();

	for (i = 0; i < ARRAY_SIZE(armv6_ext_cpuid_part); i++)
		if (armv6_ext_cpuid_part[i] == cpuid_part)
			return true;
	return false;
}

static int get_unimplemented_ctr(unsigned int *ctr)
{
	int i, cpuid_part = read_cpuid_part();

	for (i = 0; i < ARRAY_SIZE(cache_ctr_list); i++)
		if (cache_ctr_list[i].cpuid_part == cpuid_part) {
			*ctr = cache_ctr_list[i].ctr;
			return 0;
		}
	return -ENOENT;
}

static unsigned int get_ctr(void)
{
	unsigned int ctr;

	if (get_unimplemented_ctr(&ctr))
		ctr = read_cpuid_cachetype();
	return ctr;
}

static enum cache_type __get_cache_type(int level)
{
	if (level > MAX_CACHE_LEVEL)
		return CACHE_TYPE_NOCACHE;
	return get_ctr() & CTR_CTYPE_MASK ?
		CACHE_TYPE_SEPARATE : CACHE_TYPE_UNIFIED;
}

/*
 *  +---------------------------------+
 *  | 9  8  7  6 | 5  4  3 | 2 | 1  0 |
 *  +---------------------------------+
 *  |    size    |  assoc  | m |  len |
 *  +---------------------------------+
 * linelen        = 1 << (len + 3)
 * multiplier     = 2 + m
 * nsets          = 1 << (size + 6 - assoc - len)
 * associativity  = multiplier << (assoc - 1)
 * cache_size     = multiplier << (size + 8)
 */
#define CTR_LINESIZE_MASK	0x3
#define CTR_MULTIPLIER_SHIFT	2
#define CTR_MULTIPLIER_MASK	0x1
#define CTR_ASSOCIAT_SHIFT	3
#define CTR_ASSOCIAT_MASK	0x7
#define CTR_SIZE_SHIFT		6
#define CTR_SIZE_MASK		0xF
#define CTR_DCACHE_SHIFT	12

static void __ci_leaf_init(enum cache_type type, struct cacheinfo *this_leaf)
{
	unsigned int size, multiplier, assoc, len, tmp = get_ctr();

	if (type == CACHE_TYPE_DATA)
		tmp >>= CTR_DCACHE_SHIFT;

	len = tmp & CTR_LINESIZE_MASK;
	size = (tmp >> CTR_SIZE_SHIFT) & CTR_SIZE_MASK;
	assoc = (tmp >> CTR_ASSOCIAT_SHIFT) & CTR_ASSOCIAT_MASK;
	multiplier = ((tmp >> CTR_MULTIPLIER_SHIFT) & CTR_MULTIPLIER_MASK) + 2;

	this_leaf->type = type;
	this_leaf->coherency_line_size = 1 << (len + 3);
	this_leaf->number_of_sets = 1 << (size + 6 - assoc - len);
	this_leaf->ways_of_associativity = multiplier << (assoc - 1);
	this_leaf->size = multiplier << (size + 8);
}

/* Ctypen, bits[3(n - 1) + 2 : 3(n - 1)], for n = 1 to 7 */
#define CLIDR_CTYPE_SHIFT(level)	(3 * (level - 1))
#define CLIDR_CTYPE_MASK(level)		(7 << CLIDR_CTYPE_SHIFT(level))
#define CLIDR_CTYPE(clidr, level)	\
	(((clidr) & CLIDR_CTYPE_MASK(level)) >> CLIDR_CTYPE_SHIFT(level))

static inline enum cache_type __armv7_get_cache_type(int level)
{
	unsigned int clidr;

	if (level > MAX_CACHE_LEVEL)
		return CACHE_TYPE_NOCACHE;
	asm volatile ("mrc p15, 1, %0, c0, c0, 1" : "=r" (clidr));
	return CLIDR_CTYPE(clidr, level);
}

/*
 * NumSets, bits[27:13] - (Number of sets in cache) - 1
 * Associativity, bits[12:3] - (Associativity of cache) - 1
 * LineSize, bits[2:0] - (Log2(Number of words in cache line)) - 2
 */
#define CCSIDR_WRITE_THROUGH		BIT(31)
#define CCSIDR_WRITE_BACK		BIT(30)
#define CCSIDR_READ_ALLOCATE		BIT(29)
#define CCSIDR_WRITE_ALLOCATE		BIT(28)
#define CCSIDR_LINESIZE_MASK		0x7
#define CCSIDR_LINESIZE(x)		((x) & CCSIDR_LINESIZE_MASK)
#define CCSIDR_ASSOCIATIVITY_SHIFT	3
#define CCSIDR_ASSOCIATIVITY_MASK	0x3ff
#define CCSIDR_ASSOCIATIVITY(x)	\
	(((x) >> CCSIDR_ASSOCIATIVITY_SHIFT) & CCSIDR_ASSOCIATIVITY_MASK)
#define CCSIDR_NUMSETS_SHIFT		13
#define CCSIDR_NUMSETS_MASK		0x7fff
#define CCSIDR_NUMSETS(x) \
	(((x) >> CCSIDR_NUMSETS_SHIFT) & CCSIDR_NUMSETS_MASK)

#define CACHE_LINESIZE(x)		(16 << CCSIDR_LINESIZE(x))
#define CACHE_NUMSETS(x)		(CCSIDR_NUMSETS(x) + 1)
#define CACHE_ASSOCIATIVITY(x)		(CCSIDR_ASSOCIATIVITY(x) + 1)

/*
 * Cache Size Selection Register(CSSELR) selects which Cache Size ID
 * Register(CCSIDR) is accessible by specifying the required cache
 * level and the cache type. We need to ensure that no one else changes
 * CSSELR by calling this in non-preemtible context
 */
static u32 __attribute_const__ cache_get_ccsidr(u32 csselr)
{
	u32 ccsidr;

	/* Put value into CSSELR */
	asm volatile ("mcr p15, 2, %0, c0, c0, 0" : : "r" (csselr));
	isb();
	/* Read result out of CCSIDR */
	asm volatile ("mrc p15, 1, %0, c0, c0, 0" : "=r" (ccsidr));

	return ccsidr;
}

static void __armv7_ci_leaf_init(enum cache_type type,
				 struct cacheinfo *this_leaf)
{
	bool is_icache = type & CACHE_TYPE_INST;
	u32 tmp = cache_get_ccsidr((this_leaf->level - 1) << 1 | is_icache);

	this_leaf->type = type;
	this_leaf->coherency_line_size = CACHE_LINESIZE(tmp);
	this_leaf->number_of_sets = CACHE_NUMSETS(tmp);
	this_leaf->ways_of_associativity = CACHE_ASSOCIATIVITY(tmp);
	this_leaf->size = this_leaf->number_of_sets *
	    this_leaf->coherency_line_size * this_leaf->ways_of_associativity;
	this_leaf->attributes =
		((tmp & CCSIDR_WRITE_THROUGH) ? CACHE_WRITE_THROUGH : 0) |
		((tmp & CCSIDR_WRITE_BACK) ? CACHE_WRITE_BACK : 0) |
		((tmp & CCSIDR_READ_ALLOCATE) ? CACHE_READ_ALLOCATE : 0) |
		((tmp & CCSIDR_WRITE_ALLOCATE) ? CACHE_WRITE_ALLOCATE : 0);
}

static inline enum cache_type get_cache_type(int level)
{
	if (cache_is_armv7())
		return __armv7_get_cache_type(level);
	return __get_cache_type(level);
}

static void ci_leaf_init(struct cacheinfo *this_leaf,
			 enum cache_type type, unsigned int level)
{
	this_leaf->level = level;
	if (cache_is_armv7())
		__armv7_ci_leaf_init(type, this_leaf);
	else
		__ci_leaf_init(type, this_leaf);
}

static int __init_cache_level(unsigned int cpu)
{
	unsigned int ctype, level, leaves;
	struct cpu_cacheinfo *this_cpu_ci = get_cpu_cacheinfo(cpu);

	for (level = 1, leaves = 0; level <= MAX_CACHE_LEVEL; level++) {
		ctype = get_cache_type(level);
		if (ctype == CACHE_TYPE_NOCACHE) {
			level--;
			break;
		}
		/* Separate instruction and data caches */
		leaves += (ctype == CACHE_TYPE_SEPARATE) ? 2 : 1;
	}

	this_cpu_ci->num_levels = level;
	this_cpu_ci->num_leaves = leaves;

	return 0;
}

static int __populate_cache_leaves(unsigned int cpu)
{
	unsigned int level, idx;
	enum cache_type type;
	struct cpu_cacheinfo *this_cpu_ci = get_cpu_cacheinfo(cpu);
	struct cacheinfo *this_leaf = this_cpu_ci->info_list;

	for (idx = 0, level = 1; level <= this_cpu_ci->num_levels &&
	     idx < this_cpu_ci->num_leaves; idx++, level++) {
		type = get_cache_type(level);
		if (type == CACHE_TYPE_SEPARATE) {
			ci_leaf_init(this_leaf++, CACHE_TYPE_DATA, level);
			ci_leaf_init(this_leaf++, CACHE_TYPE_INST, level);
		} else {
			ci_leaf_init(this_leaf++, type, level);
		}
	}
	return 0;
}

DEFINE_SMP_CALL_CACHE_FUNCTION(init_cache_level)
DEFINE_SMP_CALL_CACHE_FUNCTION(populate_cache_leaves)
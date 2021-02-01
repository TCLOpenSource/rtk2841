#ifndef __OF_RESERVED_MEM_H
#define __OF_RESERVED_MEM_H

struct device;
struct of_phandle_args;
struct reserved_mem_ops;

struct reserved_mem {
	const char			*name;
	unsigned long			fdt_node;
	unsigned long			phandle;
	const struct reserved_mem_ops	*ops;
	phys_addr_t			base;
	phys_addr_t			size;
	void				*priv;
	int				is_sub_region;
};

struct reserved_mem_ops {
	int	(*device_init)(struct reserved_mem *rmem,
			       struct device *dev);
	void	(*device_release)(struct reserved_mem *rmem,
				  struct device *dev);
};

typedef int (*reservedmem_of_init_fn)(struct reserved_mem *rmem);

#define RESERVEDMEM_OF_DECLARE(name, compat, init)			\
	_OF_DECLARE(reservedmem, name, compat, init, reservedmem_of_init_fn)

#ifdef CONFIG_OF_RESERVED_MEM
int of_reserved_mem_device_init(struct device *dev);
void of_reserved_mem_device_release(struct device *dev);

void fdt_init_reserved_mem(void);
void fdt_reserved_mem_save_node(unsigned long node, const char *uname,
			       phys_addr_t base, phys_addr_t size);
void fdt_reserved_mem_save_node_ext(unsigned long node, const char *uname,
			       phys_addr_t base, phys_addr_t size, int is_sub_region);

unsigned long fdt_get_carvedout_mem_size_in_highmem(unsigned long high_start, unsigned long high_end);
unsigned long fdt_get_carvedout_mem_info(char *reserved_mem_name, void **addr);
#else
static inline int of_reserved_mem_device_init(struct device *dev)
{
	return -ENOSYS;
}
static inline void of_reserved_mem_device_release(struct device *pdev) { }

static inline void fdt_init_reserved_mem(void) { }
static inline void fdt_reserved_mem_save_node(unsigned long node,
		const char *uname, phys_addr_t base, phys_addr_t size) { }
static inline void fdt_reserved_mem_save_node_ext(unsigned long node,
		const char *uname, phys_addr_t base, phys_addr_t size, int is_sub_region) { }

static inline unsigned long fdt_get_carvedout_mem_size_in_highmem(unsigned long high_start, unsigned long high_end) { }
static inline unsigned long fdt_get_carvedout_mem_info(char *reserved_mem_name, void **addr) { }
#endif

#endif /* __OF_RESERVED_MEM_H */

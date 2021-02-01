/***************************************************************
*
*
*
*	magellan nand flash driver patch
*
*	magellan nand flash driver porting from mac2 platform
*
*
*
****************************************************************/
#ifndef __RTK_MTD_PATCH_H__
#define __RTK_MTD_PATCH_H__

//rtk_mtd_patch
static inline int is_jupiter_cpu(void)
{
	return 0;
}

static inline int is_saturn_cpu(void)
{
	return 0;
}

static inline int is_darwin_cpu(void)
{
	return 0;
}

static inline int is_macarthur_cpu(void)
{
	return 0;		
}

static inline int is_macarthur2_cpu(void)
{
	return 0;		

}

static inline int is_nike_cpu(void)
{
	return 0;	
}

static inline int is_magellan_cpu(void)
{
	return 0;	
}

static inline int is_sirius_cpu(void)
{
	return 0;		

}

static inline int is_296x_cpu(void)
{
	return 1;		

}

static inline int is_venus_cpu(void)
{
	return 0;
}

static inline int is_neptune_cpu(void)
{
	return 0;
}

static inline int is_mars_cpu(void)
{
	return 0;
}


#define padlock(x)
#define padunlock(x)

/*
 * Debugging macro and defines
 */
#define MTD_DEBUG_LEVEL0	(0)	/* Quiet   */
#define MTD_DEBUG_LEVEL1	(1)	/* Audible */
#define MTD_DEBUG_LEVEL2	(2)	/* Loud    */
#define MTD_DEBUG_LEVEL3	(3)	/* Noisy   */

#ifdef CONFIG_MTD_DEBUG
#define DEBUG(n, args...)				\
	do {						\
		if (n <= CONFIG_MTD_DEBUG_VERBOSE)	\
			printk(KERN_INFO args);		\
	} while(0)
#else /* CONFIG_MTD_DEBUG */
#define DEBUG(n, args...)				\
	do {						\
		if (0)					\
			printk(KERN_INFO args);		\
	} while(0)

#endif /* CONFIG_MTD_DEBUG */


#endif

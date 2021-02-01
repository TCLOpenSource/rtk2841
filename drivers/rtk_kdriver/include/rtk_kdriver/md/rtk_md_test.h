#ifndef __RTK_MD_TEST_H__
#define __RTK_MD_TEST_H__

#ifdef CONFIG_RTK_KDRV_MD_TEST
extern void rtk_md_unit_test(void);
extern void md_unit_test(int length);
extern void md_fill_test(void);
extern void md_test_all(int length);
extern int multi_vs_signal(unsigned int length, unsigned int number);
#endif

#endif
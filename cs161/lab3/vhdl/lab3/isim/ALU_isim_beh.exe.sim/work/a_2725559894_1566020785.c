/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x2f00eba5 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Documents and Settings/Embedded Systems Lab/Desktop/lab3/vhdl/ALU_S10.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3620187407;
extern char *WORK_P_4132818205;

char *ieee_p_2592010699_sub_1735675855_503743352(char *, char *, char *, char *, char *, char *);
char *ieee_p_2592010699_sub_795620321_503743352(char *, char *, char *, char *, char *, char *);
unsigned char ieee_p_3620187407_sub_1742983514_3965413181(char *, char *, char *, char *, char *);
char *ieee_p_3620187407_sub_767668596_3965413181(char *, char *, char *, char *, char *, char *);
char *ieee_p_3620187407_sub_767740470_3965413181(char *, char *, char *, char *, char *, char *);


static void work_a_2725559894_1566020785_p_0(char *t0)
{
    char t13[16];
    char *t1;
    char *t2;
    char *t3;
    int t4;
    char *t5;
    int t6;
    char *t7;
    int t8;
    char *t9;
    int t10;
    char *t11;
    int t12;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned char t23;

LAB0:    xsi_set_current_line(33, ng0);
    t1 = (t0 + 776U);
    t2 = *((char **)t1);
    t1 = (t0 + 1200U);
    t3 = *((char **)t1);
    t4 = xsi_mem_cmp(t3, t2, 3U);
    if (t4 == 1)
        goto LAB3;

LAB9:    t1 = (t0 + 1268U);
    t5 = *((char **)t1);
    t6 = xsi_mem_cmp(t5, t2, 3U);
    if (t6 == 1)
        goto LAB4;

LAB10:    t1 = (t0 + 1336U);
    t7 = *((char **)t1);
    t8 = xsi_mem_cmp(t7, t2, 3U);
    if (t8 == 1)
        goto LAB5;

LAB11:    t1 = (t0 + 1404U);
    t9 = *((char **)t1);
    t10 = xsi_mem_cmp(t9, t2, 3U);
    if (t10 == 1)
        goto LAB6;

LAB12:    t1 = (t0 + 1472U);
    t11 = *((char **)t1);
    t12 = xsi_mem_cmp(t11, t2, 3U);
    if (t12 == 1)
        goto LAB7;

LAB13:
LAB8:    xsi_set_current_line(45, ng0);
    t1 = ((WORK_P_4132818205) + 1012U);
    t2 = *((char **)t1);
    t1 = (t0 + 1132U);
    t3 = *((char **)t1);
    t1 = (t3 + 0);
    memcpy(t1, t2, 32U);

LAB2:    xsi_set_current_line(48, ng0);
    t1 = (t0 + 1132U);
    t2 = *((char **)t1);
    t1 = (t0 + 4416U);
    t3 = ((WORK_P_4132818205) + 1012U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_4132818205) + 9656U);
    t23 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t5, t3);
    if (t23 != 0)
        goto LAB18;

LAB20:    xsi_set_current_line(51, ng0);
    t1 = (t0 + 2268);
    t2 = (t1 + 32U);
    t3 = *((char **)t2);
    t5 = (t3 + 40U);
    t7 = *((char **)t5);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB19:    xsi_set_current_line(54, ng0);
    t1 = (t0 + 1132U);
    t2 = *((char **)t1);
    t1 = (t0 + 2304);
    t3 = (t1 + 32U);
    t5 = *((char **)t3);
    t7 = (t5 + 40U);
    t9 = *((char **)t7);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 2224);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(34, ng0);
    t1 = (t0 + 592U);
    t14 = *((char **)t1);
    t1 = (t0 + 4352U);
    t15 = (t0 + 684U);
    t16 = *((char **)t15);
    t15 = (t0 + 4368U);
    t17 = ieee_p_2592010699_sub_795620321_503743352(IEEE_P_2592010699, t13, t14, t1, t16, t15);
    t18 = (t0 + 1132U);
    t19 = *((char **)t18);
    t18 = (t19 + 0);
    t20 = (t13 + 12U);
    t21 = *((unsigned int *)t20);
    t22 = (1U * t21);
    memcpy(t18, t17, t22);
    goto LAB2;

LAB4:    xsi_set_current_line(35, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t1 = (t0 + 4368U);
    t3 = (t0 + 592U);
    t5 = *((char **)t3);
    t3 = (t0 + 4352U);
    t7 = ieee_p_2592010699_sub_1735675855_503743352(IEEE_P_2592010699, t13, t2, t1, t5, t3);
    t9 = (t0 + 1132U);
    t11 = *((char **)t9);
    t9 = (t11 + 0);
    t14 = (t13 + 12U);
    t21 = *((unsigned int *)t14);
    t22 = (1U * t21);
    memcpy(t9, t7, t22);
    goto LAB2;

LAB5:    xsi_set_current_line(36, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t1 = (t0 + 4352U);
    t3 = (t0 + 684U);
    t5 = *((char **)t3);
    t3 = (t0 + 4368U);
    t7 = ieee_p_3620187407_sub_767668596_3965413181(IEEE_P_3620187407, t13, t2, t1, t5, t3);
    t9 = (t0 + 1132U);
    t11 = *((char **)t9);
    t9 = (t11 + 0);
    t14 = (t13 + 12U);
    t21 = *((unsigned int *)t14);
    t22 = (1U * t21);
    memcpy(t9, t7, t22);
    goto LAB2;

LAB6:    xsi_set_current_line(37, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t1 = (t0 + 4352U);
    t3 = (t0 + 684U);
    t5 = *((char **)t3);
    t3 = (t0 + 4368U);
    t7 = ieee_p_3620187407_sub_767740470_3965413181(IEEE_P_3620187407, t13, t2, t1, t5, t3);
    t9 = (t0 + 1132U);
    t11 = *((char **)t9);
    t9 = (t11 + 0);
    t14 = (t13 + 12U);
    t21 = *((unsigned int *)t14);
    t22 = (1U * t21);
    memcpy(t9, t7, t22);
    goto LAB2;

LAB7:    xsi_set_current_line(39, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t1 = (t0 + 4352U);
    t3 = (t0 + 684U);
    t5 = *((char **)t3);
    t3 = (t0 + 4368U);
    t23 = ieee_p_3620187407_sub_1742983514_3965413181(IEEE_P_3620187407, t2, t1, t5, t3);
    if (t23 != 0)
        goto LAB15;

LAB17:    xsi_set_current_line(42, ng0);
    t1 = ((WORK_P_4132818205) + 1012U);
    t2 = *((char **)t1);
    t1 = (t0 + 1132U);
    t3 = *((char **)t1);
    t1 = (t3 + 0);
    memcpy(t1, t2, 32U);

LAB16:    goto LAB2;

LAB14:;
LAB15:    xsi_set_current_line(40, ng0);
    t7 = ((WORK_P_4132818205) + 1148U);
    t9 = *((char **)t7);
    t7 = (t0 + 1132U);
    t11 = *((char **)t7);
    t7 = (t11 + 0);
    memcpy(t7, t9, 32U);
    goto LAB16;

LAB18:    xsi_set_current_line(49, ng0);
    t7 = (t0 + 2268);
    t9 = (t7 + 32U);
    t11 = *((char **)t9);
    t14 = (t11 + 40U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t7);
    goto LAB19;

}


extern void work_a_2725559894_1566020785_init()
{
	static char *pe[] = {(void *)work_a_2725559894_1566020785_p_0};
	xsi_register_didat("work_a_2725559894_1566020785", "isim/ALU_isim_beh.exe.sim/work/a_2725559894_1566020785.didat");
	xsi_register_executes(pe);
}

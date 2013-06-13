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
static const char *ng0 = "C:/Documents and Settings/Embedded Systems Lab/Desktop/lab3/vhdl/Reg_File_S10.vhd";
extern char *IEEE_P_3620187407;

int ieee_p_3620187407_sub_514432868_3965413181(char *, char *, char *);


static void work_a_3412061098_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    int t6;
    int t7;
    char *t8;
    char *t9;
    unsigned char t10;
    char *t11;
    int t12;
    int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    unsigned char t22;

LAB0:    xsi_set_current_line(29, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 660U);
    t4 = xsi_signal_has_event(t1);
    if (t4 == 1)
        goto LAB14;

LAB15:    t3 = (unsigned char)0;

LAB16:    if (t3 != 0)
        goto LAB12;

LAB13:
LAB3:    t1 = (t0 + 2276);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(30, ng0);
    t1 = (t0 + 5846);
    *((int *)t1) = 0;
    t5 = (t0 + 5850);
    *((int *)t5) = 31;
    t6 = 0;
    t7 = 31;

LAB5:    if (t6 <= t7)
        goto LAB6;

LAB8:    goto LAB3;

LAB6:    xsi_set_current_line(31, ng0);
    t8 = (t0 + 5854);
    t10 = (32U != 32U);
    if (t10 == 1)
        goto LAB9;

LAB10:    t11 = (t0 + 5846);
    t12 = *((int *)t11);
    t13 = (t12 - 0);
    t14 = (t13 * 1);
    t15 = (32U * t14);
    t16 = (0U + t15);
    t17 = (t0 + 2320);
    t18 = (t17 + 32U);
    t19 = *((char **)t18);
    t20 = (t19 + 40U);
    t21 = *((char **)t20);
    memcpy(t21, t8, 32U);
    xsi_driver_first_trans_delta(t17, t16, 32U, 0LL);

LAB7:    t1 = (t0 + 5846);
    t6 = *((int *)t1);
    t2 = (t0 + 5850);
    t7 = *((int *)t2);
    if (t6 == t7)
        goto LAB8;

LAB11:    t12 = (t6 + 1);
    t6 = t12;
    t5 = (t0 + 5846);
    *((int *)t5) = t6;
    goto LAB5;

LAB9:    xsi_size_not_matching(32U, 32U, 0);
    goto LAB10;

LAB12:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 1420U);
    t8 = *((char **)t2);
    t2 = (t0 + 868U);
    t9 = *((char **)t2);
    t2 = (t0 + 4636U);
    t6 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t9, t2);
    t7 = (t6 - 0);
    t14 = (t7 * 1);
    xsi_vhdl_check_range_of_index(0, 31, 1, t6);
    t15 = (32U * t14);
    t16 = (0 + t15);
    t11 = (t8 + t16);
    t17 = (t0 + 2356);
    t18 = (t17 + 32U);
    t19 = *((char **)t18);
    t20 = (t19 + 40U);
    t21 = *((char **)t20);
    memcpy(t21, t11, 32U);
    xsi_driver_first_trans_fast_port(t17);
    xsi_set_current_line(35, ng0);
    t1 = (t0 + 1420U);
    t2 = *((char **)t1);
    t1 = (t0 + 960U);
    t5 = *((char **)t1);
    t1 = (t0 + 4652U);
    t6 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t5, t1);
    t7 = (t6 - 0);
    t14 = (t7 * 1);
    xsi_vhdl_check_range_of_index(0, 31, 1, t6);
    t15 = (32U * t14);
    t16 = (0 + t15);
    t8 = (t2 + t16);
    t9 = (t0 + 2392);
    t11 = (t9 + 32U);
    t17 = *((char **)t11);
    t18 = (t17 + 40U);
    t19 = *((char **)t18);
    memcpy(t19, t8, 32U);
    xsi_driver_first_trans_fast_port(t9);
    xsi_set_current_line(36, ng0);
    t1 = (t0 + 776U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB17;

LAB19:
LAB18:    goto LAB3;

LAB14:    t2 = (t0 + 684U);
    t5 = *((char **)t2);
    t10 = *((unsigned char *)t5);
    t22 = (t10 == (unsigned char)3);
    t3 = t22;
    goto LAB16;

LAB17:    xsi_set_current_line(37, ng0);
    t1 = (t0 + 1144U);
    t5 = *((char **)t1);
    t1 = (t0 + 1052U);
    t8 = *((char **)t1);
    t1 = (t0 + 4668U);
    t6 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t8, t1);
    t7 = (t6 - 0);
    t14 = (t7 * 1);
    t15 = (32U * t14);
    t16 = (0U + t15);
    t9 = (t0 + 2320);
    t11 = (t9 + 32U);
    t17 = *((char **)t11);
    t18 = (t17 + 40U);
    t19 = *((char **)t18);
    memcpy(t19, t5, 32U);
    xsi_driver_first_trans_delta(t9, t16, 32U, 0LL);
    goto LAB18;

}


extern void work_a_3412061098_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3412061098_3212880686_p_0};
	xsi_register_didat("work_a_3412061098_3212880686", "isim/wrapper_isim_beh.exe.sim/work/a_3412061098_3212880686.didat");
	xsi_register_executes(pe);
}

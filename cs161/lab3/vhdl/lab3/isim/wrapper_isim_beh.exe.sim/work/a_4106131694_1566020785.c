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
static const char *ng0 = "C:/Documents and Settings/Embedded Systems Lab/Desktop/lab3/vhdl/ALU_Control_S10.vhd";



static void work_a_4106131694_1566020785_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned int t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    int t14;
    int t15;
    int t16;
    int t18;
    char *t19;
    int t21;
    char *t22;
    char *t24;
    char *t25;

LAB0:    xsi_set_current_line(21, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t1 = (t0 + 3315);
    t4 = 1;
    if (2U == 2U)
        goto LAB5;

LAB6:    t4 = 0;

LAB7:    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t1 = (t0 + 3320);
    t4 = 1;
    if (2U == 2U)
        goto LAB13;

LAB14:    t4 = 0;

LAB15:    if (t4 != 0)
        goto LAB11;

LAB12:    xsi_set_current_line(27, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t5 = (5 - 3);
    t12 = (t5 * 1U);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = (t0 + 3325);
    t14 = xsi_mem_cmp(t3, t1, 4U);
    if (t14 == 1)
        goto LAB20;

LAB26:    t7 = (t0 + 3329);
    t15 = xsi_mem_cmp(t7, t1, 4U);
    if (t15 == 1)
        goto LAB21;

LAB27:    t9 = (t0 + 3333);
    t16 = xsi_mem_cmp(t9, t1, 4U);
    if (t16 == 1)
        goto LAB22;

LAB28:    t11 = (t0 + 3337);
    t18 = xsi_mem_cmp(t11, t1, 4U);
    if (t18 == 1)
        goto LAB23;

LAB29:    t19 = (t0 + 3341);
    t21 = xsi_mem_cmp(t19, t1, 4U);
    if (t21 == 1)
        goto LAB24;

LAB30:
LAB25:    xsi_set_current_line(44, ng0);
    t1 = (t0 + 3360);
    t3 = (t0 + 948U);
    t6 = *((char **)t3);
    t3 = (t6 + 0);
    memcpy(t3, t1, 3U);

LAB19:
LAB3:    xsi_set_current_line(50, ng0);
    t1 = (t0 + 948U);
    t2 = *((char **)t1);
    t1 = (t0 + 1744);
    t3 = (t1 + 32U);
    t6 = *((char **)t3);
    t7 = (t6 + 40U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 3U);
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 1700);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(22, ng0);
    t8 = (t0 + 3317);
    t10 = (t0 + 948U);
    t11 = *((char **)t10);
    t10 = (t11 + 0);
    memcpy(t10, t8, 3U);
    goto LAB3;

LAB5:    t5 = 0;

LAB8:    if (t5 < 2U)
        goto LAB9;
    else
        goto LAB7;

LAB9:    t6 = (t2 + t5);
    t7 = (t1 + t5);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB6;

LAB10:    t5 = (t5 + 1);
    goto LAB8;

LAB11:    xsi_set_current_line(24, ng0);
    t8 = (t0 + 3322);
    t10 = (t0 + 948U);
    t11 = *((char **)t10);
    t10 = (t11 + 0);
    memcpy(t10, t8, 3U);
    goto LAB3;

LAB13:    t5 = 0;

LAB16:    if (t5 < 2U)
        goto LAB17;
    else
        goto LAB15;

LAB17:    t6 = (t2 + t5);
    t7 = (t1 + t5);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB14;

LAB18:    t5 = (t5 + 1);
    goto LAB16;

LAB20:    xsi_set_current_line(29, ng0);
    t22 = (t0 + 3345);
    t24 = (t0 + 948U);
    t25 = *((char **)t24);
    t24 = (t25 + 0);
    memcpy(t24, t22, 3U);
    goto LAB19;

LAB21:    xsi_set_current_line(32, ng0);
    t1 = (t0 + 3348);
    t3 = (t0 + 948U);
    t6 = *((char **)t3);
    t3 = (t6 + 0);
    memcpy(t3, t1, 3U);
    goto LAB19;

LAB22:    xsi_set_current_line(35, ng0);
    t1 = (t0 + 3351);
    t3 = (t0 + 948U);
    t6 = *((char **)t3);
    t3 = (t6 + 0);
    memcpy(t3, t1, 3U);
    goto LAB19;

LAB23:    xsi_set_current_line(38, ng0);
    t1 = (t0 + 3354);
    t3 = (t0 + 948U);
    t6 = *((char **)t3);
    t3 = (t6 + 0);
    memcpy(t3, t1, 3U);
    goto LAB19;

LAB24:    xsi_set_current_line(41, ng0);
    t1 = (t0 + 3357);
    t3 = (t0 + 948U);
    t6 = *((char **)t3);
    t3 = (t6 + 0);
    memcpy(t3, t1, 3U);
    goto LAB19;

LAB31:;
}


extern void work_a_4106131694_1566020785_init()
{
	static char *pe[] = {(void *)work_a_4106131694_1566020785_p_0};
	xsi_register_didat("work_a_4106131694_1566020785", "isim/wrapper_isim_beh.exe.sim/work/a_4106131694_1566020785.didat");
	xsi_register_executes(pe);
}

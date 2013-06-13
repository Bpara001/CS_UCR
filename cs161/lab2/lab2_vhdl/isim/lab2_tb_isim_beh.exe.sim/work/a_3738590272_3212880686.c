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
static const char *ng0 = "C:/Documents and Settings/Embedded Systems Lab/Desktop/lab2_vhdl/lab2_vhdl.vhd";
extern char *IEEE_P_3620187407;
extern char *IEEE_P_2592010699;

char *ieee_p_2592010699_sub_1837678034_503743352(char *, char *, char *, char *);
char *ieee_p_3620187407_sub_436279890_3965413181(char *, char *, char *, char *, int );
int ieee_p_3620187407_sub_514432868_3965413181(char *, char *, char *);
char *ieee_p_3620187407_sub_767740470_3965413181(char *, char *, char *, char *, char *, char *);


static void work_a_3738590272_3212880686_p_0(char *t0)
{
    char t14[16];
    char t15[16];
    char t23[16];
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    int t24;
    char *t25;

LAB0:    xsi_set_current_line(43, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t3 = (31 - 31);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t7 == (unsigned char)3);
    if (t8 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(46, ng0);
    t1 = (t0 + 3156);
    t2 = (t1 + 32U);
    t9 = *((char **)t2);
    t10 = (t9 + 40U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB3:    xsi_set_current_line(48, ng0);
    t1 = (t0 + 1684U);
    t2 = *((char **)t1);
    t1 = (t0 + 6172U);
    t9 = (t0 + 592U);
    t10 = *((char **)t9);
    t4 = (31 - 30);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t9 = (t10 + t6);
    t11 = (t15 + 0U);
    t12 = (t11 + 0U);
    *((int *)t12) = 30;
    t12 = (t11 + 4U);
    *((int *)t12) = 23;
    t12 = (t11 + 8U);
    *((int *)t12) = -1;
    t3 = (23 - 30);
    t16 = (t3 * -1);
    t16 = (t16 + 1);
    t12 = (t11 + 12U);
    *((unsigned int *)t12) = t16;
    t12 = ieee_p_3620187407_sub_767740470_3965413181(IEEE_P_3620187407, t14, t2, t1, t9, t15);
    t13 = (t14 + 12U);
    t16 = *((unsigned int *)t13);
    t17 = (1U * t16);
    t7 = (8U != t17);
    if (t7 == 1)
        goto LAB5;

LAB6:    t18 = (t0 + 3192);
    t19 = (t18 + 32U);
    t20 = *((char **)t19);
    t21 = (t20 + 40U);
    t22 = *((char **)t21);
    memcpy(t22, t12, 8U);
    xsi_driver_first_trans_fast(t18);
    xsi_set_current_line(49, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t4 = (31 - 30);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t9 = (t15 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 30;
    t10 = (t9 + 4U);
    *((int *)t10) = 23;
    t10 = (t9 + 8U);
    *((int *)t10) = -1;
    t3 = (23 - 30);
    t16 = (t3 * -1);
    t16 = (t16 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t16;
    t10 = (t0 + 1684U);
    t11 = *((char **)t10);
    t10 = (t0 + 6172U);
    t12 = ieee_p_3620187407_sub_767740470_3965413181(IEEE_P_3620187407, t14, t1, t15, t11, t10);
    t13 = (t14 + 12U);
    t16 = *((unsigned int *)t13);
    t17 = (1U * t16);
    t7 = (8U != t17);
    if (t7 == 1)
        goto LAB7;

LAB8:    t18 = (t0 + 3228);
    t19 = (t18 + 32U);
    t20 = *((char **)t19);
    t21 = (t20 + 40U);
    t22 = *((char **)t21);
    memcpy(t22, t12, 8U);
    xsi_driver_first_trans_fast(t18);
    xsi_set_current_line(50, ng0);
    t1 = (t0 + 6436);
    t9 = (t0 + 592U);
    t10 = *((char **)t9);
    t4 = (31 - 22);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t9 = (t10 + t6);
    t12 = ((IEEE_P_2592010699) + 2332);
    t13 = (t15 + 0U);
    t18 = (t13 + 0U);
    *((int *)t18) = 0;
    t18 = (t13 + 4U);
    *((int *)t18) = 0;
    t18 = (t13 + 8U);
    *((int *)t18) = 1;
    t3 = (0 - 0);
    t16 = (t3 * 1);
    t16 = (t16 + 1);
    t18 = (t13 + 12U);
    *((unsigned int *)t18) = t16;
    t18 = (t23 + 0U);
    t19 = (t18 + 0U);
    *((int *)t19) = 22;
    t19 = (t18 + 4U);
    *((int *)t19) = 0;
    t19 = (t18 + 8U);
    *((int *)t19) = -1;
    t24 = (0 - 22);
    t16 = (t24 * -1);
    t16 = (t16 + 1);
    t19 = (t18 + 12U);
    *((unsigned int *)t19) = t16;
    t11 = xsi_base_array_concat(t11, t14, t12, (char)97, t1, t15, (char)97, t9, t23, (char)101);
    t16 = (1U + 23U);
    t7 = (24U != t16);
    if (t7 == 1)
        goto LAB9;

LAB10:    t19 = (t0 + 3264);
    t20 = (t19 + 32U);
    t21 = *((char **)t20);
    t22 = (t21 + 40U);
    t25 = *((char **)t22);
    memcpy(t25, t11, 24U);
    xsi_driver_first_trans_fast(t19);
    t1 = (t0 + 3080);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(44, ng0);
    t9 = (t0 + 3156);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    t12 = (t11 + 40U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)3;
    xsi_driver_first_trans_fast(t9);
    goto LAB3;

LAB5:    xsi_size_not_matching(8U, t17, 0);
    goto LAB6;

LAB7:    xsi_size_not_matching(8U, t17, 0);
    goto LAB8;

LAB9:    xsi_size_not_matching(24U, t16, 0);
    goto LAB10;

}

static void work_a_3738590272_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(57, ng0);
    t1 = (t0 + 960U);
    t2 = *((char **)t1);
    t3 = (7 - 7);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t7 == (unsigned char)3);
    if (t8 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(61, ng0);
    t1 = (t0 + 3300);
    t2 = (t1 + 32U);
    t9 = *((char **)t2);
    t10 = (t9 + 40U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(62, ng0);
    t1 = (t0 + 960U);
    t2 = *((char **)t1);
    t1 = (t0 + 6124U);
    t3 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t2, t1);
    t9 = (t0 + 3336);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    t12 = (t11 + 40U);
    t13 = *((char **)t12);
    *((int *)t13) = t3;
    xsi_driver_first_trans_fast(t9);

LAB3:    t1 = (t0 + 3088);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(58, ng0);
    t9 = (t0 + 3300);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    t12 = (t11 + 40U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)3;
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(59, ng0);
    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t1 = (t0 + 6140U);
    t3 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t2, t1);
    t9 = (t0 + 3336);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    t12 = (t11 + 40U);
    t13 = *((char **)t12);
    *((int *)t13) = t3;
    xsi_driver_first_trans_fast(t9);
    goto LAB3;

}

static void work_a_3738590272_3212880686_p_2(char *t0)
{
    char t22[16];
    char t24[16];
    char t29[16];
    char t41[16];
    char t43[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int t7;
    unsigned char t8;
    char *t9;
    unsigned char t10;
    unsigned char t11;
    unsigned char t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    int t16;
    int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t23;
    char *t25;
    char *t26;
    int t27;
    unsigned int t28;
    char *t30;
    int t31;
    int t32;
    char *t33;
    int t34;
    char *t35;
    char *t36;
    int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t42;
    char *t44;
    char *t45;
    int t46;
    char *t47;
    int t48;
    unsigned int t49;
    char *t50;
    int t51;
    int t52;
    int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    int t57;
    int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned char t62;
    char *t63;
    char *t64;
    char *t65;
    char *t66;
    int t67;
    int t68;

LAB0:    xsi_set_current_line(70, ng0);
    t1 = (t0 + 1752U);
    t2 = *((char **)t1);
    t1 = (t0 + 3372);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 40U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 32U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(71, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t7 = *((int *)t2);
    t8 = (t7 > 23);
    if (t8 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t7 = *((int *)t2);
    t10 = (t7 <= 23);
    if (t10 == 1)
        goto LAB7;

LAB8:    t8 = (unsigned char)0;

LAB9:    if (t8 != 0)
        goto LAB5;

LAB6:    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t7 = *((int *)t2);
    t10 = (t7 >= 6);
    if (t10 == 1)
        goto LAB14;

LAB15:    t8 = (unsigned char)0;

LAB16:    if (t8 != 0)
        goto LAB12;

LAB13:    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t7 = *((int *)t2);
    t10 = (t7 < 6);
    if (t10 == 1)
        goto LAB21;

LAB22:    t8 = (unsigned char)0;

LAB23:    if (t8 != 0)
        goto LAB19;

LAB20:
LAB3:    t1 = (t0 + 3096);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(72, ng0);
    t1 = (t0 + 1752U);
    t3 = *((char **)t1);
    t1 = (t0 + 3372);
    t4 = (t1 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t9 = *((char **)t6);
    memcpy(t9, t3, 32U);
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(74, ng0);
    t1 = (t0 + 1752U);
    t4 = *((char **)t1);
    t13 = (31 - 7);
    t14 = (t13 * 1U);
    t15 = (0 + t14);
    t1 = (t4 + t15);
    t5 = (t0 + 1752U);
    t6 = *((char **)t5);
    t5 = (t0 + 1512U);
    t9 = *((char **)t5);
    t16 = *((int *)t9);
    t17 = (t16 - 1);
    t18 = (31 - t17);
    xsi_vhdl_check_range_of_slice(31, 0, -1, t17, 0, -1);
    t19 = (t18 * 1U);
    t20 = (0 + t19);
    t5 = (t6 + t20);
    t23 = ((IEEE_P_2592010699) + 2332);
    t25 = (t24 + 0U);
    t26 = (t25 + 0U);
    *((int *)t26) = 7;
    t26 = (t25 + 4U);
    *((int *)t26) = 0;
    t26 = (t25 + 8U);
    *((int *)t26) = -1;
    t27 = (0 - 7);
    t28 = (t27 * -1);
    t28 = (t28 + 1);
    t26 = (t25 + 12U);
    *((unsigned int *)t26) = t28;
    t26 = (t0 + 1512U);
    t30 = *((char **)t26);
    t31 = *((int *)t30);
    t32 = (t31 - 1);
    t26 = (t29 + 0U);
    t33 = (t26 + 0U);
    *((int *)t33) = t32;
    t33 = (t26 + 4U);
    *((int *)t33) = 0;
    t33 = (t26 + 8U);
    *((int *)t33) = -1;
    t34 = (0 - t32);
    t28 = (t34 * -1);
    t28 = (t28 + 1);
    t33 = (t26 + 12U);
    *((unsigned int *)t33) = t28;
    t21 = xsi_base_array_concat(t21, t22, t23, (char)97, t1, t24, (char)97, t5, t29, (char)101);
    t33 = (t0 + 1144U);
    t35 = *((char **)t33);
    t28 = (23 - 23);
    t33 = (t0 + 1512U);
    t36 = *((char **)t33);
    t37 = *((int *)t36);
    xsi_vhdl_check_range_of_slice(23, 0, -1, 23, t37, -1);
    t38 = (t28 * 1U);
    t39 = (0 + t38);
    t33 = (t35 + t39);
    t42 = ((IEEE_P_2592010699) + 2332);
    t44 = (t0 + 1512U);
    t45 = *((char **)t44);
    t46 = *((int *)t45);
    t44 = (t43 + 0U);
    t47 = (t44 + 0U);
    *((int *)t47) = 23;
    t47 = (t44 + 4U);
    *((int *)t47) = t46;
    t47 = (t44 + 8U);
    *((int *)t47) = -1;
    t48 = (t46 - 23);
    t49 = (t48 * -1);
    t49 = (t49 + 1);
    t47 = (t44 + 12U);
    *((unsigned int *)t47) = t49;
    t40 = xsi_base_array_concat(t40, t41, t42, (char)97, t21, t22, (char)97, t33, t43, (char)101);
    t47 = (t0 + 1512U);
    t50 = *((char **)t47);
    t51 = *((int *)t50);
    t52 = (t51 - 1);
    t53 = (0 - t52);
    t49 = (t53 * -1);
    t49 = (t49 + 1);
    t54 = (1U * t49);
    t55 = (8U + t54);
    t47 = (t0 + 1512U);
    t56 = *((char **)t47);
    t57 = *((int *)t56);
    t58 = (t57 - 23);
    t59 = (t58 * -1);
    t59 = (t59 + 1);
    t60 = (1U * t59);
    t61 = (t55 + t60);
    t62 = (32U != t61);
    if (t62 == 1)
        goto LAB10;

LAB11:    t47 = (t0 + 3372);
    t63 = (t47 + 32U);
    t64 = *((char **)t63);
    t65 = (t64 + 40U);
    t66 = *((char **)t65);
    memcpy(t66, t40, 32U);
    xsi_driver_first_trans_fast(t47);
    goto LAB3;

LAB7:    t1 = (t0 + 1236U);
    t3 = *((char **)t1);
    t11 = *((unsigned char *)t3);
    t12 = (t11 == (unsigned char)2);
    t8 = t12;
    goto LAB9;

LAB10:    xsi_size_not_matching(32U, t61, 0);
    goto LAB11;

LAB12:    xsi_set_current_line(76, ng0);
    t1 = (t0 + 1144U);
    t4 = *((char **)t1);
    t1 = (t0 + 1512U);
    t5 = *((char **)t1);
    t16 = *((int *)t5);
    t17 = (30 - t16);
    t13 = (23 - t17);
    xsi_vhdl_check_range_of_slice(23, 0, -1, t17, 0, -1);
    t14 = (t13 * 1U);
    t15 = (0 + t14);
    t1 = (t4 + t15);
    t9 = ((IEEE_P_2592010699) + 2332);
    t21 = (t0 + 1512U);
    t23 = *((char **)t21);
    t27 = *((int *)t23);
    t31 = (30 - t27);
    t21 = (t24 + 0U);
    t25 = (t21 + 0U);
    *((int *)t25) = t31;
    t25 = (t21 + 4U);
    *((int *)t25) = 0;
    t25 = (t21 + 8U);
    *((int *)t25) = -1;
    t32 = (0 - t31);
    t18 = (t32 * -1);
    t18 = (t18 + 1);
    t25 = (t21 + 12U);
    *((unsigned int *)t25) = t18;
    t6 = xsi_base_array_concat(t6, t22, t9, (char)99, (unsigned char)2, (char)97, t1, t24, (char)101);
    t25 = (t0 + 1752U);
    t26 = *((char **)t25);
    t25 = (t0 + 1512U);
    t30 = *((char **)t25);
    t34 = *((int *)t30);
    t37 = (t34 - 1);
    t18 = (31 - t37);
    xsi_vhdl_check_range_of_slice(31, 0, -1, t37, 0, -1);
    t19 = (t18 * 1U);
    t20 = (0 + t19);
    t25 = (t26 + t20);
    t35 = ((IEEE_P_2592010699) + 2332);
    t36 = (t0 + 1512U);
    t40 = *((char **)t36);
    t46 = *((int *)t40);
    t48 = (t46 - 1);
    t36 = (t41 + 0U);
    t42 = (t36 + 0U);
    *((int *)t42) = t48;
    t42 = (t36 + 4U);
    *((int *)t42) = 0;
    t42 = (t36 + 8U);
    *((int *)t42) = -1;
    t51 = (0 - t48);
    t28 = (t51 * -1);
    t28 = (t28 + 1);
    t42 = (t36 + 12U);
    *((unsigned int *)t42) = t28;
    t33 = xsi_base_array_concat(t33, t29, t35, (char)97, t6, t22, (char)97, t25, t41, (char)101);
    t42 = (t0 + 1512U);
    t44 = *((char **)t42);
    t52 = *((int *)t44);
    t53 = (30 - t52);
    t57 = (0 - t53);
    t28 = (t57 * -1);
    t28 = (t28 + 1);
    t38 = (1U * t28);
    t39 = (1U + t38);
    t42 = (t0 + 1512U);
    t45 = *((char **)t42);
    t58 = *((int *)t45);
    t67 = (t58 - 1);
    t68 = (0 - t67);
    t49 = (t68 * -1);
    t49 = (t49 + 1);
    t54 = (1U * t49);
    t55 = (t39 + t54);
    t62 = (32U != t55);
    if (t62 == 1)
        goto LAB17;

LAB18:    t42 = (t0 + 3372);
    t47 = (t42 + 32U);
    t50 = *((char **)t47);
    t56 = (t50 + 40U);
    t63 = *((char **)t56);
    memcpy(t63, t33, 32U);
    xsi_driver_first_trans_fast(t42);
    goto LAB3;

LAB14:    t1 = (t0 + 1236U);
    t3 = *((char **)t1);
    t11 = *((unsigned char *)t3);
    t12 = (t11 == (unsigned char)3);
    t8 = t12;
    goto LAB16;

LAB17:    xsi_size_not_matching(32U, t55, 0);
    goto LAB18;

LAB19:    xsi_set_current_line(78, ng0);
    t1 = (t0 + 1752U);
    t4 = *((char **)t1);
    t13 = (31 - 7);
    t1 = (t0 + 1512U);
    t5 = *((char **)t1);
    t16 = *((int *)t5);
    xsi_vhdl_check_range_of_slice(31, 0, -1, 7, t16, -1);
    t14 = (t13 * 1U);
    t15 = (0 + t14);
    t1 = (t4 + t15);
    t6 = (t0 + 1144U);
    t9 = *((char **)t6);
    t18 = (23 - 23);
    t19 = (t18 * 1U);
    t20 = (0 + t19);
    t6 = (t9 + t20);
    t23 = ((IEEE_P_2592010699) + 2332);
    t25 = (t0 + 1512U);
    t26 = *((char **)t25);
    t17 = *((int *)t26);
    t25 = (t24 + 0U);
    t30 = (t25 + 0U);
    *((int *)t30) = 7;
    t30 = (t25 + 4U);
    *((int *)t30) = t17;
    t30 = (t25 + 8U);
    *((int *)t30) = -1;
    t27 = (t17 - 7);
    t28 = (t27 * -1);
    t28 = (t28 + 1);
    t30 = (t25 + 12U);
    *((unsigned int *)t30) = t28;
    t30 = (t29 + 0U);
    t33 = (t30 + 0U);
    *((int *)t33) = 23;
    t33 = (t30 + 4U);
    *((int *)t33) = 0;
    t33 = (t30 + 8U);
    *((int *)t33) = -1;
    t31 = (0 - 23);
    t28 = (t31 * -1);
    t28 = (t28 + 1);
    t33 = (t30 + 12U);
    *((unsigned int *)t33) = t28;
    t21 = xsi_base_array_concat(t21, t22, t23, (char)97, t1, t24, (char)97, t6, t29, (char)101);
    t33 = (t0 + 1752U);
    t35 = *((char **)t33);
    t33 = (t0 + 1512U);
    t36 = *((char **)t33);
    t32 = *((int *)t36);
    t28 = (31 - t32);
    xsi_vhdl_check_range_of_slice(31, 0, -1, t32, 1, -1);
    t38 = (t28 * 1U);
    t39 = (0 + t38);
    t33 = (t35 + t39);
    t42 = ((IEEE_P_2592010699) + 2332);
    t44 = (t0 + 1512U);
    t45 = *((char **)t44);
    t34 = *((int *)t45);
    t44 = (t43 + 0U);
    t47 = (t44 + 0U);
    *((int *)t47) = t34;
    t47 = (t44 + 4U);
    *((int *)t47) = 1;
    t47 = (t44 + 8U);
    *((int *)t47) = -1;
    t37 = (1 - t34);
    t49 = (t37 * -1);
    t49 = (t49 + 1);
    t47 = (t44 + 12U);
    *((unsigned int *)t47) = t49;
    t40 = xsi_base_array_concat(t40, t41, t42, (char)97, t21, t22, (char)97, t33, t43, (char)101);
    t47 = (t0 + 1512U);
    t50 = *((char **)t47);
    t46 = *((int *)t50);
    t48 = (t46 - 7);
    t49 = (t48 * -1);
    t49 = (t49 + 1);
    t54 = (1U * t49);
    t55 = (t54 + 24U);
    t47 = (t0 + 1512U);
    t56 = *((char **)t47);
    t51 = *((int *)t56);
    t52 = (1 - t51);
    t59 = (t52 * -1);
    t59 = (t59 + 1);
    t60 = (1U * t59);
    t61 = (t55 + t60);
    t62 = (32U != t61);
    if (t62 == 1)
        goto LAB24;

LAB25:    t47 = (t0 + 3372);
    t63 = (t47 + 32U);
    t64 = *((char **)t63);
    t65 = (t64 + 40U);
    t66 = *((char **)t65);
    memcpy(t66, t40, 32U);
    xsi_driver_first_trans_fast(t47);
    goto LAB3;

LAB21:    t1 = (t0 + 1236U);
    t3 = *((char **)t1);
    t11 = *((unsigned char *)t3);
    t12 = (t11 == (unsigned char)3);
    t8 = t12;
    goto LAB23;

LAB24:    xsi_size_not_matching(32U, t61, 0);
    goto LAB25;

}

static void work_a_3738590272_3212880686_p_3(char *t0)
{
    char t5[16];
    char t6[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned char t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;

LAB0:    xsi_set_current_line(87, ng0);
    t1 = (t0 + 776U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(90, ng0);
    t1 = (t0 + 1328U);
    t2 = *((char **)t1);
    t1 = (t0 + 3408);
    t7 = (t1 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 40U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 32U);
    xsi_driver_first_trans_fast(t1);

LAB3:    t1 = (t0 + 3104);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(88, ng0);
    t1 = (t0 + 1328U);
    t7 = *((char **)t1);
    t1 = (t0 + 6188U);
    t8 = ieee_p_2592010699_sub_1837678034_503743352(IEEE_P_2592010699, t6, t7, t1);
    t9 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t5, t8, t6, 1);
    t10 = (t5 + 12U);
    t11 = *((unsigned int *)t10);
    t12 = (1U * t11);
    t13 = (32U != t12);
    if (t13 == 1)
        goto LAB5;

LAB6:    t14 = (t0 + 3408);
    t15 = (t14 + 32U);
    t16 = *((char **)t15);
    t17 = (t16 + 40U);
    t18 = *((char **)t17);
    memcpy(t18, t9, 32U);
    xsi_driver_first_trans_fast(t14);
    goto LAB3;

LAB5:    xsi_size_not_matching(32U, t12, 0);
    goto LAB6;

}

static void work_a_3738590272_3212880686_p_4(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(95, ng0);

LAB3:    t1 = (t0 + 1420U);
    t2 = *((char **)t1);
    t1 = (t0 + 3444);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 40U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 3112);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_3738590272_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3738590272_3212880686_p_0,(void *)work_a_3738590272_3212880686_p_1,(void *)work_a_3738590272_3212880686_p_2,(void *)work_a_3738590272_3212880686_p_3,(void *)work_a_3738590272_3212880686_p_4};
	xsi_register_didat("work_a_3738590272_3212880686", "isim/lab2_tb_isim_beh.exe.sim/work/a_3738590272_3212880686.didat");
	xsi_register_executes(pe);
}

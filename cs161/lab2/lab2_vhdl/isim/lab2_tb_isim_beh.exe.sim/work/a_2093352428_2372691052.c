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
static const char *ng0 = "C:/Documents and Settings/Embedded Systems Lab/Desktop/lab2_vhdl/lab2_tb.vhd";



static void work_a_2093352428_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    int64 t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned char t10;
    unsigned int t11;

LAB0:    t1 = (t0 + 1344U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(49, ng0);
    t3 = (20 * 1000LL);
    t2 = (t0 + 1244);
    xsi_process_wait(t2, t3);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 3184);
    xsi_report(t2, 11U, 0);
    xsi_set_current_line(55, ng0);
    t2 = (t0 + 3195);
    t5 = (t0 + 1576);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(56, ng0);
    t3 = (20 * 1000LL);
    t2 = (t0 + 1244);
    xsi_process_wait(t2, t3);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 684U);
    t4 = *((char **)t2);
    t2 = (t0 + 3227);
    t10 = 1;
    if (32U == 32U)
        goto LAB14;

LAB15:    t10 = 0;

LAB16:    if (t10 == 0)
        goto LAB12;

LAB13:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 3272);
    xsi_report(t2, 11U, 0);
    xsi_set_current_line(64, ng0);
    t2 = (t0 + 3283);
    t5 = (t0 + 1576);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(65, ng0);
    t3 = (20 * 1000LL);
    t2 = (t0 + 1244);
    xsi_process_wait(t2, t3);

LAB22:    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB12:    t8 = (t0 + 3259);
    xsi_report(t8, 13U, (unsigned char)1);
    goto LAB13;

LAB14:    t11 = 0;

LAB17:    if (t11 < 32U)
        goto LAB18;
    else
        goto LAB16;

LAB18:    t6 = (t4 + t11);
    t7 = (t2 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB15;

LAB19:    t11 = (t11 + 1);
    goto LAB17;

LAB20:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 684U);
    t4 = *((char **)t2);
    t2 = (t0 + 3315);
    t10 = 1;
    if (32U == 32U)
        goto LAB26;

LAB27:    t10 = 0;

LAB28:    if (t10 == 0)
        goto LAB24;

LAB25:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 3360);
    xsi_report(t2, 11U, 0);
    xsi_set_current_line(73, ng0);
    t2 = (t0 + 3371);
    t5 = (t0 + 1576);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(74, ng0);
    t3 = (20 * 1000LL);
    t2 = (t0 + 1244);
    xsi_process_wait(t2, t3);

LAB34:    *((char **)t1) = &&LAB35;
    goto LAB1;

LAB21:    goto LAB20;

LAB23:    goto LAB21;

LAB24:    t8 = (t0 + 3347);
    xsi_report(t8, 13U, (unsigned char)1);
    goto LAB25;

LAB26:    t11 = 0;

LAB29:    if (t11 < 32U)
        goto LAB30;
    else
        goto LAB28;

LAB30:    t6 = (t4 + t11);
    t7 = (t2 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB27;

LAB31:    t11 = (t11 + 1);
    goto LAB29;

LAB32:    xsi_set_current_line(75, ng0);
    t2 = (t0 + 684U);
    t4 = *((char **)t2);
    t2 = (t0 + 3403);
    t10 = 1;
    if (32U == 32U)
        goto LAB38;

LAB39:    t10 = 0;

LAB40:    if (t10 == 0)
        goto LAB36;

LAB37:    xsi_set_current_line(81, ng0);
    t2 = (t0 + 3448);
    xsi_report(t2, 11U, 0);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 3459);
    t5 = (t0 + 1576);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(83, ng0);
    t3 = (20 * 1000LL);
    t2 = (t0 + 1244);
    xsi_process_wait(t2, t3);

LAB46:    *((char **)t1) = &&LAB47;
    goto LAB1;

LAB33:    goto LAB32;

LAB35:    goto LAB33;

LAB36:    t8 = (t0 + 3435);
    xsi_report(t8, 13U, (unsigned char)1);
    goto LAB37;

LAB38:    t11 = 0;

LAB41:    if (t11 < 32U)
        goto LAB42;
    else
        goto LAB40;

LAB42:    t6 = (t4 + t11);
    t7 = (t2 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB39;

LAB43:    t11 = (t11 + 1);
    goto LAB41;

LAB44:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 684U);
    t4 = *((char **)t2);
    t2 = (t0 + 3491);
    t10 = 1;
    if (32U == 32U)
        goto LAB50;

LAB51:    t10 = 0;

LAB52:    if (t10 == 0)
        goto LAB48;

LAB49:    xsi_set_current_line(90, ng0);
    t2 = (t0 + 3536);
    xsi_report(t2, 11U, 0);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 3547);
    t5 = (t0 + 1576);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(92, ng0);
    t3 = (20 * 1000LL);
    t2 = (t0 + 1244);
    xsi_process_wait(t2, t3);

LAB58:    *((char **)t1) = &&LAB59;
    goto LAB1;

LAB45:    goto LAB44;

LAB47:    goto LAB45;

LAB48:    t8 = (t0 + 3523);
    xsi_report(t8, 13U, (unsigned char)1);
    goto LAB49;

LAB50:    t11 = 0;

LAB53:    if (t11 < 32U)
        goto LAB54;
    else
        goto LAB52;

LAB54:    t6 = (t4 + t11);
    t7 = (t2 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB51;

LAB55:    t11 = (t11 + 1);
    goto LAB53;

LAB56:    xsi_set_current_line(93, ng0);
    t2 = (t0 + 684U);
    t4 = *((char **)t2);
    t2 = (t0 + 3579);
    t10 = 1;
    if (32U == 32U)
        goto LAB62;

LAB63:    t10 = 0;

LAB64:    if (t10 == 0)
        goto LAB60;

LAB61:    xsi_set_current_line(99, ng0);
    t2 = (t0 + 3624);
    xsi_report(t2, 11U, 0);
    xsi_set_current_line(100, ng0);
    t2 = (t0 + 3635);
    t5 = (t0 + 1576);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(101, ng0);
    t3 = (20 * 1000LL);
    t2 = (t0 + 1244);
    xsi_process_wait(t2, t3);

LAB70:    *((char **)t1) = &&LAB71;
    goto LAB1;

LAB57:    goto LAB56;

LAB59:    goto LAB57;

LAB60:    t8 = (t0 + 3611);
    xsi_report(t8, 13U, (unsigned char)1);
    goto LAB61;

LAB62:    t11 = 0;

LAB65:    if (t11 < 32U)
        goto LAB66;
    else
        goto LAB64;

LAB66:    t6 = (t4 + t11);
    t7 = (t2 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB63;

LAB67:    t11 = (t11 + 1);
    goto LAB65;

LAB68:    xsi_set_current_line(102, ng0);
    t2 = (t0 + 684U);
    t4 = *((char **)t2);
    t2 = (t0 + 3667);
    t10 = 1;
    if (32U == 32U)
        goto LAB74;

LAB75:    t10 = 0;

LAB76:    if (t10 == 0)
        goto LAB72;

LAB73:    xsi_set_current_line(109, ng0);
    t2 = (t0 + 3712);
    xsi_report(t2, 11U, 0);
    xsi_set_current_line(110, ng0);
    t2 = (t0 + 3723);
    t5 = (t0 + 1576);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(111, ng0);
    t3 = (20 * 1000LL);
    t2 = (t0 + 1244);
    xsi_process_wait(t2, t3);

LAB82:    *((char **)t1) = &&LAB83;
    goto LAB1;

LAB69:    goto LAB68;

LAB71:    goto LAB69;

LAB72:    t8 = (t0 + 3699);
    xsi_report(t8, 13U, (unsigned char)1);
    goto LAB73;

LAB74:    t11 = 0;

LAB77:    if (t11 < 32U)
        goto LAB78;
    else
        goto LAB76;

LAB78:    t6 = (t4 + t11);
    t7 = (t2 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB75;

LAB79:    t11 = (t11 + 1);
    goto LAB77;

LAB80:    xsi_set_current_line(112, ng0);
    t2 = (t0 + 684U);
    t4 = *((char **)t2);
    t2 = (t0 + 3755);
    t10 = 1;
    if (32U == 32U)
        goto LAB86;

LAB87:    t10 = 0;

LAB88:    if (t10 == 0)
        goto LAB84;

LAB85:    xsi_set_current_line(115, ng0);

LAB94:    *((char **)t1) = &&LAB95;
    goto LAB1;

LAB81:    goto LAB80;

LAB83:    goto LAB81;

LAB84:    t8 = (t0 + 3787);
    xsi_report(t8, 13U, (unsigned char)1);
    goto LAB85;

LAB86:    t11 = 0;

LAB89:    if (t11 < 32U)
        goto LAB90;
    else
        goto LAB88;

LAB90:    t6 = (t4 + t11);
    t7 = (t2 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB87;

LAB91:    t11 = (t11 + 1);
    goto LAB89;

LAB92:    goto LAB2;

LAB93:    goto LAB92;

LAB95:    goto LAB93;

}


extern void work_a_2093352428_2372691052_init()
{
	static char *pe[] = {(void *)work_a_2093352428_2372691052_p_0};
	xsi_register_didat("work_a_2093352428_2372691052", "isim/lab2_tb_isim_beh.exe.sim/work/a_2093352428_2372691052.didat");
	xsi_register_executes(pe);
}

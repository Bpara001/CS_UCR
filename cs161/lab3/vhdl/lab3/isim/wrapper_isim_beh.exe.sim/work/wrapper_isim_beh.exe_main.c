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

#include "xsi.h"

struct XSI_INFO xsi_info;

char *IEEE_P_2592010699;
char *STD_STANDARD;
char *STD_TEXTIO;
char *IEEE_P_3499444699;
char *IEEE_P_3620187407;
char *WORK_P_4132818205;
char *IEEE_P_3564397177;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    ieee_p_2592010699_init();
    ieee_p_3499444699_init();
    work_p_4132818205_init();
    ieee_p_3620187407_init();
    work_a_2940900732_3212880686_init();
    work_a_3564314642_3212880686_init();
    std_textio_init();
    ieee_p_3564397177_init();
    xilinxcorelib_a_3067440863_2959432447_init();
    xilinxcorelib_a_0558168456_1709443946_init();
    xilinxcorelib_a_2049272701_0543512595_init();
    xilinxcorelib_a_2018063856_3212880686_init();
    work_a_3230253320_2049108839_init();
    work_a_1258815342_3212880686_init();
    work_a_1019669073_3212880686_init();
    work_a_0368967634_3212880686_init();
    work_a_3412061098_3212880686_init();
    work_a_4042493392_1566020785_init();
    work_a_0832606739_1566020785_init();
    work_a_2399776393_1566020785_init();
    work_a_3222946569_1566020785_init();
    work_a_4106131694_1566020785_init();
    work_a_2543805730_3212880686_init();


    xsi_register_tops("work_a_2543805730_3212880686");

    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    STD_STANDARD = xsi_get_engine_memory("std_standard");
    STD_TEXTIO = xsi_get_engine_memory("std_textio");
    IEEE_P_3499444699 = xsi_get_engine_memory("ieee_p_3499444699");
    IEEE_P_3620187407 = xsi_get_engine_memory("ieee_p_3620187407");
    WORK_P_4132818205 = xsi_get_engine_memory("work_p_4132818205");
    IEEE_P_3564397177 = xsi_get_engine_memory("ieee_p_3564397177");

    return xsi_run_simulation(argc, argv);

}

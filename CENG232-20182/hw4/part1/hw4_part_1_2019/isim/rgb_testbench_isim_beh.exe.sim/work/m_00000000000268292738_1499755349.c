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

/* This file is designed for use with ISim build 0x8ef4fb42 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "TIME=%t | Mode=%b Addres=%b RGBin=%b Op=%b | RGBout=%b";
static const char *ng1 = "C:/Users/erene/OneDrive/Belgeler/Dersler/20182/CENG232/hw4/part1/hw4_part_1_2019/rgb_testbench.v";
static int ng2[] = {0, 0};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {10U, 0U};
static unsigned int ng5[] = {8504130U, 0U};
static unsigned int ng6[] = {0U, 0U};
static unsigned int ng7[] = {8421890U, 0U};
static const char *ng8 = "Test1: Passed";
static int ng9[] = {1, 0};
static const char *ng10 = "Test1 failed.";
static unsigned int ng11[] = {11003878U, 0U};
static const char *ng12 = "Test2: Passed";
static const char *ng13 = "Test2 failed.";
static unsigned int ng14[] = {2U, 0U};
static unsigned int ng15[] = {2581988U, 0U};
static const char *ng16 = "Test3: Passed";
static const char *ng17 = "Test3 failed.";
static unsigned int ng18[] = {3U, 0U};
static unsigned int ng19[] = {16777192U, 0U};
static const char *ng20 = "Test4: Passed";
static const char *ng21 = "Test4 failed.";
static unsigned int ng22[] = {4U, 0U};
static unsigned int ng23[] = {7424U, 0U};
static const char *ng24 = "Test5: Passed";
static const char *ng25 = "Test5 failed.";
static unsigned int ng26[] = {5U, 0U};
static unsigned int ng27[] = {8569923U, 0U};
static const char *ng28 = "Test6: Passed";
static const char *ng29 = "Test6 failed.";
static unsigned int ng30[] = {6U, 0U};
static unsigned int ng31[] = {8438337U, 0U};
static const char *ng32 = "Test7: Passed";
static const char *ng33 = "Test7 failed.";
static unsigned int ng34[] = {7U, 0U};
static unsigned int ng35[] = {231300U, 0U};
static const char *ng36 = "Test8: Passed";
static const char *ng37 = "Test8 failed.";
static unsigned int ng38[] = {14U, 0U};
static unsigned int ng39[] = {6514023U, 0U};
static unsigned int ng40[] = {4407619U, 0U};
static const char *ng41 = "Test9: Passed";
static const char *ng42 = "Test9 failed.";
static unsigned int ng43[] = {15988727U, 0U};
static const char *ng44 = "Test10: Passed";
static const char *ng45 = "Test10 failed.";
static unsigned int ng46[] = {11581108U, 0U};
static const char *ng47 = "Test11: Passed";
static const char *ng48 = "Test11 failed.";
static unsigned int ng49[] = {16777215U, 0U};
static const char *ng50 = "Test12: Passed";
static const char *ng51 = "Test12 failed.";
static const char *ng52 = "Test13: Passed";
static const char *ng53 = "Test13 failed.";
static unsigned int ng54[] = {6579816U, 0U};
static const char *ng55 = "Test14: Passed";
static const char *ng56 = "Test14 failed.";
static unsigned int ng57[] = {6448230U, 0U};
static const char *ng58 = "Test15: Passed";
static const char *ng59 = "Test15 failed.";
static unsigned int ng60[] = {13028046U, 0U};
static const char *ng61 = "Test16: Passed";
static const char *ng62 = "Test16 failed.";
static const char *ng63 = "Test results: %d / 16";

void Monitor_30_3(char *);
void Monitor_30_3(char *);


static void Monitor_30_3_Func(char *t0)
{
    char t1[16];
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    t2 = xsi_vlog_time(t1, 1000.0000000000000, 1000.0000000000000);
    t3 = (t0 + 828);
    t4 = (t3 + 36U);
    t5 = *((char **)t4);
    t6 = (t0 + 920);
    t7 = (t6 + 36U);
    t8 = *((char **)t7);
    t9 = (t0 + 1012);
    t10 = (t9 + 36U);
    t11 = *((char **)t10);
    t12 = (t0 + 1104);
    t13 = (t12 + 36U);
    t14 = *((char **)t13);
    t15 = (t0 + 600U);
    t16 = *((char **)t15);
    xsi_vlogfile_write(1, 0, 3, ng0, 7, t0, (char)118, t1, 64, (char)118, t5, 1, (char)118, t8, 4, (char)118, t11, 24, (char)118, t14, 3, (char)118, t16, 24);

LAB1:    return;
}

static void Initial_26_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(26, ng1);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 1196);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_27_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 1956U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(27, ng1);
    t2 = (t0 + 1856);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(27, ng1);
    t4 = (t0 + 1196);
    t5 = (t4 + 36U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB8;

LAB6:    if (*((unsigned int *)t7) == 0)
        goto LAB5;

LAB7:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB8:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB10;

LAB9:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 1196);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB5:    *((unsigned int *)t3) = 1;
    goto LAB8;

LAB10:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB9;

}

static void Initial_29_2(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;

LAB0:    t1 = (t0 + 2100U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(29, ng1);

LAB4:    xsi_set_current_line(30, ng1);
    Monitor_30_3(t0);
    xsi_set_current_line(33, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(34, ng1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 920);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(35, ng1);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(36, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(38, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1288);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(41, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 4000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(42, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(43, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(45, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng7)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB10;

LAB7:    if (t16 != 0)
        goto LAB9;

LAB8:    *((unsigned int *)t4) = 1;

LAB10:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB11;

LAB12:    xsi_set_current_line(46, ng1);
    xsi_vlogfile_write(1, 0, 0, ng10, 1, t0);

LAB13:    xsi_set_current_line(47, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB9:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB10;

LAB11:    xsi_set_current_line(45, ng1);

LAB14:    xsi_set_current_line(45, ng1);
    xsi_vlogfile_write(1, 0, 0, ng8, 1, t0);
    xsi_set_current_line(45, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB13;

LAB15:    xsi_set_current_line(49, ng1);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(50, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(51, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(52, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB16;
    goto LAB1;

LAB16:    xsi_set_current_line(53, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(54, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB17;
    goto LAB1;

LAB17:    xsi_set_current_line(55, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng11)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB21;

LAB18:    if (t16 != 0)
        goto LAB20;

LAB19:    *((unsigned int *)t4) = 1;

LAB21:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB22;

LAB23:    xsi_set_current_line(56, ng1);
    xsi_vlogfile_write(1, 0, 0, ng13, 1, t0);

LAB24:    xsi_set_current_line(57, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB26;
    goto LAB1;

LAB20:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB21;

LAB22:    xsi_set_current_line(55, ng1);

LAB25:    xsi_set_current_line(55, ng1);
    xsi_vlogfile_write(1, 0, 0, ng12, 1, t0);
    xsi_set_current_line(55, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB24;

LAB26:    xsi_set_current_line(59, ng1);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(60, ng1);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(61, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(62, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB27;
    goto LAB1;

LAB27:    xsi_set_current_line(63, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(64, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB28;
    goto LAB1;

LAB28:    xsi_set_current_line(65, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng15)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB32;

LAB29:    if (t16 != 0)
        goto LAB31;

LAB30:    *((unsigned int *)t4) = 1;

LAB32:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB33;

LAB34:    xsi_set_current_line(66, ng1);
    xsi_vlogfile_write(1, 0, 0, ng17, 1, t0);

LAB35:    xsi_set_current_line(67, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB37;
    goto LAB1;

LAB31:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB32;

LAB33:    xsi_set_current_line(65, ng1);

LAB36:    xsi_set_current_line(65, ng1);
    xsi_vlogfile_write(1, 0, 0, ng16, 1, t0);
    xsi_set_current_line(65, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB35;

LAB37:    xsi_set_current_line(69, ng1);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(70, ng1);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(71, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(72, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB38;
    goto LAB1;

LAB38:    xsi_set_current_line(73, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(74, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB39;
    goto LAB1;

LAB39:    xsi_set_current_line(75, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng19)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB43;

LAB40:    if (t16 != 0)
        goto LAB42;

LAB41:    *((unsigned int *)t4) = 1;

LAB43:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB44;

LAB45:    xsi_set_current_line(76, ng1);
    xsi_vlogfile_write(1, 0, 0, ng21, 1, t0);

LAB46:    xsi_set_current_line(77, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB48;
    goto LAB1;

LAB42:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB43;

LAB44:    xsi_set_current_line(75, ng1);

LAB47:    xsi_set_current_line(75, ng1);
    xsi_vlogfile_write(1, 0, 0, ng20, 1, t0);
    xsi_set_current_line(75, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB46;

LAB48:    xsi_set_current_line(79, ng1);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(80, ng1);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(81, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(82, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB49;
    goto LAB1;

LAB49:    xsi_set_current_line(83, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(84, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB50;
    goto LAB1;

LAB50:    xsi_set_current_line(85, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng23)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB54;

LAB51:    if (t16 != 0)
        goto LAB53;

LAB52:    *((unsigned int *)t4) = 1;

LAB54:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB55;

LAB56:    xsi_set_current_line(86, ng1);
    xsi_vlogfile_write(1, 0, 0, ng25, 1, t0);

LAB57:    xsi_set_current_line(87, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB59;
    goto LAB1;

LAB53:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB54;

LAB55:    xsi_set_current_line(85, ng1);

LAB58:    xsi_set_current_line(85, ng1);
    xsi_vlogfile_write(1, 0, 0, ng24, 1, t0);
    xsi_set_current_line(85, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB57;

LAB59:    xsi_set_current_line(89, ng1);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(90, ng1);
    t2 = ((char*)((ng26)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(91, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(92, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB60;
    goto LAB1;

LAB60:    xsi_set_current_line(93, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(94, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB61;
    goto LAB1;

LAB61:    xsi_set_current_line(95, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng27)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB65;

LAB62:    if (t16 != 0)
        goto LAB64;

LAB63:    *((unsigned int *)t4) = 1;

LAB65:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB66;

LAB67:    xsi_set_current_line(96, ng1);
    xsi_vlogfile_write(1, 0, 0, ng29, 1, t0);

LAB68:    xsi_set_current_line(97, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB70;
    goto LAB1;

LAB64:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB65;

LAB66:    xsi_set_current_line(95, ng1);

LAB69:    xsi_set_current_line(95, ng1);
    xsi_vlogfile_write(1, 0, 0, ng28, 1, t0);
    xsi_set_current_line(95, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB68;

LAB70:    xsi_set_current_line(99, ng1);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(100, ng1);
    t2 = ((char*)((ng30)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(101, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(102, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB71;
    goto LAB1;

LAB71:    xsi_set_current_line(103, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(104, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB72;
    goto LAB1;

LAB72:    xsi_set_current_line(105, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng31)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB76;

LAB73:    if (t16 != 0)
        goto LAB75;

LAB74:    *((unsigned int *)t4) = 1;

LAB76:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB77;

LAB78:    xsi_set_current_line(106, ng1);
    xsi_vlogfile_write(1, 0, 0, ng33, 1, t0);

LAB79:    xsi_set_current_line(107, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB81;
    goto LAB1;

LAB75:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB76;

LAB77:    xsi_set_current_line(105, ng1);

LAB80:    xsi_set_current_line(105, ng1);
    xsi_vlogfile_write(1, 0, 0, ng32, 1, t0);
    xsi_set_current_line(105, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB79;

LAB81:    xsi_set_current_line(109, ng1);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(110, ng1);
    t2 = ((char*)((ng34)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(111, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(112, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB82;
    goto LAB1;

LAB82:    xsi_set_current_line(113, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(114, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB83;
    goto LAB1;

LAB83:    xsi_set_current_line(115, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng35)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB87;

LAB84:    if (t16 != 0)
        goto LAB86;

LAB85:    *((unsigned int *)t4) = 1;

LAB87:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB88;

LAB89:    xsi_set_current_line(116, ng1);
    xsi_vlogfile_write(1, 0, 0, ng37, 1, t0);

LAB90:    xsi_set_current_line(117, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB92;
    goto LAB1;

LAB86:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB87;

LAB88:    xsi_set_current_line(115, ng1);

LAB91:    xsi_set_current_line(115, ng1);
    xsi_vlogfile_write(1, 0, 0, ng36, 1, t0);
    xsi_set_current_line(115, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB90;

LAB92:    xsi_set_current_line(119, ng1);
    t2 = ((char*)((ng38)));
    t3 = (t0 + 920);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(122, ng1);
    t2 = ((char*)((ng39)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(123, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(124, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(125, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB93;
    goto LAB1;

LAB93:    xsi_set_current_line(126, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(127, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB94;
    goto LAB1;

LAB94:    xsi_set_current_line(128, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng40)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB98;

LAB95:    if (t16 != 0)
        goto LAB97;

LAB96:    *((unsigned int *)t4) = 1;

LAB98:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB99;

LAB100:    xsi_set_current_line(129, ng1);
    xsi_vlogfile_write(1, 0, 0, ng42, 1, t0);

LAB101:    xsi_set_current_line(130, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB103;
    goto LAB1;

LAB97:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB98;

LAB99:    xsi_set_current_line(128, ng1);

LAB102:    xsi_set_current_line(128, ng1);
    xsi_vlogfile_write(1, 0, 0, ng41, 1, t0);
    xsi_set_current_line(128, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB101;

LAB103:    xsi_set_current_line(132, ng1);
    t2 = ((char*)((ng39)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(133, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(134, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(135, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB104;
    goto LAB1;

LAB104:    xsi_set_current_line(136, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(137, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB105;
    goto LAB1;

LAB105:    xsi_set_current_line(138, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng43)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB109;

LAB106:    if (t16 != 0)
        goto LAB108;

LAB107:    *((unsigned int *)t4) = 1;

LAB109:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB110;

LAB111:    xsi_set_current_line(139, ng1);
    xsi_vlogfile_write(1, 0, 0, ng45, 1, t0);

LAB112:    xsi_set_current_line(140, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB114;
    goto LAB1;

LAB108:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB109;

LAB110:    xsi_set_current_line(138, ng1);

LAB113:    xsi_set_current_line(138, ng1);
    xsi_vlogfile_write(1, 0, 0, ng44, 1, t0);
    xsi_set_current_line(138, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB112;

LAB114:    xsi_set_current_line(142, ng1);
    t2 = ((char*)((ng39)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(143, ng1);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(144, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(145, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB115;
    goto LAB1;

LAB115:    xsi_set_current_line(146, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(147, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB116;
    goto LAB1;

LAB116:    xsi_set_current_line(148, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng46)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB120;

LAB117:    if (t16 != 0)
        goto LAB119;

LAB118:    *((unsigned int *)t4) = 1;

LAB120:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB121;

LAB122:    xsi_set_current_line(149, ng1);
    xsi_vlogfile_write(1, 0, 0, ng48, 1, t0);

LAB123:    xsi_set_current_line(150, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB125;
    goto LAB1;

LAB119:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB120;

LAB121:    xsi_set_current_line(148, ng1);

LAB124:    xsi_set_current_line(148, ng1);
    xsi_vlogfile_write(1, 0, 0, ng47, 1, t0);
    xsi_set_current_line(148, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB123;

LAB125:    xsi_set_current_line(152, ng1);
    t2 = ((char*)((ng39)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(153, ng1);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(154, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(155, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB126;
    goto LAB1;

LAB126:    xsi_set_current_line(156, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(157, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB127;
    goto LAB1;

LAB127:    xsi_set_current_line(158, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng49)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB131;

LAB128:    if (t16 != 0)
        goto LAB130;

LAB129:    *((unsigned int *)t4) = 1;

LAB131:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB132;

LAB133:    xsi_set_current_line(159, ng1);
    xsi_vlogfile_write(1, 0, 0, ng51, 1, t0);

LAB134:    xsi_set_current_line(160, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB136;
    goto LAB1;

LAB130:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB131;

LAB132:    xsi_set_current_line(158, ng1);

LAB135:    xsi_set_current_line(158, ng1);
    xsi_vlogfile_write(1, 0, 0, ng50, 1, t0);
    xsi_set_current_line(158, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB134;

LAB136:    xsi_set_current_line(162, ng1);
    t2 = ((char*)((ng39)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(163, ng1);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(164, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(165, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB137;
    goto LAB1;

LAB137:    xsi_set_current_line(166, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(167, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB138;
    goto LAB1;

LAB138:    xsi_set_current_line(168, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng6)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB142;

LAB139:    if (t16 != 0)
        goto LAB141;

LAB140:    *((unsigned int *)t4) = 1;

LAB142:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB143;

LAB144:    xsi_set_current_line(169, ng1);
    xsi_vlogfile_write(1, 0, 0, ng53, 1, t0);

LAB145:    xsi_set_current_line(170, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB147;
    goto LAB1;

LAB141:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB142;

LAB143:    xsi_set_current_line(168, ng1);

LAB146:    xsi_set_current_line(168, ng1);
    xsi_vlogfile_write(1, 0, 0, ng52, 1, t0);
    xsi_set_current_line(168, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB145;

LAB147:    xsi_set_current_line(172, ng1);
    t2 = ((char*)((ng39)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(173, ng1);
    t2 = ((char*)((ng26)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(174, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(175, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB148;
    goto LAB1;

LAB148:    xsi_set_current_line(176, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(177, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB149;
    goto LAB1;

LAB149:    xsi_set_current_line(178, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng54)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB153;

LAB150:    if (t16 != 0)
        goto LAB152;

LAB151:    *((unsigned int *)t4) = 1;

LAB153:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB154;

LAB155:    xsi_set_current_line(179, ng1);
    xsi_vlogfile_write(1, 0, 0, ng56, 1, t0);

LAB156:    xsi_set_current_line(180, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB158;
    goto LAB1;

LAB152:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB153;

LAB154:    xsi_set_current_line(178, ng1);

LAB157:    xsi_set_current_line(178, ng1);
    xsi_vlogfile_write(1, 0, 0, ng55, 1, t0);
    xsi_set_current_line(178, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB156;

LAB158:    xsi_set_current_line(182, ng1);
    t2 = ((char*)((ng39)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(183, ng1);
    t2 = ((char*)((ng30)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(184, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(185, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB159;
    goto LAB1;

LAB159:    xsi_set_current_line(186, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(187, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB160;
    goto LAB1;

LAB160:    xsi_set_current_line(188, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng57)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB164;

LAB161:    if (t16 != 0)
        goto LAB163;

LAB162:    *((unsigned int *)t4) = 1;

LAB164:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB165;

LAB166:    xsi_set_current_line(189, ng1);
    xsi_vlogfile_write(1, 0, 0, ng59, 1, t0);

LAB167:    xsi_set_current_line(190, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB169;
    goto LAB1;

LAB163:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB164;

LAB165:    xsi_set_current_line(188, ng1);

LAB168:    xsi_set_current_line(188, ng1);
    xsi_vlogfile_write(1, 0, 0, ng58, 1, t0);
    xsi_set_current_line(188, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB167;

LAB169:    xsi_set_current_line(192, ng1);
    t2 = ((char*)((ng39)));
    t3 = (t0 + 1012);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(193, ng1);
    t2 = ((char*)((ng34)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(194, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(195, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB170;
    goto LAB1;

LAB170:    xsi_set_current_line(196, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(197, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 6000LL);
    *((char **)t1) = &&LAB171;
    goto LAB1;

LAB171:    xsi_set_current_line(198, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng60)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB175;

LAB172:    if (t16 != 0)
        goto LAB174;

LAB173:    *((unsigned int *)t4) = 1;

LAB175:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB176;

LAB177:    xsi_set_current_line(199, ng1);
    xsi_vlogfile_write(1, 0, 0, ng62, 1, t0);

LAB178:    xsi_set_current_line(200, ng1);
    t2 = (t0 + 2000);
    xsi_process_wait(t2, 3000LL);
    *((char **)t1) = &&LAB180;
    goto LAB1;

LAB174:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB175;

LAB176:    xsi_set_current_line(198, ng1);

LAB179:    xsi_set_current_line(198, ng1);
    xsi_vlogfile_write(1, 0, 0, ng61, 1, t0);
    xsi_set_current_line(198, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng9)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_assign_value(t19, t4, 0, 0, 32);
    goto LAB178;

LAB180:    xsi_set_current_line(203, ng1);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng63, 2, t0, (char)119, t5, 32);
    xsi_set_current_line(209, ng1);
    xsi_vlog_finish(1);
    goto LAB1;

}

void Monitor_30_3(char *t0)
{
    char *t1;
    char *t2;

LAB0:    t1 = (t0 + 2144);
    t2 = (t0 + 2440);
    xsi_vlogfile_monitor((void *)Monitor_30_3_Func, t1, t2);

LAB1:    return;
}


extern void work_m_00000000000268292738_1499755349_init()
{
	static char *pe[] = {(void *)Initial_26_0,(void *)Always_27_1,(void *)Initial_29_2,(void *)Monitor_30_3};
	xsi_register_didat("work_m_00000000000268292738_1499755349", "isim/rgb_testbench_isim_beh.exe.sim/work/m_00000000000268292738_1499755349.didat");
	xsi_register_executes(pe);
}

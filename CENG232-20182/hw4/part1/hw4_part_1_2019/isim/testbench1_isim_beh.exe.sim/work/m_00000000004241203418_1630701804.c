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
static const char *ng0 = "C:/Users/erene/OneDrive/Belgeler/Dersler/20182/CENG232/hw4/part1/hw4_part_1_2019/lab4_1.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {15U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {30U, 0U};
static unsigned int ng6[] = {3U, 0U};
static unsigned int ng7[] = {48U, 0U};
static unsigned int ng8[] = {4U, 0U};
static unsigned int ng9[] = {80U, 0U};
static unsigned int ng10[] = {5U, 0U};
static unsigned int ng11[] = {102U, 0U};
static unsigned int ng12[] = {6U, 0U};
static unsigned int ng13[] = {106U, 0U};
static unsigned int ng14[] = {7U, 0U};
static unsigned int ng15[] = {126U, 0U};
static unsigned int ng16[] = {8U, 0U};
static unsigned int ng17[] = {129U, 0U};
static unsigned int ng18[] = {9U, 0U};
static unsigned int ng19[] = {160U, 0U};
static unsigned int ng20[] = {10U, 0U};
static unsigned int ng21[] = {166U, 0U};
static unsigned int ng22[] = {11U, 0U};
static unsigned int ng23[] = {189U, 0U};
static unsigned int ng24[] = {12U, 0U};
static unsigned int ng25[] = {192U, 0U};
static unsigned int ng26[] = {13U, 0U};
static unsigned int ng27[] = {208U, 0U};
static unsigned int ng28[] = {14U, 0U};
static unsigned int ng29[] = {211U, 0U};
static unsigned int ng30[] = {230U, 0U};



static void Always_4_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(4, ng0);
    t2 = (t0 + 1548);
    *((int *)t2) = 1;
    t3 = (t0 + 1380);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(5, ng0);

LAB5:    xsi_set_current_line(6, ng0);
    t4 = (t0 + 600U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t4, 4);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng10)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng12)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng14)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng16)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng18)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng20)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB27;

LAB28:    t2 = ((char*)((ng22)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB29;

LAB30:    t2 = ((char*)((ng24)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB31;

LAB32:    t2 = ((char*)((ng26)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB33;

LAB34:    t2 = ((char*)((ng28)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB35;

LAB36:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB37;

LAB38:
LAB40:
LAB39:    xsi_set_current_line(23, ng0);
    t2 = ((char*)((ng28)));
    t3 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);

LAB41:    goto LAB2;

LAB7:    xsi_set_current_line(7, ng0);
    t7 = ((char*)((ng1)));
    t8 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t8, t7, 0, 0, 8, 0LL);
    goto LAB41;

LAB9:    xsi_set_current_line(8, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 8, 0LL);
    goto LAB41;

LAB11:    xsi_set_current_line(9, ng0);
    t3 = ((char*)((ng5)));
    t4 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 8, 0LL);
    goto LAB41;

LAB13:    xsi_set_current_line(10, ng0);
    t3 = ((char*)((ng7)));
    t4 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 8, 0LL);
    goto LAB41;

LAB15:    xsi_set_current_line(11, ng0);
    t3 = ((char*)((ng9)));
    t4 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 8, 0LL);
    goto LAB41;

LAB17:    xsi_set_current_line(12, ng0);
    t3 = ((char*)((ng11)));
    t4 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 8, 0LL);
    goto LAB41;

LAB19:    xsi_set_current_line(13, ng0);
    t3 = ((char*)((ng13)));
    t4 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 8, 0LL);
    goto LAB41;

LAB21:    xsi_set_current_line(14, ng0);
    t3 = ((char*)((ng15)));
    t4 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 8, 0LL);
    goto LAB41;

LAB23:    xsi_set_current_line(15, ng0);
    t3 = ((char*)((ng17)));
    t4 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 8, 0LL);
    goto LAB41;

LAB25:    xsi_set_current_line(16, ng0);
    t3 = ((char*)((ng19)));
    t4 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 8, 0LL);
    goto LAB41;

LAB27:    xsi_set_current_line(17, ng0);
    t3 = ((char*)((ng21)));
    t4 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 8, 0LL);
    goto LAB41;

LAB29:    xsi_set_current_line(18, ng0);
    t3 = ((char*)((ng23)));
    t4 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 8, 0LL);
    goto LAB41;

LAB31:    xsi_set_current_line(19, ng0);
    t3 = ((char*)((ng25)));
    t4 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 8, 0LL);
    goto LAB41;

LAB33:    xsi_set_current_line(20, ng0);
    t3 = ((char*)((ng27)));
    t4 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 8, 0LL);
    goto LAB41;

LAB35:    xsi_set_current_line(21, ng0);
    t3 = ((char*)((ng29)));
    t4 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 8, 0LL);
    goto LAB41;

LAB37:    xsi_set_current_line(22, ng0);
    t3 = ((char*)((ng30)));
    t4 = (t0 + 828);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 8, 0LL);
    goto LAB41;

}


extern void work_m_00000000004241203418_1630701804_init()
{
	static char *pe[] = {(void *)Always_4_0};
	xsi_register_didat("work_m_00000000004241203418_1630701804", "isim/testbench1_isim_beh.exe.sim/work/m_00000000004241203418_1630701804.didat");
	xsi_register_executes(pe);
}

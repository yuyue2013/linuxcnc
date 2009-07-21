/********************************************************************
* Description: emcglb.c
*   Globals initialized to values in emccfg.h
*
*   Derived from a work by Fred Proctor & Will Shackleford
*
* Author:
* License: GPL Version 2
* System: Linux
*    
* Copyright (c) 2004 All rights reserved.
*
* Last change:
********************************************************************/

#include <string.h>		/* strcpy() */
#include <float.h>		// DBL_MAX
#include "emcglb.h"		/* these decls */
#include "emccfg.h"		/* their initial values */
#include "emcpos.h"		/* EmcPose */

char emc_inifile[LINELEN] = DEFAULT_EMC_INIFILE;

char emc_nmlfile[LINELEN] = DEFAULT_EMC_NMLFILE;

char rs274ngc_startup_code[LINELEN] =
    DEFAULT_RS274NGC_STARTUP_CODE;

int emc_debug = 0;		/* initially no debug messages */

double emc_task_cycle_time = DEFAULT_EMC_TASK_CYCLE_TIME;

double emc_io_cycle_time = DEFAULT_EMC_IO_CYCLE_TIME;

int emc_task_interp_max_len = DEFAULT_EMC_TASK_INTERP_MAX_LEN;

char tool_table_file[LINELEN] = DEFAULT_TOOL_TABLE_FILE;

struct AxisConfig_t AxisConfig[EMCMOT_MAX_AXIS];
struct TrajConfig_t TrajConfig;

EmcPose tool_change_position;	/* no defaults */
unsigned char have_tool_change_position = 0;	/* default is 'not there' */

int taskplanopen = 0;

void emcInitGlobals()
{
    int i;

    TrajConfig.Inited = 0;
    TrajConfig.Joints = 0;
    TrajConfig.MaxAccel = DBL_MAX;
    TrajConfig.Axes = 0;
    TrajConfig.AxisMask = 0;
    TrajConfig.LinearUnits = 1.0;
    TrajConfig.AngularUnits = 1.0;
    TrajConfig.MotionId = 0;
    TrajConfig.DefaultVel = DEFAULT_TRAJ_DEFAULT_VELOCITY;
    TrajConfig.MaxVel = DEFAULT_TRAJ_MAX_VELOCITY;

    for (i = 0; i < EMCMOT_MAX_AXIS; i++) {
        AxisConfig[i].MaxVel = DEFAULT_AXIS_MAX_VELOCITY; 
    }
        
}

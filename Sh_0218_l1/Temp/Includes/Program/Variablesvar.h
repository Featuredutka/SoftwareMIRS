/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1632179799_1_
#define _BUR_1632179799_1_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
#else
#endif

/* Variables */
_BUR_LOCAL struct FB_Motor secondmotor;
_BUR_LOCAL float counter;
_BUR_LOCAL float pwm_period;
_BUR_LOCAL plcbit enable;
_BUR_LOCAL float speed;
_BUR_LOCAL struct FB_Motor fb_motor;
_BUR_LOCAL struct FB_Regulator fb_regulator;

__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Program/Variables.var\\\" scope "
        "\\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MotorCtrl/MotorCtrl.fun\\\" "
        "scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");

#endif /* _BUR_1632179799_1_ */

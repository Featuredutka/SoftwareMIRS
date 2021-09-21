
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorCtrl.h"
#ifdef __cplusplus
	};
#endif

/* Integrator block for motor realization */

void FB_Integrator(struct FB_Integrator* inst)
{
	inst->out += inst->in*inst->dt;	
}

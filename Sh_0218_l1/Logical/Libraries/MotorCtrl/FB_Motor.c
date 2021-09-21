
#include <bur/plctypes.h>
#ifdef __cplusplus
extern "C" {
#endif
#include "MotorCtrl.h"
#ifdef __cplusplus
};
#endif
/* Functional block defining a motor */
void FB_Motor(struct FB_Motor *inst) {
  // Second integrator is used to keep 'omega' and 'phi' calcs separate
  inst->w = inst->u / inst->ke - inst->first_integrator.out;
  inst->w *= (inst->dt / inst->Tm);

  // A fucking void function and I gotta do three actions instead of one
  inst->first_integrator.in = inst->w;
  FB_Integrator(&inst->first_integrator);
  inst->w = inst->first_integrator.out;

  // Now we have 'omega' in it's final state and can compute 'phi'

  // Yeah, yeah, whatever
  inst->second_integrator.in = inst->w;
  FB_Integrator(&inst->second_integrator);
  inst->phi = inst->second_integrator.out;
}

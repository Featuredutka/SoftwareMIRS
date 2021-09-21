
#include <bur/plctypes.h>
#ifdef __cplusplus
extern "C" {
#endif
#include "MotorCtrl.h"
#ifdef __cplusplus
};
#endif
/* PID Regulator realization */

REAL voltage_limiter(REAL voltage, REAL max_voltage) {
  if (voltage > 0) {
    return (voltage > max_voltage) ? max_voltage : voltage;
  } else {
    return (voltage < -max_voltage) ? -max_voltage : voltage;
  }
}

void FB_Regulator(struct FB_Regulator *inst) {
  REAL buffer = inst->e * inst->k_i * inst->dt + inst->iyOld;

  inst->integrator.in = buffer;
  FB_Integrator(&inst->integrator);
  buffer = inst->integrator.out;

  inst->e = voltage_limiter(inst->e * inst->k_p, inst->max_abs_value) + buffer;
  inst->u = voltage_limiter(inst->e, inst->max_abs_value);

  inst->iyOld = inst->u - inst->e;
}

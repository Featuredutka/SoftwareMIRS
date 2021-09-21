
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
    fb_regulator.k_p = 1;
    fb_regulator.k_i = 1;
    fb_regulator.integrator.dt = 0.1;
    fb_regulator.integrator.out = 0;
    fb_regulator.iyOld = 0;
    fb_regulator.max_abs_value = 24;
    fb_regulator.dt = 0.1;

    fb_motor.phi = 0;
    fb_motor.Tm = 0.1;
    fb_motor.dt = 0.1;
    fb_motor.ke = 1;
    fb_motor.first_integrator.dt = 0.1;
    fb_motor.first_integrator.out = 0;
    fb_motor.second_integrator.dt = 0.1;
    fb_motor.second_integrator.out = 0;

    secondmotor.phi = 0;
    secondmotor.Tm = 0.1;
    secondmotor.dt = 0.1;
    secondmotor.ke = 1;
    secondmotor.first_integrator.dt = 0.1;
    secondmotor.first_integrator.out = 0;
    secondmotor.second_integrator.dt = 0.1;
    secondmotor.second_integrator.out = 0;

    speed = 100;
    pwm_period = 200;
    counter = 0;
    enable = 1;


}

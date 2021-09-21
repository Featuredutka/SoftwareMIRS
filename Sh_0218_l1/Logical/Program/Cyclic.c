
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
    fb_regulator.e = speed;
    fb_regulator.e -= fb_motor.w;
    FB_Regulator(&fb_regulator);
    fb_motor.u = fb_regulator.u;
    FB_Motor(&fb_motor);

    secondmotor.u = speed;
    FB_Motor(&secondmotor);

    if (counter >= pwm_period) {
        speed = (speed) ? 0 : 100;
        counter = 0;
    }
    counter++;
}

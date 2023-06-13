/*
 * lefl_easing.c
 */
#include "lefl.h"
#include "math.h"

inline void lefl_easing_pid(float *f,float target)
{
    if(!(fabs(*f-target)<=0.1))
        *f=*f+LEFL_ANIMATION_SPEED*(target-*f);
    else
        *f=target;
}

/* 
 * File:   pwm.h
 * Author: Owner
 *
 * Created on December 1, 2017, 12:53 AM
 */

#ifndef PWM_H
#define	PWM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <plib.h>
#include <p32xxxx.h>
#include <inttypes.h>
    
#define THROTTLE 1;
#define PITCH 2;
#define YAW 3;
#define ROLL 4;
    
// ~ 10.6 -> 1 microsecond
void pwm_change(int num, int start);

void pwm_init();

#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */


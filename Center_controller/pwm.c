/*============================================================================
 * window_control.c
 *        Module for window Control.
 *==========================================================================*/
#include <p32xxxx.h>
#include <inttypes.h>
#include <plib.h>
#include "pwm.h"
#define WINDOW_BIT_MASK 0x1
static int window_status;
/* Holds the value at which OCx Pin to be driven high */
static unsigned int pulse_start ;
static unsigned int pit ;//four control signal of the drone
static unsigned int yam ;
static unsigned int thr ;
static unsigned int rol ;
/* Holds the value at which OCx Pin to be driven low */
static unsigned int pulse_stop;

void pwm_init(){
// Use RPA0R as WINDOW outputs 3,4,7,15
    
        RPB3R = 0x5;//use pin 7,14,18,24 to send pwm signal
        RPB5R = 0x5;
        RPB13R = 0x5;
        RPB9R = 0x5;
        ANSELACLR =0x1;
        window_status = 0;
        CloseOC1();
        CloseOC2();
        CloseOC3();
        CloseOC4();
        PR2 = 2298 ;//14.8ms each pulse
        T2CON = 0x8070;//set up 1/256 prescaler
        pulse_start = 171;
        pulse_stop = 295;
        
        /* set up the four PWM channel*/
       OpenOC1(OC_ON | OC_IDLE_CON | OC_TIMER2_SRC |OC_CONTINUE_PULSE,pulse_stop, pulse_start);
       OpenOC2(OC_ON | OC_IDLE_CON | OC_TIMER2_SRC |OC_CONTINUE_PULSE,pulse_stop, pulse_start);
       OpenOC3(OC_ON | OC_IDLE_CON | OC_TIMER2_SRC |OC_CONTINUE_PULSE,pulse_stop, pulse_start);
       OpenOC4(OC_ON | OC_IDLE_CON | OC_TIMER2_SRC |OC_CONTINUE_PULSE,pulse_stop, pulse_start);
       
}


void pwm_change(int num, int pStart) //open
{
    
     unsigned int de=1480;//set up multiplier to generate the target start point of signal from the command received
     unsigned int length=2298;
     unsigned int maxLv=80;
    unsigned int startNum= ((maxLv-pStart)*length/de);
    
    //based on the channel set up different PWM
    if(num==1){
        yam=startNum;
       
  SetPulseOC1(yam, pulse_stop);
    }else if(num==2){
        pit=startNum;
  SetPulseOC2(pit, pulse_stop);
    }else if(num==3){
        rol=startNum;
  SetPulseOC3(rol, pulse_stop);
    }else if(num==4){
        thr=startNum;
  SetPulseOC4(thr, pulse_stop);
    }
}


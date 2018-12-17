
#include "uart.h"
#include "pwm.h"
//#include "analog_in.h"
//#include "optenc.h"
//#include "keyp.h"

#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

//static char command[32];


void main() {
    uart_init();
    pwm_init();

    run();
   
    
}




void run() {

    while(1) {

//        }
       
        char * command = uart_read_command();//read command
        
        

        int * value=getCommand(command);//get number in the command
        
      

         pwm_change(1,value[0]);//change pwm generate based command
         pwm_change(2,value[1]);
         pwm_change(3,value[2]);
         pwm_change(4,value[3]);
  
         

    }
}
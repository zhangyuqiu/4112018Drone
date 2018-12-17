#include "uart.h"

//#define UTXBF U1STA & 0b1000000000 >> 9 
//#define URXDA U1STA & 1
static char str[32];
static int data[4];
static uint8_t size=23;

void uart_init() {
    /* Clock configuration */
    ANSELA = 0;
    TRISA = 0b1111;
    U1RXR = 0; //set RPA2 to U1RX
    RPA0R = 1; //set RPA0 to U1TX
    //U1MODE = U1MODE | 0b1000; // set fast mode (Buad rate = 40Mhz / 4(for fast) or / 16 (for slow) then / U1BRG)
    U1MODE = U1MODE & 0b0111; // set slow mode (Buad rate = 40Mhz / 4(for fast) or / 16 (for slow) then / U1BRG)
    U1BRG = 260; // set divider for buad rate (target is 9600 kb/s))
    U1STA = U1STA | 0b1010000000000; // enable URXEN and UTXEN
    U1MODE = U1MODE | 0x8000; // set on to 1
}

void uart_write(char towrite) { // write a single char through uart
    while (!uart_write_ready()) {}; // check UTXBF is equal to 0 (the TX FIFO is not full))
        U1TXREG = towrite;  
}

char uart_read() { // read through uart
    while (!(uart_read_ready())) {} // check if URXDA is 1 (has data inside RX FIFO)
    char rx = U1RXREG;
    return rx;
}

int uart_read_ready() { // check if the reading is ready
    int a = (U1STA & 1); // check if URXDA is 1 (has data inside RX FIFO)
    return a;
}

int uart_write_ready() { // check if is ready to write
    int a = !(U1STA & 0x200); // check UTXBF is equal to 0 (the TX FIFO is not full))
    return a;
}

char uart_read_nb() { // non-blocking read
    if (!uart_read_ready()) {
        return '0';
    }
    else if (uart_read_ready()) {
        char rx = U1RXREG;
        return rx;
    }
}

void uart_write_nb(char towrite) {  // non-blocking write
    U1TXREG = towrite;
}

void uart_loop_test() { // test uart loop back write
    uart_init();
    uart_write('S');
    while (1) {
        char a = uart_read();
        uart_write(a);
    }
}

void uart_write_test_nb() { // test non-blocking write
    uart_init();
    uart_write('S');

    uart_write_nb('H');
    uart_write_nb('E');
    uart_write_nb('L');
    uart_write_nb('L');
    uart_write_nb('O');
    uart_write_nb(' ');
    uart_write_nb('W');
    uart_write_nb('O');
    uart_write_nb('R');
    uart_write_nb('L');
    uart_write_nb('D');
}

void uart_write_string(const char *towrite ){ // write a input sting or character through uart
    uint32_t length = strlen(towrite); 
    int i;
    for (i = 0; i < length; i++) { // write every single character inside the string
        uart_write(*(towrite+i));
    }
}

char * uart_read_command() {
    
    
    uint8_t index = 0;
    while (1) {
        char a = uart_read();//read character 
        str[index] = a;//save the string received
       index++;
        if (a == '*') {//if red * get the end
     
           str[index] = 0;//end the string
           size=index;//save size of string
             return str;
         }
        if (index > 30)
        {
            str[index] = 0;
            size=index;
            return(str);
        }
         
    }
}

int * getCommand(const char *command){
    char num[3];//number record
    int index=0;
    int count=0;
    
    uint8_t i;
    for(i=0;i<size;i++){//read through string
    char check=command[i];
        
        if(isdigit(check)){//if check a number
            num[count] =check;//save the number
            count++;//add up count
            
        }else if (isalpha(check)||(check == '*')) {//if check a character
            int current=0;
            if(count!=0){//if have number
                if(count==3){//if 3 digit
                count=0;//reset counter
                current=atoi(num);//convert to integer
                }else if(count==1){//if 1 digit
                 char temp =num[0];
                count=0;
                num[0]='0';
                num[1]='0';
                num[2]=temp;
                current=atoi(num);
                }else if(count==2){//if 2 digit
                    char temp =num[0];
                    char temp1 =num[1];
                    count=0;
                    num[0]='0';
                    num[1]=temp;
                    num[2]=temp1;
                    current=atoi(num);
                }
                data[index]=current;//save int in array
                index++;
            }
      }
        
}
    return (data);//return array of integer
}

int  getSize(){
    return size;
}
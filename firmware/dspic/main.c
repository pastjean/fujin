//#include "fujin.h"
#include <p33EP512MC806.h>
#include "globaldef.h"
#include "hardware_profile.h"
#include "fujin.h"
#include "uart.h"
#include <stdio.h>
#include <string.h>
// Device Configurations registers
_FOSCSEL(FNOSC_FRCPLL); // select fast internal rc with pll
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_XT);
_FWDT(FWDTEN_OFF); // Watchdog timer software enabled

uint8_t print=0;

sUartParam ubParam={BRGH_HIGH_SPEED,0,UART_8BITS_NOPARITY,UART_1STOP_BIT,UART_9600BAUD};
uint8_t buf[80];

int main(int argc, char** argv) {
    // INIT LED FIRST
    // SET ALL LED ON
    fujin_init_leds();
    PORTB =0x7800;

    set_clk();
    fujin_init_io();
    fujin_init_i2c();

    	UartInit(UART_1,&ubParam);
	UartTxEnable(UART_1, ENABLE);
	UartInitPortStruc(UART_1, NULL,NULL);
	UartInterruptTxEnable(UART_1, CHAR_N_BUFFER_EMPTY,2,ENABLE);
	//UartInterruptRxEnable(UART_1, CHAR_RECEIVE,3,ENABLE);
	UartTxFrame(UART_1, "Notus Started \n", 15);
        UartInit(UART_2,&ubParam);
	UartTxEnable(UART_2, ENABLE);
	UartInitPortStruc(UART_2, NULL,NULL);
	UartInterruptTxEnable(UART_2, CHAR_N_BUFFER_EMPTY,2,ENABLE);
	//UartInterruptRxEnable(UART_1, CHAR_RECEIVE,3,ENABLE);
	UartTxFrame(UART_2, "Notus Started \n", 15);

        //UartInit(UART_2,&ubParam);
	//UartTxEnable(UART_2, ENABLE);
	//UartInitPortStruc(UART_2, NULL,NULL);
	//UartInterruptTxEnable(UART_2, CHAR_N_BUFFER_EMPTY,2,ENABLE);
	//UartInterruptRxEnable(UART_1, CHAR_RECEIVE,3,ENABLE);
	//UartTxFrame(UART_2, "Notus Started \n", 15);

    //LED_PWR    =OFF;Nop();
    //LED_CANRX  =OFF;Nop();
    //LED_CANTX  =ON;Nop();
    //LED_LOWBAT =;Nop();
    //ltc4151_init();
    Init_Timer5(10.0);
    // 0xDE
    int i=0;
    while(1){

    //U1TXREG = 'a';
        char str[10] = "";
        if(print==1){
            print = 0;
            sprintf(str,"Hello %d\n\r",i);
            //UartTxFrame(UART_1, str, strlen(str));
            UartTxFrame(UART_2, str, strlen(str));
            
            if(++i>= 100){i=0;}
              LATBbits.LATB14^=1;
        }
        // process queued led events
       // led_execute();
        //ltc4151_read_current();
    }

    // Should never go there
    return 0;
}

void __attribute__((interrupt, auto_psv)) _T5Interrupt(void)
{
    /*Timer used for display at 10 Hz*/
    if(print==0) print = 1;

    _T5IF=0;
}
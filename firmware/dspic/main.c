//#include "fujin.h"
#include <p33EP512MC806.h>
#include "globaldef.h"
#include "hardware_profile.h"
#include "fujin.h"



#include <stdio.h>
#include <string.h>
// Device Configurations registers
_FOSCSEL(FNOSC_FRCPLL); // select fast internal rc with pll
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_XT);
_FWDT(FWDTEN_OFF); // Watchdog timer software enabled

uint8_t print=0;

int main(int argc, char** argv) {

    set_clk();
    fujin_init_io();
    PORTB =0x7800;

    fujin_init_i2c();
    fujin_init_uart();
//  fujin_init_can();

//  fujin_init_ltc4151();
//  fujin_init_cat24c256w();
//  fujin_init_ds1338();

// After initialization reset the leds
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
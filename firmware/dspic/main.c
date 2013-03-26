#include <stdio.h>
#include <stdlib.h>
#include "fujin.h"

// Device Configurations registers
_FOSCSEL(FNOSC_FRCPLL); // select fast internal rc with pll
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_XT);
_FWDT(FWDTEN_OFF); // Watchdog timer software enabled

uint8_t j=0;
void __attribute__((__interrupt__,no_auto_psv)) _U1TXInterrupt(void)
{
    if(!(++j%100)){
        LED_CANRX=ON;
    }
    if(!(++j%200)){
        LED_CANRX=OFF;
    }

    IFS0bits.U1TXIF = 0; // Clear TX

    U1TXREG = 'a'; // Transmit
}

int main(int argc, char** argv) {
// Set clk
    set_clk();
    fujin_init_io();
    fujin_init_uart();
    fujin_init_i2c();
    
    // Power on
   // led_turn_on(LED_PWR_B)
   LED_PWR   = ON;
   LED_RELAY = OFF;
   // led_execute();
    
    U1TXREG = 'a';

    ltc4151_init();

    // 0xDE
    while(1){
        // process queued led events
       // led_execute();
        ltc4151_read_current();
    }

    // Should never go there
    return (EXIT_SUCCESS);
}


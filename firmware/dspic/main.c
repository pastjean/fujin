#include <stdio.h>
#include <stdlib.h>
#include "fujin.h"
#include "peripherals/leds.h"

// Device Configurations registers
_FOSCSEL(FNOSC_FRCPLL); // select fast internal rc with pll
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_XT);





uint8_t j=0;
void __attribute__((__interrupt__)) _U1TXInterrupt(void)
{
    if(!(++j%100)){led_toggle(LED_CANRX_B);j=0;}
    IFS0bits.U1TXIF = 0; // Clear TX

    U1TXREG = 'a'; // Transmit
}

int main(int argc, char** argv) {
// Set clk
    set_clk();
    fujin_init_io();
    fujin_init_uart();

    // Power on
    led_turn_on(LED_PWR_B);
    led_execute();
    
    U1TXREG = 'a';
    while(1){
        // process queued led events
        led_execute();

    }

    // Should never go there
    return (EXIT_SUCCESS);
}



void fujin_init_uart(){
    U1MODEbits.STSEL = 0; // one stop bit
    U1MODEbits.PDSEL = 0; // no parity - 8 data bit
    U1MODEbits.ABAUD = 0; // auto baud disabled
    U1MODEbits.BRGH = 0; // low speed mode
    U1BRG = ((FOSC/2)/(16*UART1_SPEED)) - 1 ; // baud rate setting
    // interrupt after transmission of one tx char
    U1STAbits.UTXISEL0 = 0;
    U1STAbits.UTXISEL1 = 0;
    // enable uart interrupt
    IEC0bits.U1TXIE = 1;
    // Enable uart
    U1MODEbits.UARTEN = 1;
    // Enable uart tx
    U1STAbits.UTXEN = 1;
}
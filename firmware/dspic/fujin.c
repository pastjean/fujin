#include "fujin.h"

void set_clk()
{
    _PLLPRE=0;
    _PLLPOST=0;
    _PLLDIV=(unsigned int) (4.0f*FOSC_MHZ/(7.37f))-1;
    while(OSCCONbits.LOCK !=1);
}

void fujin_init_io(){

    // LEDS
    CONF_LED_PWR = OUTPUT;
    CONF_LED_LOWBAT = OUTPUT;
    CONF_LED_CANRX = OUTPUT;
    CONF_LED_CANTX= OUTPUT;
    CONF_LED_RELAY= OUTPUT;


    // UART 1 Pins // XBEE
    // _RP69R = 1; // RD5
    CONF_U1TX = OUTPUT;
    CONF_U1RX = INPUT;
    _RP96R = 0b000001;  // TX
    _U1RXR = 97; // RX

    // UART 2 Pins // USB-Serial
    CONF_U2TX = OUTPUT;
    CONF_U2RX = INPUT;
    _RP101R = 0b000011; //TX
    _U2RXR = 100;//RX

    // CAN 1 Pins
    CONF_CANTX = OUTPUT;
    CONF_CANRX = INPUT;
    _RP99R = 0b001110;    // CAN1TX
    _C1RXR = 98;

    // MISC Pins
    CONF_EEPROM_WP = OUTPUT;
    CONF_SD_CARD_CS = OUTPUT;

    // SPI Pins
    // SPI2 is an autonome guy he configures himself alone
    CONF_SDO = OUTPUT;
    CONF_SCK = OUTPUT;
    CONF_SDI = INPUT;
    _RP120R = 0b001000; // SDO2
    _RP118R = 0b001001; // SCK2
    //_SDI2R  = 119;      // SDI2

    // I2C Pins
    // You dont need to configure i2c pins since the i2c module configures
    // them like a big boy

    // OSC Pins
    // OSC Pins too are big boys!
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

void fujin_init_i2c(){
    	I2C_Init(I2C_1,100000.0f);
}
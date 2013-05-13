#include "fujin.h"
#include "lib/dspic/dspic.h"

void set_clk()
{
    _PLLPRE=0;
    _PLLPOST=0;
    _PLLDIV=(unsigned int) (4.0f*FOSC_MHZ/(7.37f))-1;
    while(OSCCONbits.LOCK !=1);
}

void fujin_init_io(){

    // LEDS
    TRISB = 0;
    // UART 1 Pins // XBEE
    // _RP69R = 1; // RD5
    CONF_U1TX = OUTPUT;
    CONF_U1RX = INPUT;
    _RP97R = 0b000001;  // TX
    _U1RXR = 96; // RX

    // UART 2 Pins // USB-Serial
    CONF_U2TX = OUTPUT;
    CONF_U2RX = INPUT;
    _RP101R = 0b000011; //TX
    _U2RXR = 100;//RX
//    _RP101R = 0b000001; //TX
//    _U1RXR = 100; // RX

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


sUartParam ubParam={BRGH_HIGH_SPEED,0,UART_8BITS_NOPARITY,UART_1STOP_BIT,UART_9600BAUD};
uint8_t uart_buf[80];

void fujin_init_uart(){
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
}

void fujin_init_i2c(){
    	I2C_Init(I2C_1,100000.0f);
}
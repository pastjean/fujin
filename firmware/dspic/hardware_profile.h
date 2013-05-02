#ifndef __HARDWARE_PROFILE_H
#define __HARDWARE_PROFILE_H

#include <p33EP512MC806.h>
// # Global Definitions
#define CPU_CLOCK 	100000000.0f
#define FOSC		100000000.0f			//External Xtal (HS)
#define FOSC_MHZ	(FOSC/1000000.0f)
#define UART1_SPEED	9600.0f				//UART baud rate
#define UART2_SPEED	9600.0f				//UART baud rate
#define I2C_SPEED	100000.0f			//I2C Clock Speed -> 389KHz
#define SPI_SPEED	100000.0f
#define CAN_SPEED	100000.0f


// # PIN and Config bits
// Pin mode: 
// - 1=input
// - 0=output
#define OUTPUT 0
#define INPUT 1

// Leds
#define LED_PORT   PORTB
#define LED_PWR    PORTBbits.RB11
#define LED_LOWBAT PORTBbits.RB12
#define LED_CANRX  PORTBbits.RB13
#define LED_CANTX  PORTBbits.RB14
#define LED_RELAY  PORTBbits.RB15
#define SWITCH_RELAY  PORTBbits.RB15

// Config LEDS
#define CONF_LED_PWR    TRISBbits.TRISB11
#define CONF_LED_LOWBAT TRISBbits.TRISB12
#define CONF_LED_CANRX  TRISBbits.TRISB13
#define CONF_LED_CANTX  TRISBbits.TRISB14
#define CONF_LED_RELAY  TRISBbits.TRISB15

// UART
// UART1 is USB-Serial
// UART2 is XBee
#define U2RX PORTFbits.RF4
#define U2TX PORTFbits.RF5
#define U1TX PORTFbits.RF1
#define U1RX PORTFbits.RF0

// Config UART
#define CONF_U2RX TRISFbits.TRISF4
#define CONF_U2TX TRISFbits.TRISF5
#define CONF_U1TX TRISFbits.TRISF1
#define CONF_U1RX TRISFbits.TRISF0

// CAN
#define CANRX PORTFbits.RF2
#define CANTX PORTFbits.RF3
// Config CAN
#define CONF_CANRX TRISFbits.TRISF2
#define CONF_CANTX TRISFbits.TRISF3

// SPI
#define SCK PORTGbits.RG6
#define SDI PORTGbits.RG7
#define SDO PORTGbits.RG8
// Config SPI
#define CONF_SCK TRISGbits.TRISG6
#define CONF_SDI TRISGbits.TRISG7
#define CONF_SDO TRISGbits.TRISG8

// I2C
// Config I2C
#define CONF_SCL TRISGbits.TRISG2
#define CONF_SDA TRISGbits.TRISG3

// Miscellaneous
#define EEPROM_WP PORTEbits.RE6
#define SD_CARD_CS PORTEbits.RE5
// Config Miscellaneous
#define CONF_EEPROM_WP TRISEbits.TRISE6
#define CONF_SD_CARD_CS TRISEbits.TRISE5


#endif // __HARDWARE_PROFILE_H

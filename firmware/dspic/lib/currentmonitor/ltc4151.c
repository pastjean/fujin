#include "ltc4151.h"
#include "../dspic/i2c/i2c.h"

/* LTC4151 i2c addresses */
#define LTC4151_WRITE 0xDE
#define LTC4151_READ 0xDF

/*LTC4151 registers*/
#define LTC4151_SENSE_MSB 0x00
#define LTC4151_SENSE_LSB 0x01
#define LTC4151_VIN_MSB 0x02
#define LTC4151_VIN_LSB 0x03
#define LTC4151_CONTROL 0x06

void ltc4151_init(){
    I2C_Send(LTC4151_WRITE,LTC4151_CONTROL,0b0000100,I2C_1);
}

float ltc4151_read_voltage()
{
	char error = 0;
	float voltage = 0.0f;
	uint8_t data_LSB = 0;
	uint8_t data_MSB = 0;

	/*Receive the High side and Low side (voltage value)*/
	error = I2C_Receive(LTC4151_WRITE,
                            LTC4151_READ,
                            LTC4151_VIN_LSB,
                            &data_LSB,
                            I2C_1);

	if (error == -1){return -1;}

	error = I2C_Receive(LTC4151_WRITE,
                            LTC4151_READ,
                            LTC4151_VIN_MSB,
                            &data_MSB,
                            I2C_1);
	if (error == -1){return -1;}

	/*Scale of the sensor is 25mV/bit*/
	/*Left justificaiton*/
	data_LSB = ((data_LSB&0xF0)>>4) + ((data_MSB<<4)&0xF0);
	voltage = ((float)data_LSB*0.025f);

	return voltage;
}

float ltc4151_read_current()
{
	char error = 0;
	float current = 0.0f;
	float sense = 0.0f;
	unsigned char data_LSB = 0;
	unsigned char data_MSB = 0;

	/*Receive the High side and Low side (sense value)*/
	error = I2C_Receive(LTC4151_WRITE,LTC4151_READ,LTC4151_SENSE_LSB,&data_LSB,I2C_1);
	if (error == -1)
		{
			return (float)error;
		}

	error = I2C_Receive(LTC4151_WRITE,LTC4151_READ,LTC4151_SENSE_MSB,&data_MSB,I2C_1);
		if (error == -1)
		{
			return (float)error;
		}
	/*Scale of the sensor is 20uV/bit*/
	/*Left justificaiton*/
	data_LSB = ((data_LSB&0xF0)>>4) + ((data_MSB<<4)&0xF0);
	sense = ((float)data_LSB*0.000020f);
	/*Sense resistor = 0.02 ohms -> I=V/R*/
	current = sense/0.02f;

	return current;
}

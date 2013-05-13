#ifndef _I2C_MODULE_H
#define _I2C_MODULE_H

#include"p33EP512MC806.h"
#include "globaldef.h"
#include "hardware_profile.h"


/*Macro for I2C bus speed calculation*/
#define I2CSPEED(DESIREDSPEED)  ((1.0f/((1.0f/(CPU_CLOCK/2.0f))*(DESIREDSPEED)))-1.0f)

/*Interface for user*/
#define NB_I2C 2
#define I2C_1  (0)
#define I2C_2  (1)

bool I2C_Init(uint8_t ubI2cNo, float fSpeed);
bool I2C_Send(uint8_t ubAddress,uint8_t ubRegister,uint8_t ubData, uint8_t ubI2cNo);
bool I2C_Receive(uint8_t ubAddressWrite,uint8_t ubAddressRead,uint8_t ubRegister,uint8_t* ubData, uint8_t ubI2cNo);

#endif // _I2C_MODULE_H
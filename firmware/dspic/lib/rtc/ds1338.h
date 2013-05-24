#ifndef __DS1338_H
#define	__DS1338_H

#include "../../globaldef.h"
#include "../../hardware_profile.h"

typedef struct{
    uint8_t port;
}ds1338_s;

void ds1338_init(ds1338_s* ds1338,int i2c_port);

#endif // __LTC4151_H

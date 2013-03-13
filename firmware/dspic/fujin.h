#ifndef __FUJIN_H
#define	__FUJIN_H


#include "p33EP512MC806.h"
#include "hardware_profile.h"
#include "globaldef.h"


#define REDIS_OK                0
#define REDIS_ERR               -1

#define fujinDebug(fmt, ...) \
    printf("DEBUG %s:%d > " fmt "\n", __FILE__, __LINE__, __VA_ARGS__)


#define SET_INPUT(pin) \
    pin = 1
#define SET_OUTPUT(pin) \
    pin = 0

#define LED_ON(led) \
    led = 1
#define LED_OFF(led) \
    led = 0


#endif	// __FUJIN_H


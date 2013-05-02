#ifndef __FUJIN_H
#define	__FUJIN_H

#include "p33EP512MC806.h"
#include "hardware_profile.h"
#include "globaldef.h"

// Peripheral includes
#include "M_TMR.h"
#include "i2c.h"

// Device includes
#include "ltc4151.h"

#define FUJIN_OK                0
#define FUJIN_ERR               -1

#define fujinDebug(fmt, ...) \
    printf("DEBUG %s:%d > " fmt "\n", __FILE__, __LINE__, __VA_ARGS__)

void set_clk();
void fujin_init_leds();
void fujin_init_io();
void fujin_init_uart();
void fujin_init_i2c();
#endif	// __FUJIN_H


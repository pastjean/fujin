#ifndef __FUJIN_H
#define	__FUJIN_H

#include "hardware_profile.h"
#include "globaldef.h"

#define FUJIN_OK                0
#define FUJIN_ERR               -1

#define fujinDebug(fmt, ...) \
    printf("DEBUG %s:%d > " fmt "\n", __FILE__, __LINE__, __VA_ARGS__)



void set_clk();
void fujin_init_io();
void fujin_init_uart();

#endif	// __FUJIN_H


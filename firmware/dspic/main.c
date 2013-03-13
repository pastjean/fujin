#include <stdio.h>
#include <stdlib.h>
#include "fujin.h"
int main(int argc, char** argv) {

    // Configure leds
    SET_INPUT(CONF_LED_PWR);
    LED_ON(LED_PWR);

    while(1){}

    // Should never go there
    return (EXIT_SUCCESS);
}


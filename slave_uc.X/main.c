/*
 * File:   main.c
 * Author: Guilherme Andrade - guilhermedvae@gmail.com
 *
 * Created on 30 de Março de 2019, 23:41
 */

#include "drivers/configBits.h" // This must be the first line in the project
#include <xc.h>

#include "applications/application.h"
#include "services/interrupts.h"
#include "drivers/oscillators.h"
#include "drivers/gpio.h"
#include "drivers/timers.h"
#include "drivers/i2c.h"

void systemInit(void);

void main(void) {
    
    systemInit();
    applicationInit();
    
    while(1){
        applicationRun();
    }
    return;
}

void systemInit(void){

    oscillatorInit();
    interruptInit();
    gpioInit();
    timer0Init();
    i2cInit();
}
/*
 * File:   application.c
 * Author: Guilherme Andrade - guilhermedvae@gmail.com
 *
 * Created on 30 de Março de 2019, 23:45
 */

#include "application.h"
#include "../drivers/gpio.h"
#include "../services/ledService.h"
#include "../services/interrupts.h"

timeCounterType timeFlagStruct;
int ledstate;

void applicationRun(void) {
    
    // Test application: A led blinking once per second
    if(timeFlagStruct.flag){
        timeFlagStruct.flag = 0;
        
        if(ledstate){
            ledOff();
            ledstate = 0;
        }
        else{
            ledOn();
            ledstate = 1;
        }
    }
    
    return;
}

void applicationInit(void){
    ledInit();
    
    // time struct to get a flag set at each second
    timeFlagStruct.countedTicks = 0;
    timeFlagStruct.totalTicks = 100;
    timeFlagStruct.flag = 0;
    
    register10msCounter(&timeFlagStruct);
}
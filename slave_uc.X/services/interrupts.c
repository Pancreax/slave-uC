/*
 * File:   interrupts.c
 * Author: Guilherme Andrade - guilhermedvae@gmail.com
 *
 * Created on 01 de Abril de 2019, 00:54
 */

#include "interrupts.h"
#include "../drivers/timers.h"
#include "../drivers/ioMapping.h"
#include "../drivers/i2c.h"
#include "ledService.h"

// timer postscalers
int ps1,ps10;

// arrays of pointers to timer flags
// The services or applications can register time counters with flags to be set
// at some time rates.
timeCounterType * timer1msCounters[NUMBER_OF_1MS_COUNTERS];
timeCounterType * timer10msCounters[NUMBER_OF_10MS_COUNTERS];
timeCounterType * timer100msCounters[NUMBER_OF_100MS_COUNTERS];

void interruptInit(void){
    RCONbits.IPEN = 0b1; // enable interrupt priority levels
    INTCONbits.GIEH = 0b1; // enable high priority interrupts
    INTCONbits.GIEL = 0b1; // enable low priority interrupts
    
    //reset all pointers to time counters
    for(int i = 0; i < NUMBER_OF_1MS_COUNTERS; i ++) timer1msCounters[i] = 0;
    for(int i = 0; i < NUMBER_OF_10MS_COUNTERS; i ++) timer10msCounters[i] = 0;
    for(int i = 0; i < NUMBER_OF_100MS_COUNTERS; i ++) timer100msCounters[i] = 0;
    
    ps1 = 0;
    ps10 = 0;
}

void __interrupt() high_isr(void){
    
    // Timer0 Interrupt - Freq = 1000 Hz - Period = 0.001 seconds
    if (TMR0_INTERRUPT_FLAG) {
        
        // increment registered 1ms timer counters (without overflowing them)
        for(int i = 0; i < NUMBER_OF_1MS_COUNTERS; i ++){
            if(timer1msCounters[i] == 0) continue;
            if((timer1msCounters[i]->countedTicks)++ > timer1msCounters[i]->totalTicks){
                timer1msCounters[i]->flag = 1;
                timer1msCounters[i]->countedTicks = 0;
            }
        }
        
        /* Postscalers */
        if (++ps1 == 10) { /* each 10 ms */
            ps1 = 0;
            
            // increment registered 10ms timer counters (without overflowing them)
            for(int i = 0; i < NUMBER_OF_10MS_COUNTERS; i ++){
                if(timer10msCounters[i] == 0) continue;
                if((timer10msCounters[i]->countedTicks)++ > timer10msCounters[i]->totalTicks){
                    timer10msCounters[i]->flag = 1;
                    timer10msCounters[i]->countedTicks = 0;
                }
            }

            if (++ps10 == 10) { /* each 100 ms */
                ps10 = 0;

                // increment registered 100ms timer counters (without overflowing them)
                for(int i = 0; i < NUMBER_OF_100MS_COUNTERS; i ++){
                    if(timer100msCounters[i] == 0) continue;
                    if((timer100msCounters[i]->countedTicks)++ > timer100msCounters[i]->totalTicks){
                        timer100msCounters[i]->flag = 1;
                        timer100msCounters[i]->countedTicks = 0;
                    }
                }
            }
        }
        
        timer0AddPreset(TMR0_PRESET);
        TMR0_INTERRUPT_FLAG = 0;
    }
}

void __interrupt(low_priority) low_isr(void){
    
    if(MSSP_INTERRUPT_FLAG){
        
        i2cReleaseClock();
        MSSP_INTERRUPT_FLAG = 0;
    }
}

void register1msFlag(timeCounterType * pointerToTimeFlagVariable){
    for(int i = 0; i < NUMBER_OF_1MS_COUNTERS; i ++){
        if(timer1msCounters[i] != 0) continue;
        timer1msCounters[i] = pointerToTimeFlagVariable;
        return;
    }
}

void unregister1msCounter(timeCounterType * pointerToTimeFlagVariable){
    for(int i = 0; i < NUMBER_OF_1MS_COUNTERS; i ++){
        if(timer1msCounters[i] != pointerToTimeFlagVariable) continue;
        timer1msCounters[i] = 0;
        return;
    }
}

void register10msCounter(timeCounterType * pointerToTimeFlagVariable){
    for(int i = 0; i < NUMBER_OF_10MS_COUNTERS; i ++){
        if(timer10msCounters[i] != 0) continue;
        timer10msCounters[i] = pointerToTimeFlagVariable;
        return;
    }
}

void unregister10msCounter(timeCounterType * pointerToTimeFlagVariable){
    for(int i = 0; i < NUMBER_OF_10MS_COUNTERS; i ++){
        if(timer10msCounters[i] != pointerToTimeFlagVariable) continue;
        timer10msCounters[i] = 0;
        return;
    }
}

void register100msCounter(timeCounterType * pointerToTimeFlagVariable){
    for(int i = 0; i < NUMBER_OF_100MS_COUNTERS; i ++){
        if(timer100msCounters[i] != 0) continue;
        timer100msCounters[i] = pointerToTimeFlagVariable;
        return;
    }
}

void unregister100msCounter(timeCounterType * pointerToTimeFlagVariable){
    for(int i = 0; i < NUMBER_OF_100MS_COUNTERS; i ++){
        if(timer100msCounters[i] != pointerToTimeFlagVariable) continue;
        timer100msCounters[i] = 0;
        return;
    }
}


/* 
 * File:   interrupts.h
 * Author: Guilherme Andrade - guilhermedvae@gmail.com
 *
 * Created on 1 de Abril de 2019, 00:54
 */

#ifndef INTERRUPTS_H
#define	INTERRUPTS_H

#include <xc.h> // include processor files - each processor file is guarded.

#define NUMBER_OF_1MS_COUNTERS 10
#define NUMBER_OF_10MS_COUNTERS 10
#define NUMBER_OF_100MS_COUNTERS 10

typedef struct timeCounterType {
    unsigned int totalTicks;
    unsigned int countedTicks;
    unsigned int flag;
} timeCounterType;

void interruptInit(void);
void register1msCounter(timeCounterType * pointerToTimeFlagVariable);
void unregister1msCounter(timeCounterType * pointerToTimeFlagVariable);
void register10msCounter(timeCounterType * pointerToTimeFlagVariable);
void unregister10msCounter(timeCounterType * pointerToTimeFlagVariable);
void register100msCounter(timeCounterType * pointerToTimeFlagVariable);
void unregister100msCounter(timeCounterType * pointerToTimeFlagVariable);

#endif	/* INTERRUPTS_H */


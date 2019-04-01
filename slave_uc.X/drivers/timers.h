/* 
 * File:   timers.h
 * Author: Guilherme Andrade - guilhermedvae@gmail.com
 *
 * Created on 1 de Abril de 2019, 00:06
 */

#ifndef TIMERS_H
#define	TIMERS_H

#include <xc.h> // include processor files - each processor file is guarded.

// timer0 will generate interrupts at each t0_p = 1ms.
// So pre scaler "ps" should be:
// ps > FCY/(256/t0_p))
// ps > 16000000 / (256/0.001))
// ps > 62.5 
// The lower possible value greater than 62.5 is 64, then ps = 64.

// With the pre scaler of 64. the increment frequency of the timer is FCY/64;
// We want that the total count time to be 1ms:
// (1/(FCY/64))*count = 1ms
// count = 1ms/(1/(FCY/64))
// count = 1ms/(1/(16000000/64))
// count = 250 
// That means that the timer should count 250 times before an overflow
// Also, the pic datasheet says that, on each write in the TMR0 register,
// the timer don't count for the next 2 instruction cycles.
// Then, the preset of the timer should be:

// TMR0_PRESET = 256 - count - 2
// TMR0_PRESET = 256 - 250 - 2
// TMR0_PRESET = 4

#define TMR0_PRESET 4
#define TMR0_INTERRUPT_FLAG INTCONbits.TMR0IF

#define timer0AddPreset(x) TMR0 += x

void timer0Init(void);

#endif	/* TIMERS_H */


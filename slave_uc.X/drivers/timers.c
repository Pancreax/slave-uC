/*
 * File:   timers.c
 * Author: Guilherme Andrade - guilhermedvae@gmail.com
 *
 * Created on 01 de Abril de 2019, 00:10
 */

#include "timers.h"

void timer0Init(void){    
    
    T0CONbits.TMR0ON = 0b0; // Stop Timer0
    
    T0CONbits.T08BIT = 0b1; // 8 bit timer
    T0CONbits.T0CS = 0b0; // Clock source from internal clock
    T0CONbits.PSA = 0b0; // Timer0 clock input comes from prescaler output 
    T0CONbits.T0PS = 0b101; // 1:64 Prescale value
    
    TMR0 = TMR0_PRESET; // load the preset value in TMR0
    
    INTCON1bits.TMR0IF = 0b0; // Clear timer0 interrupt flag 
    INTCON2bits.TMR0IP = 0b1; // High priority interrupt
    INTCON1bits.TMR0IE = 0b1; // enable timer0 interrupt 
    
    T0CONbits.TMR0ON = 0b1; //Start Timer 0
}
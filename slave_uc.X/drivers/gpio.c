/*
 * File:   gpio.c
 * Author: Guilherme Andrade - guilhermedvae@gmail.com
 *
 * Created on 31 de Março de 2019, 15:11
 */

#include "gpio.h"

void gpioInit (void){
    
    ANCON0 = 0; // All pins digital
    ANCON1 = 0; //
    
    TRISA = 0xFF; // All pins are inputs
    TRISB = 0xFF; //
    TRISC = 0xFF; //
}
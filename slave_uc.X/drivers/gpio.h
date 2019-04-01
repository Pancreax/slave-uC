/* 
 * File:   gpio.h
 * Author: Guilherme Andrade - guilhermedvae@gmail.com
 *
 * Created on 31 de Março de 2019, 15:12
 */

#ifndef GPIO_H
#define	GPIO_H

#include <xc.h> // include processor files - each processor file is guarded.

void gpioInit (void);

// To be used with the PINCFG_ defines of iomapping.h
#define configAsOutput(x)   x= 0b0
#define configAsInput(x)   x= 0b1

// To be used with the PIN_ defines of iomapping.h
#define outputHigh(x)  	x = 0b1
#define outputLow(x)  	x = 0b0
#define inputRead(x)    x

#endif	/* GPIO_H */


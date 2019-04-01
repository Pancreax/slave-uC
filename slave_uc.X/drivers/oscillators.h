/* 
 * File:   oscilators.h
 * Author: Guilherme Andrade - guilhermedvae@gmail.com
 *
 * Created on 31 de Março de 2019, 14:58
 */

#ifndef OSCILLATORS_H
#define	OSCILLATORS_H

#include <xc.h> // include processor files - each processor file is guarded. 

#define FOSC 64000000 // Hz
#define FCY (FOSC/4) // Hz

void oscillatorInit (void);

#endif	/* OSCILLATORS_H */


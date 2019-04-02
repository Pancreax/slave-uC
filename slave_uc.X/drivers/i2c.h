/* 
 * File:   i2c.h
 * Author: Guilherme Andrade - guilhermedvae@gmail.com
 *
 * Created on 1 de Abril de 2019, 22:56
 */

#ifndef I2C_H
#define	I2C_H

#include <xc.h> // include processor files - each processor file is guarded.

#define MSSP_INTERRUPT_FLAG PIR1bits.SSPIF
#define i2cReleaseClock() SSPCON1bits.CKP = 1

void i2cInit(void);

#endif	/* I2C_H */


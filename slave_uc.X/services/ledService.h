/* 
 * File:   ledService.h
 * Author: Guilherme Andrade - guilhermedvae@gmail.com
 *
 * Created on 31 de Março de 2019, 23:33
 */

#ifndef LEDSERVICE_H
#define	LEDSERVICE_H

#include <xc.h> // include processor files - each processor file is guarded.
#include "../drivers/gpio.h"
#include "../drivers/ioMapping.h"

#define ledInit() configAsOutput(PINCFG_LED)
#define ledOn() outputHigh(PIN_LED)
#define ledOff() outputLow(PIN_LED)

#endif	/* LEDSERVICE_H */


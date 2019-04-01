/* 
 * File:   ioMapping.h
 * Author: guilherme
 *
 * Created on 31 de Março de 2019, 23:03
 */

#ifndef IOMAPPING_H
#define	IOMAPPING_H

#include <xc.h> // include processor files - each processor file is guarded.

// This file should contain a reference of what is connected in which pin.
// Change the name of a define or add a different define as needed to specify something connected to a pin.
// defines to TRIS bits should start with PINCFG_, and PORT bits should start with PIN_ 

/************** TRIS Bits *****************/

#define PINCFG_RA0 TRISAbits.TRISA0
#define PINCFG_RA1 TRISAbits.TRISA1
#define PINCFG_LED TRISAbits.TRISA2
#define PINCFG_RA3 TRISAbits.TRISA3
#define PINCFG_RA5 TRISAbits.TRISA5

#define PINCFG_RB0 TRISBbits.TRISB0
#define PINCFG_RB1 TRISBbits.TRISB1
#define PINCFG_RB2 TRISBbits.TRISB2
#define PINCFG_RB3 TRISBbits.TRISB3
#define PINCFG_RB4 TRISBbits.TRISB4
#define PINCFG_ORANGEPI_RESET TRISBbits.TRISB5
#define PINCFG_RB6 TRISBbits.TRISB6
#define PINCFG_RB7 TRISBbits.TRISB7

#define PINCFG_RC0 TRISCbits.TRISC0
#define PINCFG_RC1 TRISCbits.TRISC1
#define PINCFG_RC2 TRISCbits.TRISC2
#define PINCFG_RC3 TRISCbits.TRISC3
#define PINCFG_RC4 TRISCbits.TRISC4
#define PINCFG_RC5 TRISCbits.TRISC5
#define PINCFG_RC6 TRISCbits.TRISC6
#define PINCFG_RC7 TRISCbits.TRISC7

#define PINCFG_RE3 TRISEbits.TRISE3

/************** PORT Bits *****************/

#define PIN_RA0 PORTAbits.RA0
#define PIN_RA1 PORTAbits.RA1
#define PIN_LED PORTAbits.RA2
#define PIN_RA3 PORTAbits.RA3
#define PIN_RA5 PORTAbits.RA5

#define PIN_RB0 PORTBbits.RB0
#define PIN_RB1 PORTBbits.RB1
#define PIN_RB2 PORTBbits.RB2
#define PIN_RB3 PORTBbits.RB3
#define PIN_RB4 PORTBbits.RB4
#define PIN_ORANGEPI_RESET PORTBbits.RB5
#define PIN_RB6 PORTBbits.RB6
#define PIN_RB7 PORTBbits.RB7

#define PIN_RC0 PORTCbits.RC0
#define PIN_RC1 PORTCbits.RC1
#define PIN_RC2 PORTCbits.RC2
#define PIN_RC3 PORTCbits.RC3
#define PIN_RC4 PORTCbits.RC4
#define PIN_RC5 PORTCbits.RC5
#define PIN_RC6 PORTCbits.RC6
#define PIN_RC7 PORTCbits.RC7

#define PIN_RE3 PORTEbits.RE3

#endif	/* IOMAPPING_H */


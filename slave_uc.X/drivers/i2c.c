/* 
 * File:   i2c.c
 * Author: Guilherme Andrade - guilhermedvae@gmail.com
 *
 * Created on 1 de Abril de 2019, 22:56
 */

#include "i2c.h"

void i2cInit(void){
    
    SSPSTATbits.SMP = 0; //Slew rate control is enabled for High-Speed mode (400 kHz)
    SSPSTATbits.CKE = 0; // Disables SMBus specific inputs 
    
    SSPCON1bits.WCOL = 0; // No collisions detected
    
    SSPCON1bits.SSPM = 0b1001; // write this value on SSPM enables writes on SSPADD to be redirected to SSPMSK
    SSPADD = 0xE0; // actully writting on SSPMSK register. This masks the 4 lower bits of i2c address (the bit 0 is not used as i2c address)
    
    SSPCON1bits.SSPM = 0b0110; // I2C Slave mode, 7-bit address
    SSPADD = 0x80; // base slave address 
    
    SSPCON2bits.SEN = 0b1; //  Clock stretching is enabled for both slave transmit and slave receive (stretch enabled)
    
    IPR1bits.SSPIP = 0b0; // MSSP interrupt is low priority
    PIR1bits.SSPIF = 0b0; // Clear MSSP interrupt flag
    PIE1bits.SSPIE = 0b1; // Enable MSSP interrupt on i2c Slave address match 
    
    SSPCON1bits.CKP = 1; // release clock line
    SSPCON1bits.SSPEN = 1; // Enables i2c módule
}

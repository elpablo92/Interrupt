/*
 * File:   main.c
 * Author: dell
 *
 * Created on February 18, 2020, 8:22 PM
 */


#include <xc.h>
#include"config.h"
#define _XTAL_FREQ 8000000
int cont;
void Int_Ext(void);


void main(void){
    
    OSCCON=0x72;         
    Int_Ext();
    ADCON1bits.PCFG = 0xF;
    TRISAbits.RA0 = 1;
    TRISDbits.RD0 = 0;
    TRISDbits.RD4 = 0;
    PORTAbits.RA0 = 1;
    __delay_ms(4000);
    PORTAbits.RA0 = 0;
    
    while(1){
        PORTDbits.RD0 =1;
        PORTDbits.RD4=~PORTDbits.RD4;
        __delay_ms(500);
        
    }
    
}

void Int_Ext(void){
    TRISBbits.RB0 = 1;
    INTCONbits.INT0IE = 1; // Habilitar INT0 
    INTCONbits.INT0IF = 0; //FLag 0
    INTCON2bits.INTEDG0 = 0; //Flanco descendete
    INTCONbits.GIE = 1;
}

void __interrupt() INT_isr(void){
    
    
    PORTDbits.RD0=0;
    __delay_ms(5000);
    INTCONbits.INT0IF = 0; //FLag 0
}


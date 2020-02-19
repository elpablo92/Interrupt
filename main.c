/*
 * File:   main.c
 * Author: dell
 *
 * Created on February 18, 2020, 8:22 PM
 */


#include <xc.h>
#include"config.h"

void initInterrupt(){
    ADCON1bits.PCFG = 0x0F;        // 000011111
        
    TRISB=0b11111111;                //define inputs all TRISB
      
    
    INTCONbits.GIE=1;           //enable Global Interrupts
   // INTCONbits.RBIE=1;          //Enable Interrupt PORTB
   // INTCONbits.RBIF=0;          //FLAG change on portB init 0
    
    //INTCON2bits.RBIP=0;         //LOW priority for RB interrupt
    INTCON2bits.RBPU=0;         //0 flanco de bajada 1 flanco subida
    
    //INTCON2bits.INTEDG0=1;      //rb0 external interrupt enable
    INTCON2bits.INTEDG1=1;      //rb1 external interrupt enable
    //INTCON2bits.INTEDG2=1;      //rb2 external interrupt enable
    
    INTCON3bits.INT1E=1;           //enable external interrupt for RB1
    //INTCON3bits.INT2E=1;          //Habilitacion del interrupcion por puerto RB
    INTCON3bits.INT1IF=0;           // Bandera inicia en 0 para poder recibir valores
    //INTCON3bits.INT2IF=0;
    
   
}


void main(void) {
    OSCCON=0x72;  //0x72 Equivalente a binario = 01110010 configurado a 8MHZ
    TRISAbits.RA0 = 0;
    initInterrupt();
      
   //configurar todo lo inicial de la interrupcion
   
    
}




void __interrupt(low_priority) interruptRB(void){
//interrupcion del puertoB
    if(INTCON3bits.INT1E && INTCON3bits.INT1F){
        PORTAbits.RA0 = ~PORTAbits.RA0;
        __delay_ms(1000);
        
    
    }
   
    
}

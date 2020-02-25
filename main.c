/*
 * File:   main.c
 * Author: dell
 *
 * Created on February 18, 2020, 8:22 PM
 */


#include <xc.h>
#include"config.h"
#define _XTAL_FREQ 8000000

void initInterrupt(){
    int x=0;
    /*final de configuracion*/
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
    /*final de configuracion*/
    
    
    /* habilitacion de la interrupcion*/
    INTCON3bits.INT1E=1;           //enable external interrupt for RB1
    //INTCON3bits.INT2E=1;          //Habilitacion del interrupcion por puerto RB
    INTCON3bits.INT1IF=0;           // Bandera inicia en 0 para poder recibir valores
    //INTCON3bits.INT2IF=0;
    /* FIN habilitacion de la interrupcion*/
   
}


void main(void) {
    
    OSCCON=0x72;  //0x72 Equivalente a binario = 01110010 configurado a 8MHZ
    TRISAbits.RA0 = 0;
    initInterrupt();
      
   //configurar todo lo inicial de la interrupcion
    
    while(1){
        /*
         akjdsf;alksdjf;laksd
         * asd,kfaksdj
         * asdfjahskdl
         
         */
        PORTAbits.RA4 =1;
        __delay_ms(10000);
        PORTAbits.RA4 =0;
        __delay_ms(10000);
        
        for(x; x++; x>10){
            PORTAbits.RA5 =1;
            __delay_ms(10000);
            PORTAbits.RA5 =0;
            __delay_ms(10000);
        }
    
    
    }
    
   
    
}


//esta RA0 = 1
void __interrupt(low_priority) interruptRB(void){
//interrupcion del puertoB
    if(INTCON3bits.INT1E && INTCON3bits.INT1F){
        
        PORTAbits.RA0 = ~PORTAbits.RA0;
        __delay_ms(1000);
        INTCON3bits.INT1F = 0;  //reinicio necesario
        
    
    }
    
    // interrupcion hola
    
   
    
}

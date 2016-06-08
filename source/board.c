#include "sam.h"                        // Device header
#include "board.h"

//led at PC8
void led_init(void){
    PMC->PMC_PCER0=(0x1 << ID_PIOC); //enable peripherial  PIOC
    PIOC->PIO_PER= PIO_PC8;//Direct on control
    PIOC->PIO_OER= PIO_PC8; //pin as output
    PIOC->PIO_SODR= PIO_PC8; //tunr off led
}

//button at PA11
void button_init(void){
    PMC->PMC_PCER0=(0x1 << ID_PIOA);//enable peripherial PIOA
    PIOA->PIO_PER=PIO_PA11;//Direct pio control
    PIOA->PIO_ODR=PIO_PA11;//pin as input
    PIOA->PIO_CODR=PIO_PA11;
    PIOA->PIO_PUER=PIO_PA11;//enable pull-ups
    //interrupt
    PIOA->PIO_AIMDR=PIO_PA11;//both edge interrupt
 
    int irs_status =PIOA->PIO_ISR;//clear interrupt
  
    PIOA->PIO_IER=PIO_PA11;// Enable interrupt: pin
    NVIC_EnableIRQ(PIOA_IRQn);//active nvic: peripherial  
}

int button_read(void){
    return (PIOA->PIO_PDSR & PIO_PA11) ? RELEASED: PRESSED; //active low button
}

void led_write(int new_state){
    if(new_state == ON){
        PIOC->PIO_CODR=PIO_PC8;//turn on led: output low
    }else{
        PIOC->PIO_SODR=PIO_PC8;// tunr off led: output high
    }
}

__attribute__((weak)) void button_on_change_handler(void){
}

void PIOA_Handler(void){
    int interrpt_status = PIOA->PIO_ISR;
    if(interrpt_status & PIO_PA11){
        button_on_change_handler();
        
     }        
}

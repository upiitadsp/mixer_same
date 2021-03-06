#include "sam.h"                        // Device header
#include "timer_same70.h"

void timer0_init(int overflow_frequecy){
    PMC->PMC_PCER0 = 0x1 << ID_TC0;
    TC0->TC_CHANNEL[0].TC_CMR = TC_CMR_TCCLKS_TIMER_CLOCK2 | TC_CMR_CPCTRG;//timer clock is CMK*8 = 150MHz/8 = 18.75MHz
    TC0->TC_CHANNEL[0].TC_RC = (18750000/overflow_frequecy)-1;
    TC0->TC_CHANNEL[0].TC_IER = TC_IER_CPCS;
    
    NVIC_EnableIRQ(TC0_IRQn);
    TC0->TC_CHANNEL[0].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;//Enable clock and trigger counter
}

__attribute__ ((weak)) void TC0_callback(void){
}

void TC0_Handler(void){
    unsigned int status;
    status = TC0->TC_CHANNEL[0].TC_SR;
    if((status & TC_SR_CPCS)){//Channel 0 interrupt
        //TODO
        TC0_callback();
    }
}

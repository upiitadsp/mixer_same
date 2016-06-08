#include "sam.h"                        // Device header
#include "dac_same70.h"

void dac_init(void){
    //PB13 DAC0
    PMC->PMC_PCER0 = 0x1 << ID_DACC;//Enable DACC peripheral
    DACC->DACC_CR = DACC_CR_SWRST;//Reset peripheral
    DACC->DACC_MR = DACC_MR_PRESCALER(8);//Single ended, not max, one data per access 1MHz DAC clock
    DACC->DACC_TRIGR = DACC_TRIGR_TRGEN0_DIS | DACC_TRIGR_OSR0_OSR_1;
    DACC->DACC_ACR = DACC_ACR_IBCTLCH0(3);//Set max conversion rate to 1Ms/s
    DACC->DACC_CHER = DACC_CHER_CH0;//Enable channel 0
    while(!(DACC->DACC_CHSR & DACC_CHSR_DACRDY0));//Wait until channel 0 ready
}

void dac_output(uint16_t value){
    while(!(DACC->DACC_ISR & DACC_ISR_TXRDY0));//Wait until FIFO not full
    DACC->DACC_CDR[0] = value & 0xFFF;
}

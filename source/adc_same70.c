#include "adc_same70.h"
#include "sam.h"                        // Device header

void adc_init(void){
    PMC->PMC_PCER0 = 0x1 << ID_PIOD;// Enable PIOD
    PIOD->PIO_PER = PIO_PD30;// Disable direct control of PD30
    PIOD->PIO_ODR = PIO_PD30;
    PIOD->PIO_PUDR = PIO_PD30;
    
    PMC->PMC_PCER0 = 0x1 << ID_AFEC0;// Enable AFEC0
    AFEC0->AFEC_CR = AFEC_CR_SWRST;// Reset peripheral
    AFEC0->AFEC_MR = (AFEC_MR_PRESCAL(149) |
        AFEC_MR_STARTUP_SUT24|
        AFEC_MR_ONE |
        AFEC_MR_TRACKTIM(15) |
        AFEC_MR_TRANSFER(0) |
        AFEC_MR_USEQ_NUM_ORDER);
    AFEC0->AFEC_EMR = 0;//AFEC_EMR_RES_OSR4 | AFEC_EMR_STM;
    AFEC0->AFEC_COCR = 512;
    AFEC0->AFEC_SEQ1R = 0;
    AFEC0->AFEC_SEQ2R = 0;
    AFEC0->AFEC_CHDR = 0xFFF; 
    AFEC0->AFEC_CHER = AFEC_CHER_CH0;
    AFEC0->AFEC_ACR = AFEC_ACR_PGA0EN | AFEC_ACR_IBCTL(1);
}

uint16_t adc_read(void){
    AFEC0->AFEC_CR = AFEC_CR_START;// Start conversion
    while(!(AFEC0->AFEC_ISR & AFEC_ISR_EOC0));//Wait until complete
    AFEC0->AFEC_CSELR = AFEC_CSELR_CSEL(0);//Select channel 0
    return ((AFEC0->AFEC_CDR >> 0) & 0xFFF);
}


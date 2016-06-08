#include "sam.h"                        // Device header
#include "watchdog_same70.h"
#include "adc_same70.h"

uint16_t adc_value = 0;
int count = 0;

int main(){
    watchdog_disable();
    adc_init();
    while(1){
        adc_value = adc_read();
        count++;
    }
}


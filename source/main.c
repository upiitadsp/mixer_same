#include "watchdog_same70.h"
#include "adc_same70.h"
#include "dac_same70.h"
#include "timer_same70.h"
#include "board.h"

uint16_t adc_value = 0;
int count = 0;

int main(){
    watchdog_disable();
    adc_init();
    dac_init();
    led_init();
    timer0_init(10000);

    led_write(ON);
    
    while(1){
        adc_value = adc_read();
        dac_output(adc_value);
        count++;
    }
}

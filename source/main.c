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
    timer0_init(16000);

    led_write(ON);
    
    while(1){
        adc_value = adc_read();
        dac_output(adc_value);
        count++;
    }
}

int t0_counter = 0;
int last_led_state = 0;
void TC0_callback(){
    t0_counter++;
    if(!(t0_counter < 8000)){
        if(last_led_state){
            led_write(OFF);
            last_led_state = 0;
        }else{
            led_write(ON);
            last_led_state = 1;
        }
        t0_counter = 0;
    }
}

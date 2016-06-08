#ifndef _ADC_SAME70_H
#define _ADC_SAME70_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void adc_init(void);
    
uint16_t adc_read(void);
    
#ifdef __cplusplus
}
#endif

#endif /* _ADC_SAME70_H */


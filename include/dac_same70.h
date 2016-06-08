#ifndef _DAC_SAME70_H
#define _DAC_SAME70_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void dac_init(void);
void dac_output(uint16_t value);

#ifdef __cplusplus
}
#endif

#endif /* _DAC_SAME70_H */

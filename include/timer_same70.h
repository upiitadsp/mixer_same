#ifndef _TIMER_SAME70_H
#define _TIMER_SAME70_H

#ifdef __cplusplus
extern "C" {
#endif

void timer0_init(int period);

void TC0_callback(void);

#ifdef __cplusplus
}
#endif

#endif /* _TIMER_SAME70_H */

#ifndef  _BOARD_H
#define  _BOARD_H

#ifdef __cplusplus
extern "C"{
#endif

#define ON 1
#define OFF 0

#define RELEASED 0
#define PRESSED 1


/**
 * Initializa Led at pin PC8, sets default state as OFF
 */
void led_init(void);

/**
 * Change led state
 *  @param new_state can be either On or Off
 */
void led_write(int);

/**
 * User defined on callback
 */
void button_on_change_handler(void);

/**
 * Initialize the button at PA11, warning this funcion enables interrupts
*/
void button_init(void);

/**
 * Read button state
 *  @return the button state, can be either PRESSED or RELEASED
 */
int button_read(void);

#ifdef __cplusplus
}
#endif

#endif /*_BOARD_H */

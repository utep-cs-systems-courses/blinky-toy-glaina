#ifndef led_included
#define led_included

#include <msp430.h>
/*
#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (LED_RED|LED_GREEN)
*/
void led_init();
void led_on(unsigned char leds);
void led_off(unsigned char leds);
void led_update();

extern unsigned char ledFlags;

#endif

#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char ledFlags = 0;
unsigned char led_state = 0;

void led_init() {
  P1DIR |= LEDS;
  switch_state_changed = 1;
  led_update();
}

void led_on(unsigned char leds) {
  led_state |= leds;
  P1OUT |= leds;
}

void led_off(unsigned char leds) {
  led_state &= ~leds;
  P1OUT &= ~leds;
}

void led_update() {
  if (switch_state_changed) {
    char ledFlags = 0;
    
    ledFlags |= switch_state_down ? LED_GREEN : 0;
    ledFlags |= switch_state_down ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
    /*
    if (switch_state_down & SW1)
      ledFlags |= LED_RED;

    if (switch_state_down & SW2)
      ledFlags |= LED_GREEN;

    if (switch_state_down & SW3)
      ledFlags |= LEDS;
    */
  }
  //P1OUT = (P1OUT & ~LEDS) | ledFlags;
  switch_state_changed = 0;  
}

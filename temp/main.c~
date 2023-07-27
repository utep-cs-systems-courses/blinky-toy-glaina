#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (LED_RED|LED_GREEN)

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1|SW2|SW3|SW4)


void main() {

  
  WDTCTL = WDTPW | WDTHOLD;
  configureClocks();
  switch_init();
  led_init();

  P1DIR |= LEDS;
  P1OUT &= ~LEDS;
  or_sr(0x18);
}

void switch_interrupt_handler() {
  // char p2val = switch_update_interrupt_sense();
  // switch_state_down = (p2val & SWITCHES) ? 0 : 1;
  //switch_state_changed = 1;

  if (P2IFG & SW1) {
    P2IFG &= ~SW1;
    P1DIR |= LEDS;
    P1OUT |= LEDS;
  }
  else if (P2IFG & SW2) {
    P2IFG &= ~SW2;
    P1OUT &= ~LEDS;
  }
}

void __interrupt_vec(PORT2_VECTOR) Port_2() {
  if (P2IFG & SWITCHES) {
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}



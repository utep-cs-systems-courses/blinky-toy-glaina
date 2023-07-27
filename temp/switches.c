#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed;

void switch_init() {
  P2REN |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  P2IE |= SWITCHES;
  P2IES |= SWITCHES;
  P2IFG &= ~SWITCHES;
  switch_state_down = 0;
  switch_state_changed = 0;
}

static char switch_update_interrupt_sense() {
  char p2val = P2IN;

  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}
/*
void switch_interrupt_handler() {
  char p2val = switch_update_interrupt_sense();
  // switch_state_down = (p2val & SWITCHES) ? 0 : 1;
  //switch_state_changed = 1;

  if (P2IFG & SW1) {
    P2IFG &= ~SW1;
    P1OUT |= LEDS;
  }
  else if (P2IFG & SW2) {
    P2IFG &= ~SW2;
    P1OUT &= ~LEDS;
  }
}
*/

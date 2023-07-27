#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

char switch_state_down, switch_state_changed;
/*
static char switch_update_interrupt_sense() {
  // char p2val = P2IN;

  P2IES |= SWITCHES; //(p2val & SWITCHES);
  P2IES &= ~SWITCHES; //(p2val | ~SWITCHES);
  return p2val;
}
*/
void switch_init() {
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
}

unsigned char switch_input() {
  return (P2IN & SWITCHES);
}

void switch_interrupt_handler() {
  char p2val = switch_input(); //switch_update_interrupt_sense();

  if (!(p2val & SW1)) {
    green_on();
    red_off();
  }
  else if (!(p2val & SW2)) {
    red_on();
    green_off();
  }
  else if (!(p2val & SW3)) {
    toggle();
  }
/*
  else if (p2val & SW4 ? 0 : 1) {
    state_advance(4);
  }
*/

  P2IFG &= ~SWITCHES;
}

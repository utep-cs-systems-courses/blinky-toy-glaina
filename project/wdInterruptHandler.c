#include <msp430.h>
#include "stateMachines.h"

void __interrupt_vec(WDT_VECTOR) WDT() {
  static char secondCount = 0;

  if (secondCount >= 250) {
    state_advance(3);
    secondCount = 0;
  }
}

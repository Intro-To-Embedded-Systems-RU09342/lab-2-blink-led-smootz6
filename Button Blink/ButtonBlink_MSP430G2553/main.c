#include <msp430.h>

int main(void) {
    WDTCTL = WDTPW + WDTHOLD;               // Stop watchdog timer
    P1DIR |= BIT0;                          // Set P1.0 to output direction

    while(1) {
        if((P1IN & BIT3) != BIT3) {
            P1OUT |= BIT0;                  // Turn P1.0 on
        } else {
            P1OUT &= ~BIT0;                 // Turn P1.0 off
        }
    }
}

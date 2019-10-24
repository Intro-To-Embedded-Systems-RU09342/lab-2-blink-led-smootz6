#include <msp430.h> 

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // stop watchdog timer

    P1REN |= BIT1;                          // enable pull up
    P1DIR |= BIT0;                          // set P1.0 as an output

    PM5CTL0 &= ~LOCKLPM5;                   // disable the GPIO power-on default high-impedance mode
    while (1) {
        if ((P1IN & BIT1) != BIT1) {
            P1OUT |= BIT0;                  // turn P1.0 on
        } else {
            P1OUT &= ~BIT0;                 // turn P1.0 off
        }
    }
}

#include <msp430.h> 

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // stop watchdog timer
    P1DIR |= BIT0;                          // set outputs
    P9DIR |= BIT7;                          // set outputs

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode

    while(1) {
        P1OUT ^= BIT0;                      // toggle P1.0
        __delay_cycles(100000);
        P1OUT ^= BIT0;                      // toggle P1.0
        __delay_cycles(100000);
        P9OUT ^= BIT7;                      // toggle P9.7
        __delay_cycles(100000);
    }
}

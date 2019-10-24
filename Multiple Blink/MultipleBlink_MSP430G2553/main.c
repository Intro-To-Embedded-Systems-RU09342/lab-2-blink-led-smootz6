#include <msp430.h> 

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // stop watchdog timer
    P1DIR |= BIT0 + BIT6;                   // set outputs

    while(1)
    {
        P1OUT ^= BIT0;                      // toggle P1.0
        __delay_cycles(100000);
        P1OUT ^= BIT0;                      // toggle P1.0
        __delay_cycles(100000);
        P1OUT ^= BIT6;                      // toggle P1.6
        __delay_cycles(100000);
    }
}

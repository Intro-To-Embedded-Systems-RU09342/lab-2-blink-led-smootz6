#include <msp430.h> 

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // stop watchdog timer
    P1DIR |= BIT4 + BIT5;                   // set outputs

    while (1) {
            P1OUT ^= BIT4;                  // toggle output P1.4
            __delay_cycles(100000);
            P1OUT ^= BIT5;                  // toggle output P1.5
            __delay_cycles(100000);
            P1OUT ^= BIT5;                  // toggle output P1.5
            __delay_cycles(100000);
    }
}

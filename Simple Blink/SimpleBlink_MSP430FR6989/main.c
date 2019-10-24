#include <msp430.h> 

int main(void) {
    WDTCTL = WDTPW + WDTHOLD;               // Stop watchdog timer
    P1DIR |= BIT0;                          // Set P1.0 to output direction
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode

    while(1) {
        P1OUT ^= BIT0;                      // Toggle P1.0 using exclusive-OR
        __delay_cycles(100000);             // Delay
    }
}

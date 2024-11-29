#include <msp430.h>
int i;
void ser_output(char *str);
char text[] = "Hello\n\r";

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;


    init_ser();
    while(1){
//        UCA1TXBUF = 'A';
//        for(i = 0; i < 10000; i++){
//
//        }
        ser_output(text);
    }
}
void ser_output(char *str){
    while(*str != 0) {
        while (!(UCA1IFG&UCTXIFG));
        UCA1TXBUF = *str++;
        int i;
        for (i = 0; i < 100; i++){}
    }
}

void init_ser(){
    UCA1CTLW0 |= UCSWRST;                      // Put eUSCI in reset
    UCA1CTLW0 |= UCSSEL__SMCLK;
    UCA1BRW = 8;
    UCA1MCTLW = 0xD600;
    P4SEL1 &= ~BIT3;
    P4SEL0 |= BIT3;

    PM5CTL0 &= ~LOCKLPM5;
    UCA1CTLW0 &= ~UCSWRST;
}

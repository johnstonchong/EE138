/* File: ee138 - lab4t1.c
   Description: PWM Lab
   Group Members: Johnston Chong, Janice Pham, Andrew Vo
*/
#include <avr/io.h>

void timer_init();

int main(void)
{
	DDRD=0b00100000; //set OC1A as output (D.5)
	timer_init();
	while(1){;}
}

void timer_init()
{
	//WGM[13:10] = 1110 for fast PWM & TOP = ICR1 (period width)
	//CS1[12:10] = 001 for 1MHz no prescale
	//COM1A[1:0] = 10 for CLEAR OC1A on match (to OCR1A)
	TCCR1A = 0b10000010;
	TCCR1B = 0b00011001;
	ICR1 = 300; //period time in uS
	OCR1A = 75; //.25*300 = 75 for 25% duty cycle
}

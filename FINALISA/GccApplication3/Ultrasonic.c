#include "Ultrasonic.h"



int ovf = 0;

void ultra_config(void){
	ULTRA_DDR |=(1<<trig); //output
	ULTRA_DDR &= ~(1<<echo); // input
	// PORTB =0xff;
}

void sendEcho()
{
	ULTRA_PORT |=(1<<trig);
	_delay_us(10);
	ULTRA_PORT &=~(1<<trig);

}


double cm_Distance()
{

	//over flow intterupt enable
	TIMSK1 |= (1<<TOIE1);
	TCCR1A = 0 ;



	sendEcho();
	TCNT1 = 0 ;
	//input capture at rising no prescaler
	TCCR1B |=(1<<ICES1)|(1<<CS10);
	//clear capture flag
	TIFR1 |= (1<<ICF1);
	TIFR1 |= (1<<TOV1);
	//wait for rising edge
	while((TIFR1 & (1<<ICF1))==0);
	TCNT1 = 0 ;
	//capture on falling edge
	TCCR1B &=~(1<<ICES1);
	//clear capture flag
	TIFR1 |= (1<<ICF1);
	TIFR1 |= (1<<TOV1);
	ovf=0 ;

	//wait for falling edge
	while((TIFR1 & (1<<ICF1))==0);
	unsigned int cap = (0x0000ffff & ICR1 );


	unsigned long count = cap + 65535*ovf;
	double  distance = (double)count/928;
	//return 0 ;

	return distance;

}


ISR(TIMER1_OVF_vect)
{
	ovf++;

}

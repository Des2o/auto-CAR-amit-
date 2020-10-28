/*
 * GccApplication3.c
 *
 * Created: 28/10/2020 11:37:50 ص
 * Author : Qaiaty_Store
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "car.c"



char l = 0;
char r =0 ;




int main(void)
{
sei();
car_init();

//ultra_config();

  DDRC &= ~((1<<DDC5)|(1<<DDC4));
    /* Replace with your application code */

	while (1) 
    {


	if(cm_Distance()>10)
	{
		char f = ((PINC & 0b00110000)>>4);
		_delay_ms(100);
		if(f !=((PINC & 0b00110000)>>4) )f=0;
		if(f==0)carForward(150);
		else
		{
			Brake();
			_delay_ms(1000);
			if(f==3)
			{
				carReverse(150);
				_delay_ms(1000);
			}
			if(f==2)
			{
				carRightF();
				_delay_ms(700);
				
			}
			if(f==1)
			{
				carLeftF();
				_delay_ms(700);
			}
			
		}
		
	}
	else
	{
		char f = ((PINC & 0b00110000)>>4);
		_delay_ms(100);
		if(f !=((PINC & 0b00110000)>>4) )f=0;
		Brake();
		_delay_ms(1000);
		if(f==1)
		{
			carLeftB();
			_delay_ms(700);
		}
		if(f==2)
		{
			carRightB();
			_delay_ms(700);
		}
		else
		{
			carReverse(150);
		    _delay_ms(500);
			carRightB();
			_delay_ms(700);
			
		}
	}
/*Brake();
_delay_ms(1000);
 carForward(180);
_delay_ms(1000);
carReverse(180);
_delay_ms(1000);
carLeftF();
_delay_ms(700);
carRightF();
_delay_ms(700);
carLeftB();
_delay_ms(700);
carRightB();
_delay_ms(700);*/
	

	
		}
		
			
		
    
}

/*void IR_config(void)
{
	EICRA |= (1<<ISC11)|(1<<ISC01);
	DDRD &=~((1<< PORTD2)|(1<< PORTD3));
	EIMSK |=(1<<INT1)|(1<<INT0);
	
	
}

ISR(INT0_vect)
{
	l = 1;
}
ISR(INT1_vect)
{
	carRight();
	_delay_ms(3000);
	
}*/
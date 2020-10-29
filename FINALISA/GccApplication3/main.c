/*
 * GccApplication3.c
 *
 * Created: 28/10/2020 11:37:50 ص
 * Author : Qaiaty_Store
 */ 
#define F_CPU 8000000UL
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
//double us =0;
	while (1) 
    {
		//sampling for real hardware
/*for(int i =0 ;i<20;i++)
{
	us += cm_Distance();
}
us /=20 ;*/
	if(cm_Distance()>15.0)
	{
		
		char f = ((PINC & 0b00110000)>>4);
		/*debounce
		_delay_ms(20);
		if(f !=((PINC & 0b00110000)>>4) )f=0;*/
	
	
	//in track w  mafe4 obstacles
		if(f==0)carForward(150);
		else
		{
			Brake();
			//_delay_ms(1000);
			if(f==3)
			{
				carReverse(150);
				//_delay_ms(1000);
			}
			//Track border left
			if(f==2)
			{
				carRightF();
				//_delay_ms(700);
				
			}
			//track border right
			if(f==1)
			{
				carLeftF();
				//_delay_ms(700);
			}
			
		}
		
	}
	else
	{
		char f = ((PINC & 0b00110000)>>4);
		//debounce
		//_delay_ms(20);
		//if(f !=((PINC & 0b00110000)>>4) )f=0;
		Brake();
		//_delay_ms(1000);
		//obstacle + track border right
		if(f==1)
		{
			carLeftB();
			//_delay_ms(700);
		}
		//obstacle + track border left
		if(f==2)
		{
			carRightB();
			//_delay_ms(700);
		}
		//obstacle in track
		else
		{
			carReverse(150);
		    //_delay_ms(500);
			
			
			carRightB();
			//_delay_ms(700);
			
		}
	}
	
	//testing
/*Brake();
_delay_ms(1000);
 carForward(250);
_delay_ms(1000);
carReverse(250);
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
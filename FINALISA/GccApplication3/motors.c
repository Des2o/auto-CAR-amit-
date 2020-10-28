#include "motors.h"

char motor1_direction =forward;
char motor2_direction = forward;

void motors_init()
{
	TCCR0A |=(1<<COM0A1)|(1<<COM0B1)|(1<<WGM00)|(1<<WGM01);
	TCCR0B |=(1<<CS00);
	//motor1 
	DDRD |= (1<<EN1);
	MOTOR1_DDR |=(1<<IN1)|(1<<IN2);
	motor1_forward();
	motor1_speed(0);
	//motor2
	DDRD |= 1<<EN2 ;
	MOTOR2_DDR |= (1<<IN3)|(1<<IN4);
	motor2_forward();
	motor2_speed(0);
	
}



/*void motor1_init()
{
	TCCR2 |=(1<<WGM21)|(1<<WGM20)|(1<<COM21)|(1<<CS21);
	DDRD |= (1<<EN1);
	MOTOR1_DDR |=(1<<IN1)|(1<<IN2);
	motor1_forward();
	motor1_speed(0);
}*/

void motor1_speed(char s1)
{
	OCR0A = s1;
}

void motor1_forward(void)
{
	if(motor1_direction != forward)
	{
		motor1_stop();
		motor1_direction = forward ;
	}
	MOTOR1_PORT |=(1<<IN2);
	MOTOR1_PORT &= ~(1<<IN1);
}

void motor1_stop()
{
	MOTOR1_PORT &= ~(1<<IN1);
	MOTOR1_PORT &= ~(1<<IN2);
	motor1_speed(0);
	
}
void motor1_backward(void)
{
	if(motor1_direction != backward)
	{
		motor1_stop();
		motor1_direction = backward ;
	}
	MOTOR1_PORT |=(1<<IN1);
	MOTOR1_PORT &= ~(1<<IN2);
	
}

/////////////////////////////////////////////
void motor2_speed(char s2)
{
	OCR0B = s2;
}

/*void motor2_init(void)
{
	TCCR0 =(1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS00);
	MOTOR2_DDR |= 1<<EN2 ;
	MOTOR2_DDR |= (1<<IN3)|(1<<IN4);
	motor2_forward();
	motor2_speed(0);
}*/

void motor2_forward(void)
{
	if(motor2_direction != forward)
	{
		motor2_stop();
		motor2_direction = forward ;
	}
	MOTOR2_PORT |=(1<<IN4);
	MOTOR2_PORT &= ~(1<<IN3);
	
}
void motor2_stop()
{
	MOTOR2_PORT &= ~(1<<IN3);
	MOTOR2_PORT &= ~(1<<IN4);
	motor2_speed(0);
	
}
void motor2_backward(void)
{
	if(motor2_direction != backward)
	{
		motor2_stop();
		motor2_direction = backward ;
		
	}
	MOTOR2_PORT |=(1<<IN3);
	MOTOR2_PORT &= ~(1<<IN4);
	
}

///////////////////////////////////////////////////////////
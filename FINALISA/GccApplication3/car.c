#include "car.h"
#include "motors.c"
#include "Ultrasonic.c"


car_Direction Dir = F;

void car_init(void)
{
	//config IR interrupts
	
	ultra_config();
	motors_init();
	
	
}

void carForward(char s)
{
	if(Dir != F)
	{
		Brake() ;
		motor1_forward();
		motor2_forward();
		
	}
        motor1_speed(s);
		motor2_speed(s);
	Dir = F ;
}

void carReverse(char s)
{
	
	if(Dir != B)
	{
		
		Brake();
		motor1_backward();
		motor2_backward();
		
}
		motor1_speed(s);
		motor2_speed(s);
		Dir = B;
		
}

void carRightF(void)
{
	if(Dir != FR)
	{
		
		Brake();
		motor2_forward();
		motor1_stop();
		motor2_speed(135);
		
	}
	Dir=FR;
	
	
}

void carRightB(void)
{
	if(Dir != BR)
	{
		
		Brake();
		motor2_backward();
		motor1_stop();
		motor2_speed(135);
		
	}
	Dir=BR;
	
	
}

void carLeftF(void)
{
	if(Dir != FL)
	{
		Brake();
	motor1_forward();
	motor2_stop();
	motor1_speed(150);
	}
	Dir = FL ;
}

void carLeftB(void)
{
	if(Dir != BL)
	{
		Brake();
		motor1_backward();
		motor2_stop();
		motor1_speed(150);
	}
	Dir = BL ;
}
void Brake(void)
{
	Dir = S ;
motor1_stop();
motor2_stop();	
}
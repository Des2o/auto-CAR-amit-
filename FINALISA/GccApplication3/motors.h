#ifndef MOTORS_H_INCLUDED
#define MOTORS_H_INCULDED

#define forward 1
#define backward 0

#define MOTOR1_PORT PORTC
#define MOTOR1_DDR  DDRC
#define EN1 PORTD6
#define IN1 PORTC0
#define IN2 PORTC1

#define MOTOR2_PORT PORTC
#define MOTOR2_DDR DDRC
#define EN2 PORTD5
#define IN3 PORTC2
#define IN4 PORTC3


void motors_init(void);


void motor1_speed(char);
void motor1_forward(void);
void motor1_backward(void);
void motor1_stop(void);




void motor2_speed(char);
void motor2_forward(void);
void motor2_backward(void);
void motor2_stop(void);

#endif
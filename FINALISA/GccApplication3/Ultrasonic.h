#ifndef ULTRASONIC_H_INCLUDED
#define ULTRASONIC_H_INCLUDED

#define ULTRA_PORT PORTB
#define ULTRA_PIN  PINB
#define ULTRA_DDR  DDRB

#define trig PORTB1
#define echo PORTB0


void ultra_config(void);

void sendEcho(void);

double cm_Distance(void);




#endif // MYULTRASONIC_H_INCLUDED
#ifndef CAR_H_INCLUDED 
#define CAR_H_INCLUDED 

typedef enum  {B,F,FL,FR,BL,BR,S}car_Direction; 

#include "motors.h"

void Brake(void);
void car_init(void);
void carForward(char );
void carReverse(char);
void carLeftF(void);
void carRightF(void);
void carLeftB(void);
void carRightB(void);



#endif
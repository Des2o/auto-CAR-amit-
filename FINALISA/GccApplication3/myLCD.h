#ifndef MYLCD_H_INCLUDED
#define MYLCD_H_INCLUDED

#include <stdbool.h>

#define ClearDisplay 0x01
#define ReturnHome 0x02






void lcd_init(void);

void send_cmd(unsigned char command) ;

void send_cmd4(unsigned char command);

void send_char(unsigned char);

void setDisplay (bool,bool,bool);

void send_String(char[],int l);







#endif // MYLCD_H_INCLUDED

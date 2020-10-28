#include "myLCD.h"

#define E_H PORTD |=(1<<PORTD3);
#define E_L PORTD &=~(1<<PORTD3);

//#define Read PORTB |= (1<<2);
#define Write PORTB &=~(1<<2);

#define DR PORTD |= (1<<PORTD2);
#define IR PORTD &= ~(1<<PORTD2);

#define Data PORTD
#define LCD_PORT PORTD
#define LCD_DDR  DDRD
#define LCD_PIN PIND









void lcd_init(void){

LCD_DDR |= 0xf0;
//DDRB |= (1<<1)|(1<<2)|(1<<3);
DDRD |= (1<<DDD3)|(1<<DDD2);
////////////
_delay_ms(20);
//PORTD = 0x30;
LCD_PORT |= (0xf0 & 0x30);
LCD_PORT &=(0x0f | 0x30);
IR
Write
E_H

_delay_ms(5);

E_L
//PORTD = 0x30;

LCD_PORT |= (0xf0 & 0x30);
LCD_PORT &=(0x0f | 0x30);


E_H
_delay_us(150);
E_L

//PORTD = 0x30;
LCD_PORT |= (0xf0 & 0x30);
LCD_PORT &=(0x0f | 0x30);



E_H
_delay_ms(1);
E_L

//PORTD = 0x20;
LCD_PORT |= (0xf0 & 0x20);
LCD_PORT &=(0x0f | 0x20);

E_H
_delay_ms(1);
E_L

////////////
/*send_cmd4(0b00101100);
send_cmd4(0x08);
send_cmd4(0x01);
send_cmd4(0x06);
send_cmd4(0x80);*/
//send_cmd4(0x33);
//send_cmd4(0x32);
send_cmd4(0x28);
send_cmd4(0x0c);
send_cmd4(0x06);
send_cmd4(0x01);


}

void send_cmd4(unsigned char command)
{
//First half
    IR
    Write
    //Data =command ;
    Data |= (0xf0 & command);
    Data &= (0x0f | command);
    _delay_ms(1);
    E_H
    _delay_ms(1);
    E_L
     _delay_ms(1);
//Second half
    //Data = command <<4 ;
    Data |= (0xf0 & (command<<4));
    Data &= (0x0f | (command<<4));
    _delay_ms(3);
    E_H
    _delay_ms(1);
    E_L
     _delay_ms(3);

}

void send_char(unsigned char c)
{
    //Data = c ;
    Data |= (0xf0 & c);
    Data &= (0x0f | c);
    DR
    Write
    _delay_ms(1);
    E_H
    _delay_ms(1);
    E_L
    _delay_ms(1);

    //Data = c<<4;
    Data |= (0xf0 & (c<<4));
    Data &= (0x0f | (c<<4));

    _delay_ms(1);
    E_H
    _delay_ms(1);
    E_L
    _delay_ms(1);
}


void setDisplay (bool D,bool C,bool B)
{
    char cmd = 0b00001000 |(D<<2)|(C<<1)|(B<<0);
    send_cmd4(cmd);

}

void send_String(char s[] ,int l )
{
    int i;
    for(i=0 ;i<l ;i++)
    {
        send_char(s[i]);
    }

}

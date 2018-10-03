/*
 */

#define F_CPU 16000000
#include <avr/io.h>
#include "n5110.h"


void presets()
{
    DDRC = 0;
    PORTC = 0;

    Lcd_init();
    Lcd_clear();
    Lcd_update();
}


int main(void)
{
    presets();
        int yp = 2;
        unsigned char p_up = 0, p_dw = 0;


    while(1)
    {
        if(PINC&1)
        {
            if(!p_up)
            {
                p_up = 1;
                yp--;
            }
        }
        else p_up = 0;
       if(PINC&2)
        {
            if(!p_dw)
            {
                p_dw = 1;
                yp++;
            }
        }
        else p_dw = 0;
        if(yp<0) yp = 0;
        if(yp>5) yp = 5;

        Lcd_clear();
        LcdGotoXY(0,yp);
        LcdChr(FONT_1X,'>');
        Lcd_update();
    }
}

// x = ( a>b?A:B);

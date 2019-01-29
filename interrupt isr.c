
#include <pic16f1459.h>
#include "config.h"
#include "main.h"
#include "clear_OLED.h"
#include "OLED_write.h"
#include "set_page_address.h"
#include "set_columns.h"
#include "match_digit.h"
#include "split_time.h"
#include <stdio.h>

void interrupt isr (void)
{
    uchar x;
    
    if(INTCONbits.TMR0IF == 1)
    {
       // if(overflow >=123)      // 2 sec refresh of sensor reading
        if(overflow >=62)
        {
            //read the sensor data
            if(seconds > 59)
            {
                seconds = 0;
                minutes = minutes + 1;
            }
    
    
            if (minutes > 59)
            {
                seconds = 0;
                minutes = 0;
                hours  = hours + 1;
            }
            if (hours > 23)
            {
                seconds = 0;
                minutes = 0;
                hours = 0;
            }
            split_time(seconds);
            
            
            set_columns(0x21, 0x3f, 0x47);
            match_digit(hours_msb);
            set_columns(0x21, 0x48, 0x50);
            match_digit(hours_lsb);
            set_columns(0x21, 0x51, 0x59);
            match_digit(mins_msb);
            set_columns(0x21, 0x5a, 0x62);
            match_digit(mins_lsb);
            set_columns(0x21, 0x67, 0x6f);
            match_digit(secs_msb);
            set_columns(0x21, 0x70, 0x78);
            match_digit(secs_lsb);
            
            seconds = seconds + 1;
            PORTCbits.RC7 = ~PORTCbits.RC7;
            overflow = 0;
        }
        overflow++;
        INTCONbits.TMR0IF = 0;
    }
}

/*
 * File:   main.c
 * Author: Phil Glazzard
 *
 * Created on 25 January 2019, 20:52
 */


#include <xc.h>
#include "config_osc.h"
#include "setup_ports.h"
#include "config_TMR0.h"
#include "config_usart.h"
#include "i2c_start.h"
#include "i2c_write.h"
#include "i2c_stop.h"
#include "OLED_write.h"
#include "config_i2c.h"
#include "set_page_address.h"
#include "set_columns.h"
#include "config_OLED.h"
#include "clear_OLED.h"
#include <stdio.h>
#include "split_time.h"
void main(void) 
{
    unsigned int result = 2359;
  
    uchar x;
    config_osc();
    setup_ports();
    config_TMR0();
    config_usart();
    config_i2c();
    config_OLED();
    clear_OLED();
    set_page_address(0x78, 0x00, 0x03);
    
    set_columns(0x21, 0x0b, 0x13);
    for(x = 0; x < 8; x++)
    {
       OLED_write(OLED_ADDR, 0x40,t[x]) ;
    }
    
    set_columns(0x21, 0x14, 0x1c);
    for(x = 0; x < 8; x++)
    {
       OLED_write(OLED_ADDR, 0x40,i[x]);
    }
    
    set_columns(0x21, 0x1d, 0x25);
    for(x = 0; x < 8; x++)
    {
       OLED_write(OLED_ADDR, 0x40,m[x]);
    }
    
   
    set_columns(0x21, 0x26, 0x2e);
    for(x = 0; x < 8; x++)
    {
       OLED_write(OLED_ADDR, 0x40,e[x]);
    }
    
    printf("hello!\n");
    split_time(seconds);
   // printf("thous = %d, huns = %d, tens = %d, units = %d\n", thous, huns, tens, units);
    while(1)
    {
            
    }       
         
}

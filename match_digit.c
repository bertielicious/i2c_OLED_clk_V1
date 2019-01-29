#include "config.h"
#include "OLED_write.h"
void match_digit(uchar num)
{
    uchar x;
    switch (num)
            {
                case 0:
                    
                    ptr = &zero[0];
                    for (x = 0; x < 8; x++)
                    {
                        OLED_write(OLED_ADDR, 0x40,*ptr);
                        ptr++;
                    }
                    break;
                    
                case 1:
                    ptr = &one[0];
                    for (x = 0; x < 8; x++)
                    {
                        OLED_write(OLED_ADDR, 0x40,*ptr);
                        ptr++;
                    }
                    break;
                    
                case 2:
                    ptr = &two[0];
                    for (x = 0; x < 8; x++)
                    {
                        OLED_write(OLED_ADDR, 0x40,*ptr);
                        ptr++;
                    }
                    break;
                    
                case 3:
                    ptr = &three[0];
                    for (x = 0; x < 8; x++)
                    {
                        OLED_write(OLED_ADDR, 0x40,*ptr);
                        ptr++;
                    }
                    break;
                    
                case 4:
                    ptr = &four[0];
                    for (x = 0; x < 8; x++)
                    {
                        OLED_write(OLED_ADDR, 0x40,*ptr);
                        ptr++;
                    }
                    break;
                    
                case 5:
                    ptr = &five[0];
                    for (x = 0; x < 8; x++)
                    {
                        OLED_write(OLED_ADDR, 0x40,*ptr);
                        ptr++;
                    }
                    break;
                    
                    case 6:
                    ptr = &six[0];
                    for (x = 0; x < 8; x++)
                    {
                        OLED_write(OLED_ADDR, 0x40,*ptr);
                        ptr++;
                    }
                    break; 
                    
                    case 7:
                    ptr = &seven[0];
                    for (x = 0; x < 8; x++)
                    {
                        OLED_write(OLED_ADDR, 0x40,*ptr);
                        ptr++;
                    }
                    break; 
                    
                    case 8:
                    ptr = &eight[0];
                    for (x = 0; x < 8; x++)
                    {
                        OLED_write(OLED_ADDR, 0x40,*ptr);
                        ptr++;
                    }
                    break; 
                    
                    case 9:
                    ptr = &nine[0];
                    for (x = 0; x < 8; x++)
                    {
                        OLED_write(OLED_ADDR, 0x40,*ptr);
                        ptr++;
                    }
                    break; 
                    
                    default:
                    seconds = 0;
                    break; 
                }
}

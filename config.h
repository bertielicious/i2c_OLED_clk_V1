/* 
 * File:   config.h
 * Author: Phil Glazzard
 *
 * Created on 25 January 2019, 20:49
 */

#ifndef CONFIG_H
#define	CONFIG_H

// PIC16F1459 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover Mode (Internal/External Switchover Mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config CPUDIV = CLKDIV6 // CPU System Clock Selection Bit (CPU system clock divided by 6)
#pragma config USBLSCLK = 48MHz // USB Low SPeed Clock Selection bit (System clock expects 48 MHz, FS/LS USB CLKENs divide-by is set to 8.)
#pragma config PLLMULT = 3x     // PLL Multipler Selection Bit (3x Output Frequency Selected)
#pragma config PLLEN = ENABLED  // PLL Enable Bit (3x or 4x PLL Enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
typedef unsigned char uchar;
#define _XTAL_FREQ 16000000         //16 MHz clock
#define SDA PORTBbits.RB4       // pin 13   Serial DAta
#define SCL PORTBbits.RB6       // pin 11   Serial CLock
/*Global variables*/
uchar overflow = 0;
uchar *ptr = 0;
volatile uchar old_counter= 0;
volatile unsigned int seconds = 0;
uchar minutes, hours,secs_lsb, secs_msb, mins_lsb, mins_msb, hours_lsb, hours_msb  = 0;
const uchar zero[8] = {0x00,0x7e,0x81,0x81,0x81,0x7a,0x00,0x00};
const uchar one[8] = {0x84,0x84,0x82,0xff,0x80,0x80,0x80,0x00};
const uchar two[8] = {0x00,0x00,0xc6,0xa1,0x91,0x8a,0x84,0x00};
const uchar three[8] = {0x00,0x00,0x41,0x89,0x95,0x73,0x00,0x00};
const uchar four[8] = {0x00,0x30,0x28,0x24,0x22,0xf9,0x20,0x00};
const uchar five[8] = {0x00,0x00,0x5f,0x91,0x89,0x49,0x31,0x00};
const uchar six[8] = {0x00,0x38,0x54,0x8a,0x89,0x70,0x00,0x00};
const uchar seven[8] = {0x00,0x03,0xe1,0x11,0x09,0x05,0x03,0x00};
const uchar eight[8] = {0x20,0x56,0x89,0x89,0x89,0x56,0x20,0x00};
const uchar nine[8] = {0x00,0x06,0x89,0x49,0x29,0x11,0x0e,0x00};

const uchar t[8] = {0x00,0x04,0x04,0x7f,0x84,0x84,0x84,0x00};
const uchar i[8] = {0x00,0x00,0x00,0x00,0x7d,0x80,0x00,0x00};
const uchar m[8] = {0x00,0xf0,0x08,0x04,0x78,0x04,0x08,0xf0};
const uchar e[8] = {0x00,0x00,0x03c,0x52,0x92,0x92,0x92,0x0c};
/*OLED display parameters*/
#define OLED_ADDR 0x78


#define SSD1306_128_64
#define SSD1306_LCDWIDTH  128
#define SSD1306_LCDHEIGHT  64

#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETMULTIPLEX 0xA8
#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETSTARTLINE 0x40
#define SSD1306_CHARGEPUMP 0x8D

#define SSD1306_SETSEGMENTREMAP 0xA0
#define SSD1306_SEGREMAP 0xA0

#define SSD1306_COMSCANDEC 0xC8
#define SSD1306_SETCOMPINS 0xDA
#define SSD1306_SETCONTRAST 0x81
#define SSD1306_SETPRECHARGE 0xD9
#define SSD1306_SETVCOMDETECT 0xDB
#define SSD1306_DISPLAYALLON_RESUME 0xA4    // output follows RAM contents
#define SSD1306_NORMALDISPLAY 0xA6          // white on black or black on white
#define SSD1306_DISPLAYON 0xAF

#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_INVERTDISPLAY 0xA6
#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10
#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22
#define SSD1306_COMSCANINC 0xC0
#define SSD1306_SEGREMAP 0xA0
#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A
#define SSD1306_SET_COM_OUTPUT_SCAN_DIRECTION 0xA0

#endif	/* CONFIG_H */


#include <../LIB/STD_TYPES.h>
#include <../LIB/UTILIS.h>


#include <DIO/DIO_Interface.h>
#include <DIO/DIO_Private.h>

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


#define PORT_DATA       PORTA
#define PORT_CONTROL    PORTB 

#define RS              PIN1
#define RW              PIN2
#define EN              PIN3

/*Macro to initialize LCD*/
#define FNSET           0x80
#define ZERO            0x00
#define ONE             0x01
#define INIT_VAL        0x20
#define DIS_MODE        0xc0
#define DIS_CLR         0x10
#define ENT_MODE        0x60


#define LCD_GoTo_CMD    0x80

/*  Functions to Send Command  */
/*  Functions to Write Data     */


void LCD_Init(void);

void LCD_voidWriteData      (u8 copy_u8Data);

void LCD_voidSendCMD        (u8 copy_u8CMD);

void LCD_voidWriteString    (u8* copy_pu8String);

void LCD_cycle(void);

void LCD_GoTo(u8 Raw, u8 Col);







#endif
#include <../LIB/STD_TYPES.h>
#include <UTILIS.h>

#include <DIO/DIO_Interface.h>
#include <DIO/DIO_Private.h>
#include <util/delay.h>
#include "LCD/LCD_Interface.h"

u8 LCD_Curser_Tracer=0;
void LCD_Init(void)
{
    DIO_voidSetPinDir(PORT_CONTROL,RS,OUTPUT);
    DIO_voidSetPinDir(PORT_CONTROL,RW,OUTPUT);
    DIO_voidSetPinDir(PORT_CONTROL,EN,OUTPUT);

    // DIO_voidSetPortDir(PORT_DATA,OUTPUT);
    DIO_voidSetPinDir(PORTA,PIN4,OUTPUT);
    DIO_voidSetPinDir(PORTA,PIN5,OUTPUT);
    DIO_voidSetPinDir(PORTA,PIN6,OUTPUT);
    DIO_voidSetPinDir(PORTA,PIN7,OUTPUT);

  

    /*Delay for 30 ms*/
    _delay_ms(100);

    /*Function Set*/
    LCD_voidSendCMD(0b00100010);        
    // LCD_voidSendCMD(0b10000000);       // N= 1 F= 0 
    DIO_voidSetPinValue(PORTD,PIN7,HIGH);
    DIO_voidSetPinValue(PORTD,PIN6,LOW);
    /*Delay for 30 ms*/
    LCD_cycle();

    /*Display ON/OFF Control*/
    LCD_voidSendCMD(0b00001111);
    // LCD_voidSendCMD(0b11110000);

    /*Delay for 30 ms*/
    _delay_ms(2);

    /*Display Clear*/
    LCD_voidSendCMD(0b00000001);
    // LCD_voidSendCMD(0b00010000);

    /*Delay for 30 ms*/
    _delay_ms(2);

    /*Entry Mode Set*/
    LCD_voidSendCMD(0b00000110);
    // LCD_voidSendCMD(0b01100000);


}




void LCD_voidWriteData (u8 copy_u8Data)
{
    DIO_voidSetPinValue(PORT_CONTROL,RS,HIGH);
    DIO_voidSetPinValue(PORT_CONTROL,RW,LOW);

    // DIO_voidSetPortValue(PORT_DATA,copy_u8Data);
    DIO_voidSetPinValue(PORTA,PIN4,GET_BIT(copy_u8Data,4));
    DIO_voidSetPinValue(PORTA,PIN5,GET_BIT(copy_u8Data,5));
    DIO_voidSetPinValue(PORTA,PIN6,GET_BIT(copy_u8Data,6));
    DIO_voidSetPinValue(PORTA,PIN7,GET_BIT(copy_u8Data,7));


    /*Latching Enable*/
    LCD_cycle();

    DIO_voidSetPinValue(PORTA,PIN4,GET_BIT(copy_u8Data,0));
    DIO_voidSetPinValue(PORTA,PIN5,GET_BIT(copy_u8Data,1));
    DIO_voidSetPinValue(PORTA,PIN6,GET_BIT(copy_u8Data,2));
    DIO_voidSetPinValue(PORTA,PIN7,GET_BIT(copy_u8Data,3));

    LCD_cycle();
    LCD_Curser_Tracer++;
    if (LCD_Curser_Tracer == 16)
    {
        LCD_GoTo(1,0);
    }
    
}


void LCD_voidSendCMD   (u8 copy_u8CMD)
{
    DIO_voidSetPinValue(PORT_CONTROL,RS,LOW);
    DIO_voidSetPinValue(PORT_CONTROL,RW,LOW);

    // DIO_voidSetPortValue(PORT_DATA,copy_u8CMD);
    DIO_voidSetPinValue(PORTA,PIN4,GET_BIT(copy_u8CMD,4));
    DIO_voidSetPinValue(PORTA,PIN5,GET_BIT(copy_u8CMD,5));
    DIO_voidSetPinValue(PORTA,PIN6,GET_BIT(copy_u8CMD,6));
    DIO_voidSetPinValue(PORTA,PIN7,GET_BIT(copy_u8CMD,7));

    LCD_cycle();

    DIO_voidSetPinValue(PORTA,PIN4,GET_BIT(copy_u8CMD,0));
    DIO_voidSetPinValue(PORTA,PIN5,GET_BIT(copy_u8CMD,1));
    DIO_voidSetPinValue(PORTA,PIN6,GET_BIT(copy_u8CMD,2));
    DIO_voidSetPinValue(PORTA,PIN7,GET_BIT(copy_u8CMD,3));

    /*Latching Enable*/
    LCD_cycle();

    _delay_ms(2);


    
}


void LCD_voidWriteString    (u8* copy_pu8String)
{
    while (*copy_pu8String != '\0')
    {
        LCD_voidWriteData (*copy_pu8String);
        copy_pu8String ++;
    }
    




}


void LCD_cycle(void)
{
    DIO_voidSetPinValue(PORT_CONTROL,EN,HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(PORT_CONTROL,EN,LOW);
    _delay_ms(2);


}



void LCD_GoTo(u8 Raw,u8 Col)
{
    LCD_voidSendCMD(LCD_GoTo_CMD + (Raw*64 + Col) );
    LCD_Curser_Tracer = Raw*16 +Col;
}
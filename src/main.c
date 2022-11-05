#include <../LIB/UTILIS.h>
#include <../LIB/STD_TYPES.h>
#include <DIO/DIO_Interface.h>
#include <DIO/DIO_Private.h>
#include <Keypad/keypad_Interface.h>
#include <LCD/LCD_Interface.h>
#include <DIO/Interupt/EXT_INT0_Interface.h>
#include <DIO/Interupt/EXT_INT0_Private.h>
#include <DIO/Interupt/GIE_Interface.h>
#include <util/delay.h>
#include <DIO/ADC/ADC_Interface.h>
#include <DIO/ADC/ADC_Private.h>



int main()
{
    u16 READING=0;
    
    
    ADC_INIT();
    ADC_EN();

    DIO_voidSetPinDir(PORTA,PIN1,INPUT);
    DIO_voidSetPinDir(PORTC,PIN7,OUTPUT);
    // DIO_voidSetPinDir(PORTC,PIN7,OUTPUT);
    // DIO_voidSetPinDir(PORTC,PIN7,OUTPUT);
    while (1)
    {
        READING = ADC_Read(PIN1);
        if (READING>=0 && READING<=50)
        {
            DIO_voidSetPinValue(PORTC,PIN7,LOW);
        }
        if (READING>=51 && READING<=400)
        {
            DIO_voidSetPinValue(PORTC,PIN7,HIGH);
        }
    }
    
    
    

}
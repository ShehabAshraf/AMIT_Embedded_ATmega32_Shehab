#include <../LIB/UTILIS.h>
#include <../LIB/STD_TYPES.h>
#include <DIO/DIO_Interface.h>
#include <DIO/DIO_Private.h>
#include <util/delay.h>
int main()
{
    DIO_voidSetPinDir(PORTB,PIN0,INPUT);
    DIO_voidSetPinValue(PORTB,PIN0,HIGH);

    DIO_voidSetPinDir(PORTA,PIN2,OUTPUT);

    DIO_voidSetPinValue(PORTA,PIN2,LOW);

    while (1)
    {
        u8 switch_1=DIO_u8GetPinValue(PORTA,PIN3);
        _delay_ms(5);

        if (switch_1== HIGH)
        {
            DIO_voidSetPinValue(PORTD,PIN3,HIGH);
        }
        else if (switch_1== LOW)
        {
            DIO_voidSetPinValue(PORTD,PIN3,LOW);
        }
        
          
    }
    
}
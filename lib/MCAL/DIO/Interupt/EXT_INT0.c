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
#define TOG_BIT(REG,Bit_No) (REG ^=  (1<<Bit_No))

// void __vector_1(void);


void ISR_TGL_LED()
{
    GIE_voidEnable();
    EXT_INT0_voidEnable();
    
    TOG_BIT(REG_PORTC,PIN2);
    

}



int main()
{

    GIE_voidEnable();
    EXT_INT0_voidINIT();
    EXT_INT0_voidEnable();


    DIO_voidSetPinDir(PORTC,PIN2,OUTPUT);
    DIO_voidSetPinDir(PORTD,PIN2,INPUT);
    DIO_voidSetPinValue(PORTC,PIN2,HIGH);

    EXT_INT0_CallBackFunction(ISR_TGL_LED);
    while (1)
    {
        
    }
    

}
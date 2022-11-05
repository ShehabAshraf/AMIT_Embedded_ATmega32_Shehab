#include <Keypad/keypad_Interface.h>






void Keypad_INIT(void)
{
    /*ROWs Inputs*/
    DIO_voidSetPinDir(Keypad_R0,INPUT_PULL_UP);
    DIO_voidSetPinDir(Keypad_R1,INPUT_PULL_UP);
    DIO_voidSetPinDir(Keypad_R2,INPUT_PULL_UP);
    DIO_voidSetPinDir(Keypad_R3,INPUT_PULL_UP);
    /*COLs Outputs*/
    DIO_voidSetPinDir(Keypad_C0,OUTPUT);
    DIO_voidSetPinDir(Keypad_C1,OUTPUT);
    DIO_voidSetPinDir(Keypad_C2,OUTPUT);
    DIO_voidSetPinDir(Keypad_C3,OUTPUT);

    /*Make All High*/
    DIO_voidSetPinDir(Keypad_C0,HIGH);
    DIO_voidSetPinDir(Keypad_C1,HIGH);
    DIO_voidSetPinDir(Keypad_C2,HIGH);
    DIO_voidSetPinDir(Keypad_C3,HIGH);

}

u8 Keypad_u8GetKeyPress(void)
{
    u8 Reading=0;
    DIO_voidSetPinValue(Keypad_C0,LOW);     _delay_ms(5);
    if (DIO_u8GetPinValue(Keypad_R0) == LOW)   {Reading='1';}
    if (DIO_u8GetPinValue(Keypad_R1) == LOW)   {Reading='4';}
    if (DIO_u8GetPinValue(Keypad_R2) == LOW)   {Reading='7';}
    if (DIO_u8GetPinValue(Keypad_R3) == LOW)   {Reading='*';}
    DIO_voidSetPinValue(Keypad_C0,HIGH);

    DIO_voidSetPinValue(Keypad_C1,LOW);     _delay_ms(5);
    if (DIO_u8GetPinValue(Keypad_R0) == LOW)   {Reading='2';}
    if (DIO_u8GetPinValue(Keypad_R1) == LOW)   {Reading='5';}
    if (DIO_u8GetPinValue(Keypad_R2) == LOW)   {Reading='8';}
    if (DIO_u8GetPinValue(Keypad_R3) == LOW)   {Reading='0';}
    DIO_voidSetPinValue(Keypad_C1,HIGH);

    DIO_voidSetPinValue(Keypad_C2,LOW);     _delay_ms(5);
    if (DIO_u8GetPinValue(Keypad_R0) == LOW)   {Reading='3';}
    if (DIO_u8GetPinValue(Keypad_R1) == LOW)   {Reading='6';}
    if (DIO_u8GetPinValue(Keypad_R2) == LOW)   {Reading='9';}
    if (DIO_u8GetPinValue(Keypad_R3) == LOW)   {Reading='#';}
    DIO_voidSetPinValue(Keypad_C2,HIGH);

    DIO_voidSetPinValue(Keypad_C3,LOW);     _delay_ms(5);
    if (DIO_u8GetPinValue(Keypad_R0) == LOW)   {Reading='A';}
    if (DIO_u8GetPinValue(Keypad_R1) == LOW)   {Reading='B';}
    if (DIO_u8GetPinValue(Keypad_R2) == LOW)   {Reading='C';}
    if (DIO_u8GetPinValue(Keypad_R3) == LOW)   {Reading='D';}
    DIO_voidSetPinValue(Keypad_C3,HIGH);


    return Reading;
}

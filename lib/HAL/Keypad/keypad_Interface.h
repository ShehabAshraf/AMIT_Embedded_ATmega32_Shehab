#include <DIO/DIO_Interface.h>
#include <DIO/DIO_Private.h>
#include <../LIB/UTILIS.h>
#include <../LIB/STD_TYPES.h>
#include <util/delay.h>

#define Keypad_R0   PORTC,PIN0
#define Keypad_R1   PORTC,PIN1
#define Keypad_R2   PORTD,PIN4
#define Keypad_R3   PORTC,PIN3

#define Keypad_C0   PORTC,PIN4
#define Keypad_C1   PORTC,PIN5
#define Keypad_C2   PORTC,PIN6
#define Keypad_C3   PORTD,PIN5

void Keypad_INIT(void);
u8 Keypad_u8GetKeyPress(void);


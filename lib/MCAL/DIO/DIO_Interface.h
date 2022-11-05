/******GUARDs******/
/****** Protect from multiple definitions*******/ 



#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H
#include "../LIB/STD_TYPES.h"

/**** Function prototypes ****/
/********** Setting Direction (Input/Output) **********/
  
void DIO_voidSetPinDir(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Dir);     // Ports 0 ==> 3 Pins 0 ==> 7 Dirs OUTPUT/INPUT
void DIO_voidSetPortDir(u8 copy_u8Port , u8 copy_u8Dir);        // Ports 0 ==> 3  Dirs OUTPUT/INPUT

/****************************************/

/********** Setting Values **********/

void DIO_voidSetPinValue(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Val);       // Ports 0 ==> 3 Pins 0 ==> 7 Vals HIGH/LOW
void DIO_voidSetPortValue(u8 copy_u8Port , u8 copy_u8Val);      // Ports 0 ==> 3  Vals HIGH/LOW

/****************************************/

/********** Getting Values **********/

u8 DIO_u8GetPinValue(u8 copy_u8Port , u8 copy_u8Pin);       // Ports 0 ==> 3 Pins 0 ==> 7 
u8 DIO_u8GetPortValue(u8 copy_u8Port);      // Ports 0 ==> 3 Pins 0 ==> 7 Vals HIGH/LOW

/****************************************/

/********** Variable used in the functions **********/

/********** Ports **********/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

/****************************************/

/********** Pins **********/
#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7

/****************************************/

#define HIGH 1
#define LOW  0


#define INPUT  0
#define OUTPUT 1
#define INPUT_PULL_UP 2



#endif
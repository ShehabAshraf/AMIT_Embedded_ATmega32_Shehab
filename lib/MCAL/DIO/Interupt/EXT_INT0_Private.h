#include <../lib/UTILIS.h>
#include <../lib/STD_TYPES.h>
#include <util/delay.h>


#ifndef EXT_INT0_PRIVATE_H
#define EXT_INT0_PRIVATE_H
/*Rgisters*/
#define     GICR    *((volatile u8*)(0x5B)) // for external inputs
#define     GIFR    *((volatile u8*)(0x5A)) // Flag Reg
#define     MCUCR   *((volatile u8*)(0x55)) // Sense control for INT0,INT1
#define     MCUCSR  *((volatile u8*)(0x54)) // Sense control for INT2
/*************************/

/*Senses mode*/
#define EXT_LOW     5
#define EXT_RISING  3
#define EXT_FALLING 9
#define EXT_ANY_LC  7


/**************************/

/*Sense mode bits for EXT0*/
/*Interupt 0*/
#define ISC00    0
#define ISC01    1

/*Interupt 1*/
#define ISC10    2
#define ISC11    3

/*Interupt 2*/
#define ISC2     6
/**************************/

/*Flags*/
#define INTF1 7
#define INTF0 6
#define INTF2 5
/**************************/

/*Enable bit for EXT i0*/
#define EXTI0   6

#define NULL_PTR (void(*)(void))0


#endif
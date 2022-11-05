#include <../lib/UTILIS.h>
#include <../lib/STD_TYPES.h>
#include <util/delay.h>


#ifndef EXT_INT0_INTERFACE_H
#define EXT_INT0_INTERFACE_H

void EXT_INT0_voidINIT(void);
void EXT_INT0_voidEnable(void);
void EXT_INT0_voidDisable(void);

/*Function to do ISR*/
void EXT_INT0_CallBackFunction(void(*ptrfun)(void));

void __vector_1(void) __attribute__((used));



#endif
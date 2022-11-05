#include <../lib/UTILIS.h>
#include <../lib/STD_TYPES.h>
#include <util/delay.h>
#include <DIO/Interupt/GIE_Interface.h>
#include <DIO/Interupt/GIE_Private.h>






void GIE_voidEnable(void)
{
    SET_BIT(SREG , 7);

}


void GIE_voidDisable(void)
{
    CLR_BIT(SREG , 7);

}
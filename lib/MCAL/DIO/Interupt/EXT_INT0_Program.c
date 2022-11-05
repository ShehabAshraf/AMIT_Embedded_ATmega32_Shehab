#include <DIO/Interupt/EXT_INT0_Interface.h>
#include <DIO/Interupt/EXT_INT0_Private.h>



void EXT_INT0_voidINIT(void)
{

    /*Clear all sense modes*/
    /*Interupt 0*/
    CLR_BIT(MCUCR,ISC01);
    CLR_BIT(MCUCR,ISC00);
    /*Interupt 1*/
    CLR_BIT(MCUCR,ISC11);
    CLR_BIT(MCUCR,ISC10);
    /*Interupt 2*/
    CLR_BIT(MCUCSR,ISC2);

    #define SENSE_MODE EXT_FALLING

    /*Choose the sense mode*/
    if (SENSE_MODE == EXT_FALLING)
    {
        CLR_BIT(MCUCR,ISC00);
        SET_BIT(MCUCR,ISC01);
    }
    else if (SENSE_MODE == EXT_RISING)
    {
        SET_BIT(MCUCR,ISC01);
        SET_BIT(MCUCR,ISC00);
    }
    else if (SENSE_MODE == EXT_LOW)
    {
        CLR_BIT(MCUCR,ISC01);
        CLR_BIT(MCUCR,ISC00);
    }
    else if (SENSE_MODE == EXT_ANY_LC)
    {
        SET_BIT(MCUCR,ISC00);
        CLR_BIT(MCUCR,ISC01);
    }
    else{/*Diable interupt*/}

    CLR_BIT(GICR,INTF1);
    CLR_BIT(GICR,INTF0);
    CLR_BIT(GICR,INTF2);

    /*Disable flags by make it high*/
    SET_BIT(GIFR,INTF1);
    SET_BIT(GIFR,INTF0);
    SET_BIT(GIFR,INTF2);
}


void EXT_INT0_voidEnable(void)
{
    SET_BIT(GICR,EXTI0);
}


void EXT_INT0_voidDisable(void)
{
    CLR_BIT(GICR,EXTI0);
}








void (*GenPtr) (void) = NULL_PTR;


void EXT_INT0_CallBackFunction(void(*ptrfun)(void))
{
    if (ptrfun != NULL_PTR)
    {
        GenPtr=ptrfun;
    }
    

}

void __vector_1(void)
{
    /*Calls pointer called by hardware circuit when interupt */
    /*Global pointer saved in it the name of the function*/
    
    GenPtr();
}
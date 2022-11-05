// Include from LIB 
#include "../LIB/STD_TYPES.h"
#include "../LIB/UTILIS.h"

// Include from DIO Layer
#include "DIO_Interface.h"
#include "DIO_Private.h"

/********** Setting Direction (Input/Output) **********/
void DIO_voidSetPinDir(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Dir)
{
	if ((copy_u8Port >= 0) && (copy_u8Port < 4) )
	{
		
		if ((copy_u8Pin >=0) && (copy_u8Pin <8))
		{
		
			if (copy_u8Dir == OUTPUT)
			{
				switch (copy_u8Port)
				{
					case PORTA:{SET_BIT(REG_DDRA,copy_u8Pin); break;}
					case PORTB:{SET_BIT(REG_DDRB,copy_u8Pin); break;}
					case PORTC:{SET_BIT(REG_DDRC,copy_u8Pin); break;}
					case PORTD:{SET_BIT(REG_DDRD,copy_u8Pin); break;}
				}
			}
			else if (copy_u8Dir == INPUT)
			{
				switch (copy_u8Port)
				{
					case PORTA:{CLR_BIT(REG_DDRA,copy_u8Pin); CLR_BIT(REG_PORTA,copy_u8Pin); break;}
					case PORTB:{CLR_BIT(REG_DDRB,copy_u8Pin); CLR_BIT(REG_PORTB,copy_u8Pin); break;}
					case PORTC:{CLR_BIT(REG_DDRC,copy_u8Pin); CLR_BIT(REG_PORTC,copy_u8Pin); break;}
					case PORTD:{CLR_BIT(REG_DDRD,copy_u8Pin); CLR_BIT(REG_PORTD,copy_u8Pin); break;}
				}
			}
			else if (copy_u8Dir == INPUT_PULL_UP)
			{
				switch (copy_u8Port)
				{
					case PORTA:{CLR_BIT(REG_DDRA,copy_u8Pin); SET_BIT(REG_PORTA,copy_u8Pin); break;}
					case PORTB:{CLR_BIT(REG_DDRB,copy_u8Pin); SET_BIT(REG_PORTB,copy_u8Pin); break;}
					case PORTC:{CLR_BIT(REG_DDRC,copy_u8Pin); SET_BIT(REG_PORTC,copy_u8Pin); break;}
					case PORTD:{CLR_BIT(REG_DDRD,copy_u8Pin); SET_BIT(REG_PORTD,copy_u8Pin); break;}
				}
			}
			else
			{
				// NOTHING
			}
		}
	}	
}

/***************/

void DIO_voidSetPortDir(u8 copy_u8Port , u8 copy_u8Dir)
{
	if ((copy_u8Port >= 0) && (copy_u8Port < 4) )
	{
		if (copy_u8Dir == OUTPUT)
		{
			switch (copy_u8Port)
			{
				case PORTA:{REG_DDRA = 0xff; break;}
				case PORTB:{REG_DDRB = 0xff; break;}
				case PORTC:{REG_DDRC = 0xff; break;}
				case PORTD:{REG_DDRD = 0xff; break;}
			}
		}
		else if (copy_u8Dir == INPUT)
		{
			switch (copy_u8Port)
			{
				case PORTA:{REG_DDRA = 0x00; break;}
				case PORTB:{REG_DDRB = 0x00; break;}
				case PORTC:{REG_DDRC = 0x00; break;}
				case PORTD:{REG_DDRD = 0x00; break;}
			}
		}
		else
		{
			// NOTHING
		}
	}	
}

/****************************************/



/********** Setting Values **********/
void DIO_voidSetPinValue(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Val)
{
	if ((copy_u8Port >= 0) && (copy_u8Port < 4))
	{
		if ((copy_u8Pin >= 0) && (copy_u8Pin < 8))
		{
			if (copy_u8Val == HIGH)
			{
				switch (copy_u8Port)
				{
				case PORTA: {SET_BIT(REG_PORTA, copy_u8Pin); break;}
				case PORTB: {SET_BIT(REG_PORTB, copy_u8Pin); break;}
				case PORTC: {SET_BIT(REG_PORTC, copy_u8Pin); break;}
				case PORTD: {SET_BIT(REG_PORTD, copy_u8Pin); break;}
				}
			}
			else if (copy_u8Val == LOW)
			{
				switch (copy_u8Port)
				{
				case PORTA: {CLR_BIT(REG_PORTA, copy_u8Pin); break;}
				case PORTB: {CLR_BIT(REG_PORTB, copy_u8Pin); break;}
				case PORTC: {CLR_BIT(REG_PORTC, copy_u8Pin); break;}
				case PORTD: {CLR_BIT(REG_PORTD, copy_u8Pin); break;}
				}
			}
			else {/** Nothing **/}
		}
	}
}

/***************/

void DIO_voidSetPortValue(u8 copy_u8Port , u8 copy_u8Val)
{
	if ((copy_u8Port >= 0) && (copy_u8Port < 4))
	{
		if (copy_u8Val == HIGH)
		{
			switch (copy_u8Port)
			{
			case PORTA: {(REG_PORTA == 0xff); break;}
			case PORTB: {(REG_PORTB == 0xff); break;}
			case PORTC: {(REG_PORTC == 0xff); break;}
			case PORTD: {(REG_PORTD == 0xff); break;}
			}
		}
		else if (copy_u8Val == LOW)
		{
			switch (copy_u8Port)
			{
			case PORTA: {(REG_PORTA == 0x00); break;}
			case PORTB: {(REG_PORTB == 0x00); break;}
			case PORTC: {(REG_PORTC == 0x00); break;}
			case PORTD: {(REG_PORTD == 0x00); break;}
			}
		}
		else {/** Nothing **/}
	}
}
/****************************************/



/********** Getting Values **********/
u8 DIO_u8GetPinValue(u8 copy_u8Port , u8 copy_u8Pin)
{
	if ((copy_u8Port >= 0) && (copy_u8Port < 4))
	{
		if ((copy_u8Pin >= 0) && (copy_u8Pin < 8))
		{
			u8 copy_u8Val =1;
			switch (copy_u8Port)
			{
			case PORTA: {copy_u8Val = GET_BIT(REG_PINA,copy_u8Pin);  break;}
			case PORTB: {copy_u8Val = GET_BIT(REG_PINB,copy_u8Pin);  break;}
			case PORTC: {copy_u8Val = GET_BIT(REG_PINC,copy_u8Pin);  break;}
			case PORTD: {copy_u8Val = GET_BIT(REG_PIND,copy_u8Pin);  break;}
			}
			return copy_u8Val;
		}
	}
}

/***************/

u8 DIO_u8GetPortValue(u8 copy_u8Port)
{
	if ((copy_u8Port >= 0) && (copy_u8Port < 4))
	{
		u8 copy_u8Val ;
		switch (copy_u8Port)
		{
		case PORTA: {copy_u8Val = REG_PINA;  break;}
		case PORTB: {copy_u8Val = REG_PINB;  break;}
		case PORTC: {copy_u8Val = REG_PINC;  break;}
		case PORTD: {copy_u8Val = REG_PIND;  break;}
		}
		return copy_u8Val;
	}
}
/****************************************/
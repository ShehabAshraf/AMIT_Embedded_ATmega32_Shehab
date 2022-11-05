

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include <STD_TYPES.h>

/*Needed REGs*/
#define ADC_REG_ACSR    (*((volatile u8*) 0x28))    
/*Multiplexer REG*/
#define ADC_REG_ADMUX   (*((volatile u8*) 0x27))
/*Control & Status REG (Enable)*/
#define ADC_REG_ADCSRA  (*((volatile u8*) 0x26))
/*Data REGs (save conversion result)*/
#define ADC_REG_ADCH    (*((volatile u8*) 0x25))
#define ADC_REG_ADCL    (*((volatile u8*) 0x24))
/*Special REF*/
#define ADC_REG_SFIOR    (*((volatile u8*) 0x50))


/*Muliplexer Bits*/
/*Choose REF voltage Bits*/
#define ADC_REFS1   7
#define ADC_REFS0   6
/*Voltage REF modes*/
#define Reserved    0
#define AREF        1
#define AVCC        2
#define INT_VOLT    3

#define Voltage_Mode    2


#define ADC_ADLAR   5   //It will remain 0 to be right adjust the result
/*Channels */
#define ADC_MUX2    2
#define ADC_MUX1    1
#define ADC_MUX0    0

/*Control & Status Bits*/
#define ADC_ADEN    7
#define ADC_ADSC    6
#define ADC_ADATE   5
#define ADC_ADIF    4
#define ADC_ADPS2   2
#define ADC_ADPS1   1
#define ADC_ADPS0   0

/*Data Bits*/

/*Special Bits*/
#define ADTS0   5
#define ADTS1   6
#define ADTS2   7
#define SFIOR_RESERVED    4   //VI

#endif
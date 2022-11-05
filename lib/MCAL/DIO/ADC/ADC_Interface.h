#include <DIO/ADC/ADC_Private.h>

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


void ADC_INIT(void);
void ADC_EN(void);
void ADC_DIS(void);
u16 ADC_Read(u16 INPUT_PIN);

#endif
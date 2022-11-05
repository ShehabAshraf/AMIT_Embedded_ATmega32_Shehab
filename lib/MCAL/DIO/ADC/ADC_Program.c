#include <DIO/ADC/ADC_Interface.h>
#include <DIO/ADC/ADC_Private.h>
#include <../lib/UTILIS.h>


/*Voltage Reference /Prescalling ADEN ==> High /ADC Enable-Disable /SFIOR Reserved bit ==> Low*/
void ADC_INIT(void)
{
    /*Voltage Mode Selection*/
    if (Voltage_Mode == Reserved)
    {
        SET_BIT(ADC_REG_ADMUX,ADC_REFS1);
        CLR_BIT(ADC_REG_ADMUX,ADC_REFS0);
    }
    else if (Voltage_Mode == AREF)
    {
        CLR_BIT(ADC_REG_ADMUX,ADC_REFS1);
        CLR_BIT(ADC_REG_ADMUX,ADC_REFS0);
    }
    else if (Voltage_Mode == AVCC)
    {
        CLR_BIT(ADC_REG_ADMUX,ADC_REFS1);
        SET_BIT(ADC_REG_ADMUX,ADC_REFS0);
    }
    else if (Voltage_Mode == INT_VOLT)
    {
        SET_BIT(ADC_REG_ADMUX,ADC_REFS1);
        SET_BIT(ADC_REG_ADMUX,ADC_REFS0);
    }
    
    /*Special REG pin 4 Must be 0*/
    CLR_BIT(ADC_REG_SFIOR,SFIOR_RESERVED);

    /*Makes Channel 0 is the reading channel*/  /*It can be written like (ADMUX |= adc_number) it will choose the channel direct*/
    /*It must be in Read Function*/

    /*For Trigger (It can be used if we need that it will start when another action happens)*/
    // SET_BIT(ADC_REG_ADCSRA,ADC_ADATE);

    /*For prescaler we need it to be 50k::200k*/
    /*Processor runs in 16MHz  &&  ADC runs in 50k::200k*/
    /*It well act like a transltor between processor and ADC*/
    SET_BIT(ADC_REG_ADCSRA,ADC_ADPS0);
    SET_BIT(ADC_REG_ADCSRA,ADC_ADPS1);
    SET_BIT(ADC_REG_ADCSRA,ADC_ADPS2);

    


}


/*It can be put in INIT. of ADC*/
void ADC_EN(void)
{
    SET_BIT(ADC_REG_ADCSRA,ADC_ADEN);
}


void ADC_DIS(void)
{
    CLR_BIT(ADC_REG_ADCSRA,ADC_ADEN);
}



u16 ADC_Read(u16 INPUT_PIN)
{
    u16 AdcRead =0;
    ADC_REG_ADMUX |= INPUT_PIN ; 
    SET_BIT(ADC_REG_ADCSRA,ADC_ADSC);   //Start Conversion
    while (GET_BIT(ADC_REG_ADCSRA,ADC_ADIF)==0)
    {
        /* Nothing happens */
    }
    
    AdcRead=(int)ADC_REG_ADCL+ (int)ADC_REG_ADCH*256;
    return AdcRead;
}
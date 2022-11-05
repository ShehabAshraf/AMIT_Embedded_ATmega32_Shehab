#include <DIO/DIO_Interface.h>
#include <DIO/DIO_Private.h>
#include <STD_TYPES.h>
#include <UTILIS.h>
#include <util/delay.h>
#include <LCD/LCD_Interface.h>



int main()
{
    // u8 name_var = 'S';
    u8 name_varaa[] = "SHEHAB ^__^";

   
    LCD_Init();
    LCD_voidWriteString(name_varaa);
    while (1)
    {
        /*Write program to display name*/
        // LCD_voidWriteString(name_var);
        // LCD_voidWriteData(name_var); _delay_ms(1000);

        // name_var++;
        // LCD_voidWriteString(name_varaa);
        // _delay_ms(1000);
    }
    
}
#include <../LIB/UTILIS.h>
#include <../LIB/STD_TYPES.h>
#include <DIO/DIO_Interface.h>
#include <DIO/DIO_Private.h>
#include <Keypad/keypad_Interface.h>
#include <LCD/LCD_Interface.h>
#include <util/delay.h>
int main()
{
    Keypad_INIT();
    LCD_Init();
    LCD_voidWriteString("Shehab");
    while (1)
    {
        // u8 read = Keypad_u8GetKeyPress();

        // LCD_voidWriteData(read);
        // _delay_ms(1000);
        // LCD_GoTo(0,0);

    }
    
}
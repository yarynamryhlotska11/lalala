#include <avr/io.h>
#include <util/delay.h>

#define LED_R PD5 // buildin led


#define LED_DDR DDRD
#define LED_PORT PORTD

int main(void)
{
    LED_DDR |= (1 << LED_R); 

    while (1) 
    {
        for (uint8_t i = 0; i < 3; i++) {
            LED_PORT |= 1 << LED_R;    // включити світлодіод
            _delay_ms(100);           // затримка
            LED_PORT &= ~(1 << LED_R); // виключити світлодіод
            _delay_ms(200);     
        }
        for (uint8_t i = 0; i < 3; i++) {
            LED_PORT |= 1 << LED_R;    // включити світлодіод
            _delay_ms(300);           // затримка
            LED_PORT &= ~(1 << LED_R); // виключити світлодіод
            _delay_ms(200);     
        }
       
        for (uint8_t i = 0; i < 3; i++) {
            LED_PORT |= 1 << LED_R;    // включити світлодіод
            _delay_ms(100);           // затримка
            LED_PORT &= ~(1 << LED_R); // виключити світлодіод
            _delay_ms(200);     
        }


       _delay_ms(1000); 

    }

  return 0;
}
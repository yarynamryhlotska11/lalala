#include <avr/io.h>
#include <util/delay.h>
#include <avr/sleep.h> 
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#define LED_0 PD0
#define LED_1 PD1
#define LED_2 PD2
#define LED_3 PD3
#define LED_4 PD4
#define LED_5 PD5
#define LED_6 PD6
#define LED_7 PD7
#define BTN PB5

volatile int button_pressed = 0;
volatile int pressed_twice = 0;

ISR(PCINT0_vect,ISR_BLOCK)
{
  int timer = 0;
  while (!(PINB & (1 << BTN))){
    timer++;
    _delay_ms(1);
  }
    if (timer >= 2000) {
      button_pressed = 1;
    } 
    else if (timer >= 1){
      if(!pressed_twice){
        pressed_twice = 1;
      while (PINB & (1 << BTN)){
        _delay_ms(1);
      }
    } else if (pressed_twice) {
      pressed_twice = 0;
    }
    }
}

void fire_on(int port) {
  int i = 0;
  PORTD |= 1 << port;
  while (i <= 100){
    _delay_ms(1);
    if (button_pressed){
      break;
    }
    i++;
  }
}
void fire_off(int port) {
  int i = 0;
  PORTD &= ~(1 << port);
  while (i <= 100){
    _delay_ms(1);
    if (button_pressed){
      break;
    }
    i++;
  }
}

void johnson_up(){
  int LEDS[8] = {LED_0, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7};
    for (int i = 0; i < 8; i++){
      if (button_pressed){
      break;
    }
    fire_off(LEDS[i]);
    if (button_pressed){
      break;
    }
    if (button_pressed){
      break;
    }
    }
}

void johnson_down(){
  int LEDS[8] = {LED_0, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7};
    for (int i = 0; i < 8; i++){
      if (button_pressed){
      break;
    }
    fire_on(LEDS[i]);
    if (button_pressed){
      break;
    }
    if (button_pressed){
      break;
    }
    }
}

void running_flame(){
  PORTD = 0; 
  int LEDS[8] = {LED_0, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7};
  while (1) {
    if (button_pressed){
      button_pressed = 0;
    break;
    }
    for (int i = 0; i < 8; i++){
    fire_on(LEDS[i]);
    if (button_pressed){
      break;
    }
    PORTD &= ~(1 << LEDS[i]);
    }
  }
}

void running_shadow(){
  PORTD = 0xFF; 
  int LEDS[8] = {LED_0, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7};
  while (1) {
    if (button_pressed){
      button_pressed = 0;
    break;
    }
    for (int i = 0; i < 8; i++){
    fire_off(LEDS[i]);
    if (button_pressed){
      break;
    }
    PORTD |= 1 << LEDS[i];
    }
  }
}

void running_johnson(){
  PORTD = 0; 
    while (1){
      if (button_pressed){
      button_pressed = 0;
    break;
    }
    johnson_down();
    johnson_up();
  }
}

int main(void)
{
  DDRD = 0xFF;
  DDRB &= ~(1<<BTN);
  PCMSK0 |= (1<<PCINT5);
  PCICR |= (1<<PCIE0);
  sei();
  while(1){
  running_flame();
  running_shadow();
  running_johnson();
  }
return 0;
}


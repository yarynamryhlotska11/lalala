#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
<<<<<<< HEAD
#include <string.h>

#define BTN1 PC4
#define BTN2 PC5

static char alphabet[26][8] = {
    {0, 0b00111111, 0b01001000, 0b10001000, 0b10001000, 0b01001000, 0b00111111, 0}, // A

    {0, 0b00000110, 0b01101001, 0b10010001, 0b10010001, 0b10010001, 0b11111111, 0}, // B
=======
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
>>>>>>> d271968 (lab2)

    {0, 0b01000010, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b01111110, 0}, // C

    {0, 0b01111110, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b11111111, 0}, // D

    {0, 0b10010001, 0b10010001, 0b10010001, 0b10010001, 0b10010001, 0b11111111, 0}, // E

    {0, 0b10010000, 0b10010000, 0b10010000, 0b10010000, 0b10010000, 0b11111111, 0}, // F

    {0, 0b01001111, 0b10001001, 0b10000001, 0b10000001, 0b10000001, 0b01111110, 0}, // G

    {0, 0b11111111, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b11111111, 0}, // H

    {0, 0b10000001, 0b10000001, 0b11111111, 0b11111111, 0b10000001, 0b10000001, 0}, // I

    {0, 0b10000000, 0b11111110, 0b10000001, 0b10000001, 0b10000001, 0b10011110, 0}, // J

    {0, 0b10000001, 0b01000110, 0b00101000, 0b00011000, 0b00010000, 0b11111111, 0}, // K

    {0, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b11111111, 0}, // L

    {0, 0b11111111, 0b01000000, 0b00100000, 0b00100000, 0b01000000, 0b11111111, 0}, // M

    {0, 0b11111111, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b11111111, 0}, // N

    {0, 0b01111110, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b01111110, 0}, // O

    {0, 0b01110000, 0b10001000, 0b10001000, 0b10001000, 0b10001000, 0b11111111, 0}, // P

    {0, 0b01111110, 0b10000011, 0b10000101, 0b10000001, 0b10000001, 0b01111110, 0}, // Q

    {0, 0b01100001, 0b10010110, 0b10011000, 0b10010000, 0b10010000, 0b11111111, 0}, // R

    {0, 0b01001110, 0b10010001, 0b10010001, 0b10010001, 0b10010001, 0b01100010, 0}, // S

    {0, 0b10000000, 0b10000000, 0b11111111, 0b11111111, 0b10000000, 0b10000000, 0}, // T

    {0, 0b11111110, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b11111110, 0}, // U

    {0, 0b11111000, 0b00000100, 0b00000011, 0b00000011, 0b00000100, 0b11111000, 0}, // V

    {0, 0b11111111, 0b00000010, 0b00000100, 0b00000100, 0b00000010, 0b11111111, 0}, // W

    {0, 0b11000011, 0b00101100, 0b00010000, 0b00010000, 0b00101100, 0b11000011, 0}, // X

    {0, 0b11000000, 0b00110000, 0b00001111, 0b00001111, 0b00110000, 0b11000000, 0}, // Y

    {0, 0b11000001, 0b10100001, 0b10010001, 0b10001001, 0b10000101, 0b10000011, 0} // Z
};

int speed = 80, loopy = 0, l = 0, i = 0, j = 0, k = 0;

void btn1_pressed()
{
<<<<<<< HEAD
  if (!(PINC & (1 << BTN1)))
  {
    speed += 50;
  }
}

void btn2_pressed()
{
  if (!(PINC & (1 << BTN2)))
  {
    if (speed > 10)
    {
      speed -= 10;
      if (i > (speed - 10))
      {
        loopy = 1;
      }
    }
  }
}

void draw_pix_1(char *str, int j, int k, int l) //відображення пікселя з рядка на світлодіодному маніпуляторі
{
  if (j + k < 8) //перевірка чи знаходимося в межах області матриці світлодіодів
  {
    PORTD = (1 << (j + k));
    if (str[l] == ' ')
    {
      PORTB = ~0;
    }
    else
    {
      PORTB = ~alphabet[str[l] - 'a'][j];
    }
    _delay_us(500);
  }

  if ((k - j - 1 >= 0) && (l + 1 < strlen(str))) //відображення наступного пікселя у наступному рядку
  {
    PORTD = (1 << (k - j - 1));
    if (str[l + 1] == ' ')
    {
      PORTB = ~0;
    }
    else
    {
      PORTB = ~alphabet[str[l + 1] - 'a'][7 - j];
    }
    _delay_us(500);
  }

  if ((k - j - 1 >= 0) && (l + 1 == strlen(str))) //відображає останній рядок пікселів в рядку 
  {
    PORTD = (1 << (k - j - 1));
    PORTB = ~0;
    _delay_us(500);
  }
}

void draw_pix_2(char *str, int j, int k, int l)
{
  if (j + k < 8)
  {
    PORTD = (1 << (j + k));
    PORTB = ~0;
    _delay_us(500);
  }

  if (k - j - 1 >= 0)
  {
    PORTD = (1 << (k - j - 1));
    PORTB = ~alphabet[str[0] - 'a'][7 - j];
    _delay_us(500);
  }
}

void draw_let_1(char *str, int l) // відображення символа
{
  for (k = 0; k < 8; k++)
  {
    for (i = 0; i < speed; i++)
    {
      for (j = 0; j < 8; j++)
      {
        draw_pix_1(str, j, k, l); //відображає конкретний піксель символу на  маніпуляторі
      }
      PORTD = 0x00;
      if (loopy == 1)
      {
        loopy = 0;
        break;
      }
    }
  }
}

void draw_let_2(char *str, int l)
{
  for (k = 0; k < 8; k++)
  {
    for (i = 0; i < speed; i++)
    {
      for (j = 0; j < 8; j++)
      {
        draw_pix_2(str, j, k, l);
      }
      PORTD = 0x00;
      if (loopy == 1)
      {
        loopy = 0;
        break;
      }
    }
  }
}
{
  for (k = 0; k < 8; k++)
  {
    for (i = 0; i < speed; i++)
    {
      for (j = 0; j < 8; j++)
      {
        draw_pix_2(str, j, k, l);
      }
      PORTD = 0x00;
      if (loopy == 1)
      {
        loopy = 0;
        break;
      }
    }
  }
}

ISR(PCINT1_vect)
{
  btn1_pressed();
  btn2_pressed();
}

int main()
{

  DDRB = 0xff;
  DDRD = 0xff;

  DDRC &= ~(1 << DDC4);
  PORTC |= (1 << PORTC4);
  DDRC &= ~(1 << DDC5);
  PORTC |= (1 << PORTC5);
  PCMSK1 |= (1 << PCINT12);
  PCMSK1 |= (1 << PCINT13);
  PCICR |= (1 << PCIE1);
  sei();

  char *str = "hello";
  for (l = 0; l < strlen(str); l++)
  {
    draw_let_1(str, l);
    if (l + 1 == strlen(str))
    {
      draw_let_2(str, l);
      l = -1;
    }
  }
  return 0;
=======
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
>>>>>>> d271968 (lab2)
}

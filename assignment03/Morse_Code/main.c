//User LD2 Green LED corresponding to STM32 I/O PA5 pin 21
//Need to Enable Peripheral Clock Registor for AHB1 for GPIO_A

//Clock Registor
//RCC_base = 0x40023800
//RCC_AHB1ENR
//      Offset: 0x30
//      Set Bit 0 to 1 to enable clock for GPIOA

//GPIO_A_base = 0x40020000
//GPIOx_MODER (set the port is input or output)
//      Offset: 0x00
//      Set GPIOA (Port5) to output mode
//              --> Set bit 10 to 1 (0x400)
//      At address 0x40020000 write 0xA80004000

//GPIOx_ODR (write the output value to GPIOA port 5
//      Offset: 0x14
//      Write 1 to the GPIOA (Port5)
//              --> Set bit 5 to 1 (0x20)
//      Step3: Address 0x40020014 write 0x20 to turn LED ON
//      Step4: Address 0x40020014 write 0x00 to turn LED OFF
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

//Basic function define 
void Delay_blink(unsigned long time); //delay 1s
void blinking_led(int); //blinking led function
void led_control(int input); //led control 1 turn on, other turn off
void Morse_led(char *input);

//Set up the constant variable

const char message[ ] = "SOS"; 
// In ASCII code, 'space' is 32, '0'-'9' is 48-57, and 'A'-'Z' is 65-90
//const String morse[] = { ".----", "..---", "...--", "....-", ".....", 
//  "-....", "--...", "---..", "----.", "-----", ".-", "-...", "-.-.", "-..", 
//  ".","..-.","--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", 
//  ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", 
//  "--.."};

const int dot_delay = 1; //delay 1s for dot
const int dash_delay = 3; //delay 3 time for dash
const int space_delay = 7; //dealy 7 times between word

void main()
{
  RCC_AHB1ENR = 0x01; //Enable clock to GPIOA
  GPIOA_MODER |= 0x400; //Set GPIOA to output
  char input[] = "- .- -."; //Encode = T-A-N
  
  while(1) {
//    Morse_led(input);
//    blinking_led(1);
    for (int j = 0;j <strlen(input); j++){
      if (input[j] == '.'){
        led_control(1);
        Delay_blink(dot_delay);
      }
      else if(input[j] == '-'){
        led_control(1);
        Delay_blink(dash_delay);
      }
      else if(input[j] == ' '){
        Delay_blink(3); //delay  between each character
      }
      led_control(0);
      Delay_blink(1);
    }
    Delay_blink(space_delay);
  }
}

void Delay_blink(unsigned long time){
  unsigned long i;
  while(time > 0){
    i = 2000000;
    while(i>0){
      i = i -1;
    }
    time = time -1;
  }
}
void blinking_led(int delay){
  GPIOA_ODR = 0x20; //turn LED ON
  Delay_blink(delay);
  GPIOA_ODR = 0x00; //turn LED off
  Delay_blink(delay);
}
void led_control(int input){
  if (input == 1){
    GPIOA_ODR = 0x20; //turn LED ON
  }
  else{
    GPIOA_ODR = 0x00; //turn LED off
  }
}


void Morse_led(char *input) {
  for (int i = 0; i <strlen(input); i++){
    GPIOA_ODR = 0x20; //turn on the LED
    if(input[i] == '.'){
      Delay_blink(1);
    }
    else if (input[i] == '-'){
      Delay_blink(3);
    }
    GPIOA_ODR = 0x00; //turn off the LED
  }
}
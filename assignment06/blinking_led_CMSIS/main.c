
#include "stm32f401xe.h"

volatile int counter=0;
void delay(int);

void delay(int interval){
   counter = 0;
   while (counter < interval){
      counter++;
   }
}
void main(void)
{
    
    // RCC Base Address: 0x40023800
    // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    // Address offset: 0x30
    // Set bit[0] to 1
    // Bit band alias start from 0x42000000 and from 0x22000000
    // 1. Enable clock to Peripheral
    //RCC_AHB1ENR |= 0x1;
    
    //*((unsigned int*)((0x42000000) + (0x23830 * 32) + (0 * 4))) = 0x1; //using bit band
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  
    // GPIOA Base Address: 0x40020000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable Port5 as output
    //GPIOA_MODER |= 0x400;
    //*((unsigned int*)((0x42000000) + (0x20000 * 32) + (10 * 4))) = 0x1; // using bit band
    GPIOA->MODER |= 0x400;

    // GPIOA Base Address: 0x40020000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x00; // Turn LED OFF
     
    while(1)
    {
      delay(1000000);
    //GPIOA_ODR |= GPIOA;
      //*((unsigned int*)((0x42000000) + (0x20014 * 32) + (5 *4))) = 0x1; // using bit band 
      GPIOA->ODR |= (1<<5);
      
      delay(1000000);
    //GPIOA_ODR &= ~GPIOA;
    // *((unsigned int*)((0x42000000) + (0x20014 * 32) + (5 *4))) = 0x0; // using bit band 
      GPIOA->ODR &= ~(1<<5);

    }
}

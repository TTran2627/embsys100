/*******************************************************************************
FILE NAME   : main.c
DESCRIPTION : Where all the magic begins.
	      

Copyright   : David Allegre
            : 2015
	    : All Rights Reserved
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "nucleoboard.h"
#include "hw_init.h"
#include "print.h"

char clr_scrn[] = { 27, 91, 50, 74, 0 };              // esc[2J
/* Public variables ----------------------------------------------------------*/
__IO uint32_t timer;
PRINT_DEFINEBUFFER();           /* required for lightweight sprintf */
/* Private prototype ---------------------------------------------------------*/
void delay(uint32_t time);

uint32_t sqrAsm();
const char* myCstr = "\nHello from assembly!";

uint32_t div2Asm();
const char* myCstr1 = "\nDivide by 2 Assembly function!";

uint32_t swapCharsAsm(char* x, char* y);
const char* myCstr2 = "\n Swap 2 char by Assembly";

/*******************************************************************************
Function Name   : main
Description     : 
Parameters      :
Return value    :               */
void main() {
uint8_t foo;
uint8_t Result;

  foo = 10;
  Hw_init();

  PrintString(clr_scrn); /* Clear entire screen */
  // Change [My name] to your name      //
  PrintString("[Tan Tran]'s Nucleo STM32F401 is ... alive!!!\n");
  RETAILMSG(1, ("Programming Assignment #1: Built %s %s.\r\n\r\n",
              __DATE__,
              __TIME__)); 
  char x = 'T';
  char y = 'N';
  PrintString("\n------------Before Swapping-------------");
  PrintString("\nx = ");
  PrintByte(x);
  PrintString("\ny = ");
  PrintByte(y);
  Result = swapCharsAsm(&x, &y);
  PrintString("\n------------After Swapping-------------");
  PrintString("\nx = ");
  PrintByte(x);
  PrintString("\ny = ");
  PrintByte(y);
  PrintString("\n------------Return 0 If 2 Char Are Identical, Otherwise, Return 1-------------");
  PrintString("\nResult = ");
  Print_uint32(Result);
  PrintString("\n\n");
  
  while (foo) {
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
    PrintString("EMBSYS CP100A: University of Washington - UART Test Application \n");
    
    delay(1000);
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
    
    delay(1000);
    
    PrintString("x = ");
    Print_uint32(foo);
    uint32_t x = sqrAsm(foo);
    
    PrintString("x^2 = ");
    Print_uint32(x);
    PrintString("\n");
    
    PrintString("y = ");
    Print_uint32(foo);
    uint32_t y = div2Asm(foo);
    
    PrintString("y/2 = ");
    Print_uint32(y);
    PrintString("\n");
    
    
    
    foo--;
  }
  while (1) {
    // loop forever
    asm("nop");
  }
}


void delay(uint32_t time) {
  
  timer = time;
  while(timer) {}
}
void SystemInit(void) {
  // System init is called from the assembly .s file
  // We will configure the clocks in hw_init
  asm("nop");
}
  
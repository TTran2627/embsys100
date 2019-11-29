# **Assignment 05**


1. Create a function that allows swapping of two pointer
   * Explain what the "main" function does to the CSTACK in order setup the input arguments prior to calling the swap_pointer() function? **In Cortex M4, the first four register r0-r3 are used to pass argument value into a subroutine and to return a result value from a function. Moreover, the register r4-r8 are used to hold the values of a routine's local variables. Therefore, a subroutine must preserve the contents of the register r4 to r8 and LK register (which hold the return address instructions). Before calling the swap_pointer in main function, the compiler preserve 6 register (R3-R7, LK) on stack pointer to prepare for function calling (function argument and return address)**

   * And what are the value in R0 and R1 when swap_pointer is called? **The swap_pointer function need to have 2 input arguments (*xPr and *yPr). In Cortex M4,r0-r3 are used to pass argument in and out of function. Therefore, when the swap_pointer function is called, the R0 and R1 will store the memory address of xPr and yP**
   * Share a screen shot of the local variables insid of "main" after the function swap_pointer() return, showing the values of the pointers and what they are pointing to, similar to picture below?

![Image of swap_pointer](https://github.com/TTran2627/embsys100/blob/master/assignment01/HelloWorld.PNG)



2. Run sqrAsm code from the class demo:

![Image of sqrAsm.s](https://github.com/TTran2627/embsys100/blob/master/assignment01/HelloWorld.PNG)

3. Create and run div2Asm.s:

![Image of div2Asm.s](https://github.com/TTran2627/embsys100/blob/master/assignment01/HelloWorld.PNG)

4. Create and run swapCharAsm :

![Image of swapCharAsm.s](https://github.com/TTran2627/embsys100/blob/master/assignment01/HelloWorld.PNG)

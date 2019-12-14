# **Assignment 07**


1. Set a break point inside the Systick_Handler interrupt and capture a snapshot of the stack once inside the interrupt and LR value. Explain what are values stored on the stack at the moment the Handler gets invoked.
   * In M4 cortex microcontroller, in order to call an exception handler, the exception mechanism needs to save 8 registers R0 to R3, R12, LR, PSR and PC to stack at exception entrance automatically, and restore them back when exception exit. Moreover, when program reaches exception handler the LR register will store a special value 0xFFFFFFF9.



![Image of swap_pointer](https://github.com/TTran2627/embsys100/blob/master/assignment07/capture.PNG)

void swap_pointer(int* *x, int* *y);

int main()
{ int x = 1000000;
  int y = 2000000;
  int* xPr = &x; //address of x variable
  int* yPr = &y; //address of y variable
  
  swap_pointer(&xPr , &yPr);
  return 0;
}

void swap_pointer(int* *x, int* *y){
    int* temp = *x;
    *x = *y;
    *y = temp;
}
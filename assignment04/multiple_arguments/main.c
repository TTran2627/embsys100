
int sum(int, int, int, int, int);

int sum(int var0, int var1, int var2, int var3, int var4)
{
     int lvar0;
     int lvar1;
     int lvar2;
     int lvar3;
     int lvar4;
     
     int sum;
     
     lvar0 = var0;
     lvar1 = var1;
     lvar2 = var2;
     lvar3 = var3;
     lvar4 = var4;
     
     sum = lvar0 + lvar1 + lvar2 + lvar3 + lvar4;
     return sum;
}


int result = 0;
int main()
{
  result = sum(1,2,3,4,5);
  return 0;
}

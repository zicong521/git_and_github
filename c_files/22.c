#include<stdio.h>
#include<stdlib.h>
int main()
{
   unsigned char p = 0x01;
   for (int i =0;i<7;i++)
   {
      p = p << 1;
      printf("%#X\n", p);
   }
   return 0; 
}
#include <stdio.h>

int main(void) 
{
  int i;
  scanf("%d", &i);

  int n;
  for(n = 1; n <= i; n++)
  {
  int a, b;
  char c;
  scanf(" (%d,%d,%c)", &a, &b, &c);
  printf("%4d |", a);  
   
  int d;
  d = 0; 
  while(d<b)
  {
  printf("%c", c);
  d++;
  }

  printf(" %d\n", b);

  }
  
  return 0;
}


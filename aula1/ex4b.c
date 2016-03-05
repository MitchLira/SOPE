#include <stdio.h> 
int main(int argc,char *argv[])  
{ 
  int n =*(argv[2])-48;
  int i;
  for(i = n; i > 0; i--)
  {
  printf("Hello %s!\n", argv[1]); 
  }

  return 0; 
} 

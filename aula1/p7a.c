#include <stdio.h>
#include <stdlib.h>

void function1 ()
{
  printf("Executing  exit handler 1 \n");
}

void function2()
{
 printf("Executing exit handler 2 \n");
}
int main()
{
 atexit(function1);
 atexit(function2);
 printf("Main done! \n");
}


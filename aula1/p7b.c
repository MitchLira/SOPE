#include <stdio.h>
#include <stdlib.h>

void function1 ()
{
  printf("Executing  exit handler 1 \n");
exit(0);
}

void function2()
{
 printf("Executing exit handler 2 \n");
exit(1);
}
int main()
{
 atexit(function2);
 atexit(function1);
 printf("Main done! \n");
}


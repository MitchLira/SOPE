#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int n1 = atoi(argv[1]);
int n2 = atoi(argv[2]);

int n;

while(n != n2)
{
n = rand() % n1;
printf(" %d \n", n); 
}

 return 0;
}

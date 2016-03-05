#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h> 


int main(int argc, char *argv[])
{
clock_t start, end;
 struct tms t;
 long ticks;
 int k;
 start = times(&t); /* início da medição de tempo */
 ticks = sysconf(_SC_CLK_TCK); 
int n1 = atoi(argv[1]);
int n2 = atoi(argv[2]);

int n;

while(n != n2)
{
n = rand() % n1;
printf(" %d \n", n); 
}
 end = times(&t); /* fim da medição de tempo */
 printf("Clock: %4.2f s\n", (double)(end-start)/ticks); 
 printf("User time: %4.2f s\n", (double)t.tms_utime/ticks);
 printf("System time: %4.2f s\n", (double)t.tms_stime/ticks); 
 return 0;
}

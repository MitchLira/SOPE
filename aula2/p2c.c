#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
# include <time.h>
#include <sys/times.h> 
#include <unistd.h> 

#define BUF_LENGTH 10 
void main(int argc,char *argv[]) 
{ 
  clock_t start, end; 
  struct tms t; 
  long ticks; 
  int k; 
  
  int src, dst, leitura, escrita;
  char buf[BUF_LENGTH];
  
  start = times(&t);                       /* início da medição de tempo */ 
  ticks = sysconf(_SC_CLK_TCK); 
  
  src = open(argv[1], O_RDONLY);
  if(src == -1)
  {

  }
  dst = open(argv[2], O_TRUNC | O_WRONLY | O_CREAT, S_IRUSR);
  if(dst == -1)
  {

  }
  while((leitura = read(src, buf, BUF_LENGTH)) != 0)
  {
      if( escrita = write(dst, buf,leitura) < 0)
      {
          close(src);
          close(dst);

      }
  }
    
  close(src);
  close(dst);
  end = times(&t);                            /* fim da medição de tempo */ 
  printf("Clock: %4.2f s\n", (double)(end-start)/ticks); 

} 


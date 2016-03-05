#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <string.h> 

#define BUF_LENGTH 256 
int main(int argc,char *argv[]) 
{ 
  int src, leitura, escrita;
  char buf[BUF_LENGTH];
  src = open(argv[1], O_RDONLY);
  if(src == -1)
  {
      return 1;
  }
  while((leitura = read(src, buf, BUF_LENGTH)) != 0)
  {
      if( escrita = write(STDOUT_FILENO,buf,leitura) < 0)
      {
          close(src);
          return 3;
      }
  }
  close(src);
  return 0;  // zero é geralmente indicativo de "sucesso" e
} 


#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#define BUF_LENGTH 256 
int main(int argc,char *argv[]) 
{ 
  int src, dst, leitura, escrita;
  char buf[BUF_LENGTH];
  src = open(argv[1], O_RDONLY);
  if(src == -1)
  {
      return 1;
  }
  dst = open(argv[2], O_TRUNC | O_WRONLY | O_CREAT, S_IRUSR);
  if(dst == -1)
  {
      return 2;
  }
  while((leitura = read(src, buf, BUF_LENGTH)) != 0)
  {
      if( escrita = write(dst, buf,leitura) < 0)
      {
          close(src);
          close(dst);
          return 3;
      }
  }
  close(src);
  close(dst);
  return 0;  // zero é geralmente indicativo de "sucesso" e
} 


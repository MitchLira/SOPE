#include <stdio.h> 
int main(int argc, char *argv[], char *envp[])  
{ 
  int i =0;
  while(envp[i] != NULL)
  {
if(strncmp(envp[i],"USER=", 5) ==0)
{
  printf("Hello %s!\n", envp[i]+5); 
}
  i++;
  }

  return 0; 
} 

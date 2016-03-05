#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main(int argc,char const *argv[]){

  char stri[50];
  char *aux;
  char *token[10];
  int j,i=0;


  fgets(stri,100,stdin);
  aux = strtok(stri," ");


  while (aux != NULL) {
    token[i]=(char *)malloc(50*sizeof(char));
    strcpy(token[i],aux);
    aux =strtok(NULL, " ");
    i++;
  }


  for (j = 0;j < i;j++) {
    printf("%s\n",token[j]);
  }

  for (j= 0; j <i; j++) {
    free(token[j]);
  }

  return 0;
}

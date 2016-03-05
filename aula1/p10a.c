#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    char *token;
    char str[100];
    fgets(str,100,stdin);
    if( str == NULL)
    {
        perror("Couldn't read! \n");
        return(-1);
    }
    token = strtok(str, " ");
    while(token != NULL)
    {
        printf("%s  ", token);
        token = strtok(NULL, " ");
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <fcntl.h> 

struct Info {
	char  title[50];
	char  mode[50];
	char  date[100];
	char  dir[100];
	char  url[101];
	};  
	
int equalFiles(struct Info info1,struct Info info2)
{
	char l1;
	char l2;
	FILE *fp1 = fopen(info1.url , "r");
	FILE *fp2 = fopen(info2.url, "r");
	
	
	do {
		l1 = fgetc(fp1);
		l2 = fgetc(fp2);
	} while (l1 != EOF && l2 != EOF && l1==l2);
	
	if(l1 == l2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}


int main(int argc, char *argv[])
{
	int fd;
	FILE *hardlinksfp;
	FILE *fp;
	pid_t pid , pid2;
	int duplication, duplication2;
	char l1[101];
	char l2[102];
	char *symbol;
	char dirhlinks[256];
	struct Info info1;
	struct Info info2;
	
	if(argc != 2){
		fprintf(stderr, "Usage: %s dir_name\n", argv[0]);
		exit(1);
	}
	
	
	fd=open("teste.txt",O_CREAT|O_RDWR|O_TRUNC,0600); 
	if(fd < 0)
	{
		perror("Error: Open files.txt failed!");
		exit(1);
	}
	
	pid = fork();
	
	if(pid < 0)
	{
		perror("Error: Fork failed!");
		exit(2);
	}
	
	
	if(pid ==0)
	{

		duplication = dup2(fd, STDOUT_FILENO);

		
		if(duplication < 0)
		{
			perror("Error: Dup2 failed!");
			exit(3);
		}		
		
		execl("lsdir", "lsdir", argv[1], NULL);
		
	}
	else 
	{
		wait(NULL);
	}
	close(fd);
	

	fd=open("files.txt",O_CREAT|O_TRUNC|O_RDWR,0600); 
	pid2 = fork();
		
	if(pid2 < 0)
	{
		perror("Error: Fork failed!");
		exit(4);
	}
	
	else if(pid2 == 0)
	{
		duplication2 = dup2(fd, STDOUT_FILENO);
		if(duplication2 < 0)
		{
			perror("Error: Dup2 failed!");
			exit(5);
		}
		
		execlp("sort", "sort", "teste.txt", NULL);
		close(fd);
	}
	else 
	{
		wait(NULL);
	}
	
	
	unlink("teste.txt");
	close(fd);	
		
	fp = fopen("files.txt" , "r");
	sprintf(dirhlinks, "%s/%s", argv[1], "hlinks.txt");
	
	hardlinksfp=fopen(dirhlinks, "w");
	
	if(fp == NULL) 
	{
      perror("Error opening file");
      exit(6);
	}
	
	if(fgets(l1, 101, fp)!=NULL ) 
	{

			symbol = strtok(l1, "/");
			strcpy(info1.title, symbol);
    
			symbol = strtok(NULL, " ");
			strcpy(info1.mode, symbol);
    
			symbol = strtok(NULL, " ");
			strcpy(info1.date, symbol);
    
			symbol = strtok(NULL, "\n");
			strcpy(info1.dir, symbol);
    
			sprintf(info1.url, "%s/%s", info1.dir, info1.title);
		
			
		}
		while(fgets(l2, 101, fp) != NULL)
		{

    
			symbol = strtok(l2, "/");
			strcpy(info2.title, symbol);
    
			symbol = strtok(NULL, " ");
			strcpy(info2.mode, symbol);
    
			symbol = strtok(NULL, " ");
			strcpy(info2.date, symbol);
    
			symbol = strtok(NULL, "\n");
			strcpy(info2.dir, symbol);
    
			sprintf(info2.url, "%s/%s", info2.dir, info2.title);
		

			if( (strcmp(info1.title, info2.title)== 0) && (strcmp(info1.mode, info2.mode) == 0))
			{
				if(equalFiles(info1, info2) == 1)
				{
					unlink(info2.url);
					link(info1.url, info2.url);
					fprintf(hardlinksfp,"%s \n", info2.url);
				}
			}
			else
			{
				strcpy(info1.title,info2.title);
				strcpy(info1.mode, info2.mode);
				strcpy(info1.date, info2.date);
				strcpy(info1.dir, info2.dir);
				strcpy(info1.url, info2.url);
			}
		}
	fclose(hardlinksfp);
	fclose(fp);
	return 0;
}

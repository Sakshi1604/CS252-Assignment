#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include<sys/types.h>
int main()
{
	char str[30];
	printf("enter the string :");
	scanf("%[^\n]",str);
    int i;
	int fd[2];	
	write(fd[1],str,strlen(str));
	printf("pid is %d for wiring in pipe - ",getpid());
	int y=strlen(str);
	printf("\n\n we have Written in pipe :%s\n",str);	
	for(i=0;i<strlen(str);i++)
		{
	     if(islower(str[i]))
	     {
	     	str[i]=toupper(str[i]);
		 }
		 else if(isupper(str[i]))
	     {
	     	str[i]=tolower(str[i]);
		 }
		}
	close(fd[0]);
	read(fd[0],str,strlen(str));
	printf("\n\npid is %d for reading in pipe ",getpid());
	printf("\n\n second string   :%s\n",str);
	
}
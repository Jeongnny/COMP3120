#include <stdio.h>

//lab4_1_Q2.c

int main(void){
	int pid;
	char c;	
	FILE * fp = fopen("lab4_1.txt", "a");
	if(fp == NULL)	{
		printf("lab4_1.txt open failed.\n");
		return 0;
	}
/*//file open check	
        while(c != EOF){
                c = fgetc(fp);
                putchar(c);
        }
        return 0;
*/
	pid = fork();
	
	if(pid < 0){		//fork error	
		printf("fork error!!\n");
		return 2;	
	}
	else if(pid == 0) {	//child process
/*//read a file
		printf("[child process] read lab4_1.txt\n");
        	while(c != EOF){
                	c = fgetc(fp);
                	putchar(c);
        	}
*/
		printf("child process] write lab4_1.txt\n");
		fputs("child process: hi I am child process\n", fp);
		printf("[child process] write hi...\n"); 
	}
	else{			//parent process
/*//read a file
		printf("[parent process] read lab4_1.txt\n");
        	while(c != EOF){
                	c = fgetc(fp);
                	putchar(c);
        	}
*/
		printf("[parent process] write lab4_1.txt\n");
		fputs("parent process: hi I am parent process\n", fp);
		printf("[parent process] write hi...\n");
	}
	
	fclose(fp);	
	return 0;
}

#include <stdio.h>
#include <sys/wait.h>

//lab4_1_Q3.c

int main(void) {
	int stat;
	int pid = fork();
	
	if(pid < 0){		//fork error	
		printf("fork error!!\n");
		return 1;	
	}
	else if(pid == 0) {	//child process
		printf("[child process] hello\n");
	}
	else{			//parent process
		while((waitpid(-1, &stat, WNOHANG) == 0));
		printf("[parent process] goodbye\n");
	}
	
	return 0;
}

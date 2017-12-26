#include <stdio.h>
#include <sys/wait.h>
//lab4_1_Q4.c

int main(void) {
	int stat;
	int pid = fork();
	
	if(pid < 0){		//fork error	
		printf("fork error!!\n");
		return 1;	
	}
	else if(pid == 0) {	//child process
		execl("/bin/ls", "./ls", "-a", 0);
		printf("[child process] hello\n");
	}
	else{			//parent process
		waitpid(-1, &stat, WNOHANG);
		printf("[parent process] goodbye\n");
	}
	
	return 0;
}



#include <stdio.h>
#include <sys/wait.h>
//lab4_1_Q5.c

int main(void) {
	int result, stat;
	int pid = fork();
	
	if(pid < 0){		//fork error	
		printf("fork error!!\n");
		return 1;	
	}
	else if(pid == 0) {	//child process
		result = wait(&stat);
		printf("result of 'wait': %d\n", result);
		printf("[child process] after fork, the process id: %d\n", (int)getpid());
		printf("[child process] hello\n");
	}
	else{			//parent process
//		result = wait(&stat);
		printf("[parent process] after fork, the process id: %d\n", (int)getpid());
	//	printf("result of 'wait'= %d\n", result);
		printf("[parent process] goodbye\n");
	}
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//lab4_1_Q6.c

int main(int ac, char **av) {
	int fd1[2], stat;
	int pid = fork(), pid2;
	
	if(pipe(fd1) == -1){
		fprintf(stderr, "pipe1 failed");
		return 1;
	}
	

	if(pid < 0){		//fork error	
		printf("fork error!!\n");
		return 1;	
	}
	else if(pid == 0) {	//child process pipe[0] == reading end.stdin == 0
		printf("[child-1 process] fileno(stdout) = %d\n", fileno(stdout));
		if(dup2(fd1[1], fileno(stdout)) == -1){
			printf("could not redirected stdout\n");
			return 3;
		}
		printf("fd[1] = %d/ stdout = %d\n", fd1[1], fileno(stdout));
		close(fd1[0]);
		close(fd1[1]);
	//	exit(4);
	}
	else{			//parent process
	//	wait(&stat);
		pid2 = fork();
		if(pid2 < 0) {
			printf("fork error\n");
			return 1;
		}
		else if(pid2 == 0){	//child process
			printf("[child-2 process] stdin = %d", fileno(stdin));
			dup2(fd1[0], fileno(stdin));
			printf("fd1[0] = %d/ stdin = %d\n", fd1[0], fileno(stdin));
			close(fd1[0]);
			close(fd1[1]);
	//		exit(5);		
		}
		else{			//parent process
//			printf("[parent process]\n");
		}
	}
	
//	printf("end\n");
	return 0;
}

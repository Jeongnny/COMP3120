#include <stdio.h>

//lab4_1_Q1.c

int main(void) {
	int x = 100;
	int pid = fork();
	
	if(pid < 0){		//fork error	
	}
	else if(pid == 0) {	//child process
		printf("[child process] x = %d", x);
		x = x + 5;
		printf("[child process] x + 5 = %d", x);
	}
	else{			//parent process
		printf("[parent process] x = %d", x);
		x = x + 10;
		printf("[parent process] x + 10 = %d", x);
	}
	
	return 0;
}

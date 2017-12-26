#include <stdio.h>

//lab4_1_Q1.c

int main(void) {
	int x = 100;
	int pid = fork();
	
	if(pid < 0){		//fork error	
	}
	else if(pid == 0) {	//child process
		printf("[child process] x = %d\n", x);
		x = x + 5;
		printf("[child process] x + 5 = %d\n", x);
	}
	else{			//parent process
		printf("[parent process] x = %d\n", x);
		x = x + 10;
		printf("[parent process] x + 10 = %d\n", x);
	}
	
	printf("result x = %d\n", x);

	return 0;
}

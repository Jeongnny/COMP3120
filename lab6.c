#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

char a[50], b[10], c[15], d[15], childid[10];
FILE *fp;
FILE *fp2;
int utime, stime;
int main(){
	int pid;
	int stat, i, j; 
	int  pi1, pi4, pi5, pi6, pi7;
	unsigned int pi8;
	long unsigned int  pi9, pi10, pi11, pi12, pi13, pi14, pi15;
	char pi2[10], pi3;
	char command1[50], command2[50];
	pid =fork();	
	switch(pid){
		case -1:
			printf("fork() error!!\n");
			return -1;
		case 0:
			printf("Enter a process id: ");
			scanf("%s", childid);
			strcpy(a, "/proc/");
			strcpy(b, childid);
			strcat(a, b);
			strcpy(command2, a);
			strcat(command2, "/stat");
			strcpy(command1, a);
			strcat(command1, "/status");
			//Read VmSize
			fp2 = fopen(command1, "r");
			if(fp2 == NULL) {
				printf("fp2 open error!!!\n");
				return 3;
			}
			else{
				for(j = 1; j < 500; j++) {
					fscanf(fp2,"%s", c);
					if(c[0] == 'V' && c[1] == 'm' && c[2] == 'S' && c[3] == 'i' && c[4] == 'z' && c[5] =='e'){
						printf("[%s process] %s ",childid, c);
						fscanf(fp2, "%s", c);
						printf("%s\n", c);
						sleep(2);
						fclose(fp2);
						break;
					}
				}
					 
			}
			while(1){
				fp = fopen(command2, "r");
				if(fp == NULL){
					printf("fopen error!!\n");
					return 2;
				}	 
				else{
					fscanf(fp, "%d %s %c %d %d %d %d %d %u %lu %lu %lu %lu %lu %lu", &pi1, pi2, &pi3, &pi4, &pi5, &pi6, &pi7, &pi8, &pi9, &pi10, &pi11, &pi12, &pi13, &pi14, &pi15);
					printf("=============================================================\n");
					printf("[%s process] utime = %lu stime = %lu\n", childid, pi14, pi15);
					printf("[%s process] total time = %lu\n", childid, 100*(pi14 + pi15));
				}
				fclose(fp);
				sleep(1);
			}
			exit(0);
		default:
			wait(&stat);
	}
}

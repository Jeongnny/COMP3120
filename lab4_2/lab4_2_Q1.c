#include <stdio.h>
#include <sys/time.h>

int main(void){
	int i;
	struct timeval start_t, end_t;
	gettimeofday(&start_t, NULL);
	
	for(i = 0; i < 9999999; i++){
		rand();
	}
	
	gettimeofday(&end_t, NULL);
	
	printf("gettimeofday()\n");
	printf("[start]      %f\n", (start_t.tv_sec + start_t.tv_usec) * 0.000001);
	printf("[end]        %f\n", (end_t.tv_sec + end_t.tv_usec) * 0.000001);
	printf("[difference] %f\n", (end_t.tv_sec + end_t.tv_usec - start_t.tv_sec - start_t.tv_usec) * 0.000001);
	
	return 0;
}



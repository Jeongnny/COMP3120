#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define BILLION 1000000000L

int main(void){
        int i;
//        struct timeval start_t, end_t;
//        gettimeofday(&start_t, NULL);
	struct timespec start_t, end_t;
	struct tm *ptm;
	uint64_t diff;

	clock_gettime(CLOCK_MONOTONIC, &start_t);	

        for(i = 0; i < 9999999; i++)
                rand();

//        gettimeofday(&end_t, NULL);
	clock_gettime(CLOCK_MONOTONIC, &end_t);

	printf("clock_gettime()\n");
        printf("[start]      %llu\n", (start_t.tv_sec + start_t.tv_nsec) * BILLION);
        printf("[end]        %llu\n", (end_t.tv_sec + end_t.tv_nsec) * BILLION);
        printf("[difference] %llu\n", ((end_t.tv_sec + end_t.tv_nsec)-(start_t.tv_sec + start_t.tv_nsec)) * BILLION); 

        return 0;
}

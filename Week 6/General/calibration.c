#include <stdio.h>
#include <time.h>
#include <sys/time.h>


//Based on testing, times less then 1E(-5) seconds are insignificant
int main(){
	struct timeval time;
	struct timeval time2;
	gettimeofday(&time, NULL);
	//printf("Testing\n");
	gettimeofday(&time2, NULL);
	double elapsedTime = (((double) time2.tv_sec) + ((double) time2.tv_usec)/1000000) - (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);

	printf("Elapsed time: %.16f seconds\n", elapsedTime); 
}

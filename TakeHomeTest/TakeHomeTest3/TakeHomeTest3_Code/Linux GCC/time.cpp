#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define SIZE 100000000
//function prototype
void ClearUsingIndex(int[], int);
void ClearUsingPointers(int *, int);

static int Array[SIZE];

main(int argc, char **argv)
{
	uint64_t time;
	//double time;
	double avg = 0.0;
	struct timespec start, end;
	for (int i=0; i<100; i++){
		clock_gettime(CLOCK_MONOTONIC, &start);

		//ClearUsingIndex(Array, SIZE);
		ClearUsingPointers(&Array[0],SIZE);

		//recorded end time
		clock_gettime(CLOCK_MONOTONIC, &end);

		timed = (end.tv_sec - start.tv_sec)*1000000000ULL + end.tv_nsec - start.tv_nsec;
		printf("time = %f ns\n", (double) timed);
		avg += timed;
	}
	avg/= 100;
	printf("size = %i, avg time = %f ns \n", SIZE, avg);
	return 0;
}


void ClearUsingIndex(int Array[], int size) {
	int i;
	for (i = 0; i < size; i++)
		Array[i] = 0;
}

void ClearUsingPointers(int *array, int size) {
	int *p;
	for (p = &array[0]; p<&array[size]; p = p + 1)
		*p = 0;
}



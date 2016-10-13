#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <ctype.h>
#include "mymalloc.h"

long average_times[6];

void testCaseA() {

	int a;
	char * work[3000];	

	for(a = 0; a < 3000; a++){

		char * testa = malloc(1);
		work[a] = testa;

	}
	for(; a >=0; a--){

		free(work[a]);

	}

}

void testCaseB() {

	int b;

	for(b = 0; b < 3000; b++){	

		char * testb = malloc(1);
		free(testb);

	}

}

void testCaseC() {

	char * work[3000];
	int malloc_index = 0, free_index = 0;
	int mallocs = 0, frees = 0;

	while (1) {

		int r = rand() % 2; //r=1=malloc, r=0=free
		
		if (mallocs == 3000) {

			r = 0;
			if (frees == 3000) {

				break;
			}
		}
	
		if (r) {

			char * testc = malloc(1);
			work[malloc_index] = testc;
			malloc_index++;
			mallocs++;

		} else {

			free(work[free_index]);
			if (free_index <= malloc_index) {

				free_index++;
				frees++;

			}

		}

	}

}

void testCaseD() {

	char * work[3000];
	int malloc_index = 0, free_index = 0;
	int mallocs = 0, frees = 0;

	while (1) {

		int r = rand() % 2; //r=1=malloc, r=0=free
		int rand_size = (rand() % 60) + 1;

		if (mallocs == 3000) {

			r = 0;
			if (frees == 3000) {

				break;

			}

		}
	
		if (r) {

			char * testd = malloc(rand_size);
			work[malloc_index] = testd;
			malloc_index++;
			mallocs++;

		} else {

			free(work[free_index]);
			if (free_index <= malloc_index) {
				
				free_index++;
				frees++;

			}

		}

	}

}

void testCaseE() {

	int e;

	for (e=0;e<3000;e++) {

		char * teste = malloc(e);
		free(teste);

	}

	for (;e>=0;e--) {
		char * teste = malloc(e);
		free(teste);
	}
	
}

void testCaseF() {

	int f;
	char * work[3000];
	char * str[] = {"hello", "hi", "goodbye"};

	for(f = 0; f < 3000; f++){
			
			int r = rand() % 3;
			char * segment = malloc(strlen(str[r])+1);

			if (segment != NULL) { 
				strcpy(segment, str[r]);
			}
			work[f] = segment;

	}
	
	for(f = 0; f < 3000; f++){

		free(work[f]);
 
	}
	
}

void setAverageElapsedTime(void (*function_to_call)(), char test_case) {
	
	long averageTime = 0;
	int total_runs = 100;
	int x = 0;
	
	for(;x<total_runs;x++) {
		
		struct timeval start, finish;
		gettimeofday(&start, NULL);

		(*function_to_call)();

		gettimeofday(&finish, NULL);

		averageTime += (long)(finish.tv_sec - start.tv_sec)*1000000L;
		averageTime += (long)(finish.tv_usec - start.tv_usec);	

		resetmyblock();
		
	}

	averageTime /= total_runs;
	average_times[test_case-97] = averageTime;
	
}

void printAverageElapsedTimes() {
	
	int i=0;
	
	for (;i<6;i++) {
		
		printf("Test Case %c Avg Time = %ld microseconds.\n", toupper(97+i), average_times[i]);
		
	}
	
}

int main(int argc, char * argv[]) {
	
	setAverageElapsedTime(&testCaseA, 'a');
	setAverageElapsedTime(&testCaseB, 'b');
	setAverageElapsedTime(&testCaseC, 'c');
	setAverageElapsedTime(&testCaseD, 'd');
	setAverageElapsedTime(&testCaseE, 'e');
	setAverageElapsedTime(&testCaseF, 'f');
	printAverageElapsedTimes();

	return 0;
	
}
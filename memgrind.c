#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "mymalloc.h"

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

}

void getAverageElapsedTime(void (*function_to_call)(), char test_case) {
	long averageTime = 0;
	int total_runs = 100;
	int x = 0;
	FILE * f = fopen("output.txt", "a");
	//setvbuf(f,NULL,_IONBF,0);
	
	for(;x<total_runs;x++) {
		struct timeval start, finish;
		gettimeofday(&start, NULL);

		(*function_to_call)();

		gettimeofday(&finish, NULL);
		averageTime += (long)(finish.tv_sec - start.tv_sec)*1000000L;
		averageTime += (long)(finish.tv_usec - start.tv_usec);	
	}

	averageTime /= total_runs;
	printf("Avg time for test case %c = %ld microseconds.\n",test_case, averageTime);
	fprintf(f, "Avg time for test case %c = %ld microseconds.\n",test_case, averageTime);
	fclose(f);
}

int main(int argc, char * argv[]) {
	
	getAverageElapsedTime(&testCaseA, 'A');
	getAverageElapsedTime(&testCaseB, 'B');
	getAverageElapsedTime(&testCaseC, 'C');
	getAverageElapsedTime(&testCaseD, 'D');
	getAverageElapsedTime(&testCaseE, 'E');
	getAverageElapsedTime(&testCaseF, 'F');

	return 0;
}


/*
		char * test1 = malloc(6);
		if (test1 != NULL) {
			test1[5] = '\0';
			test1[0] = 'a';
			test1[1] = 'b';
			test1[2] = 'c';
			test1[3] = 'd';
			test1[4] = 'e';
		}
		
		char * test2 = malloc(7);
		if (test2 != NULL) {
			test2[6] = '\0';
			test2[0] = 'f';
			test2[1] = 'g';
			test2[2] = 'h';
			test2[3] = 'i';
			test2[4] = 'j';
			test2[5] = 'k';
		}
		
		int * int_ptr = malloc(sizeof(int));
		if (int_ptr != NULL) {
			*int_ptr = 25;
		}
		
		printf("%s\n", (test1 != NULL) ? test1 : "");
		printf("%s\n", (test2 != NULL) ? test2 : "");
		printf("%d\n", (int_ptr != NULL) ? *int_ptr : -1);
		//free(test1);
		//free(test1);
		//free(test2);
		free(&x);
		
		char * myblock = getMyBlock();
		a = 0;
		for(; a<300; a++){
			
			printf("%d[%c %d %x]\n", a, myblock[a], myblock[a], myblock[a]);
			
		}*/
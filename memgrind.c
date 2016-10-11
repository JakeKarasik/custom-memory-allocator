#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "mymalloc.h"

void test_case_a() {
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

void test_case_b() {
	int a;

	for(a = 0; a < 3000; a++){		
		char * testb = malloc(1);
		free(testb);
	}
}

void test_case_c() {
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

void test_case_d() {
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

void test_case_e() {
	int a;

	for (a=0;a<3000;a++) {
		char * teste = malloc(a);
		free(teste);
	}

	for (;a>=0;a--) {
		char * teste = malloc(a);
		free(teste);
	}
}

void test_case_f() {
	return;
}

int main(int argc, char * argv[]) {
	
	long averageTime = 0;
	int total_runs = 100;
	int x;

	for(x = 0;x<total_runs;x++) {

		struct timeval  start, finish;
		gettimeofday(&start, NULL);
	
		test_case_a();

		gettimeofday(&finish, NULL);
		averageTime += (finish.tv_sec - start.tv_sec)*1000000L + finish.tv_usec - start.tv_usec;	
		
	}
	averageTime /= total_runs;
	printf("Avg time test case A = %ld\n",averageTime);

	averageTime = 0;

	for(x = 0;x<total_runs;x++) {
		
		struct timeval  start, finish;
		gettimeofday(&start, NULL);
	
		test_case_b();

		gettimeofday(&finish, NULL);
		averageTime += (finish.tv_sec - start.tv_sec)*1000000L + finish.tv_usec - start.tv_usec;	
		
	}
	averageTime /= total_runs;
	printf("Avg time test case B = %ld\n",averageTime);

	averageTime = 0;

	for(x = 0;x<total_runs;x++) {
		
		struct timeval  start, finish;
		gettimeofday(&start, NULL);
	
		test_case_c();

		gettimeofday(&finish, NULL);
		averageTime += (finish.tv_sec - start.tv_sec)*1000000L + finish.tv_usec - start.tv_usec;	
		
	}
	averageTime /= total_runs;
	printf("Avg time test case C = %ld\n",averageTime);

	averageTime = 0;

	for(x = 0;x<total_runs;x++) {
		
		struct timeval  start, finish;
		gettimeofday(&start, NULL);
	
		test_case_d();

		gettimeofday(&finish, NULL);
		averageTime += (finish.tv_sec - start.tv_sec)*1000000L + finish.tv_usec - start.tv_usec;	
		
	}
	averageTime /= total_runs;
	printf("Avg time test case D = %ld\n",averageTime);

	averageTime = 0;

	for(x = 0;x<total_runs;x++) {
		
		struct timeval  start, finish;
		gettimeofday(&start, NULL);
	
		test_case_e();

		gettimeofday(&finish, NULL);
		averageTime += (finish.tv_sec - start.tv_sec)*1000000L + finish.tv_usec - start.tv_usec;	
		
	}
	averageTime /= total_runs;
	printf("Avg time test case E = %ld\n",averageTime);

	averageTime = 0;

	for(x = 0;x<total_runs;x++) {
		
		struct timeval  start, finish;
		gettimeofday(&start, NULL);
	
		test_case_f();

		gettimeofday(&finish, NULL);
		averageTime += (finish.tv_sec - start.tv_sec)*1000000L + finish.tv_usec - start.tv_usec;	
		
	}
	averageTime /= total_runs;
	printf("Avg time test case F = %ld\n",averageTime);


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
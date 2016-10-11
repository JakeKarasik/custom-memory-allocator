#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "mymalloc.h"


int main(int argc, char * argv[]) {
	
	
	int a;
	int malloc_index = 0, free_index = 0;
	char* work[3000];
	int mallocs = 0, frees = 0;
	long averageTime = 0;
	int x;
	for(x = 0;x<100;x++) {
		struct timeval  start, finish;
		gettimeofday(&start, NULL);
	
	
	/*
	char * test1 = mymalloc(sizeof(char)*6);
	test1[5] = '\0';
	test1[0] = 'a';
	test1[1] = 'b';
	test1[2] = 'c';
	test1[3] = 'd';
	test1[4] = 'e';
	
	
	char * test2 = mymalloc(sizeof(char)*7);
	test2[6] = '\0';
	test2[0] = 'f';
	test2[1] = 'g';
	test2[2] = 'h';
	test2[3] = 'i';
	test2[4] = 'j';
	test2[5] = 'k';
	
	
	int * int_ptr = mymalloc(sizeof(int));
	*int_ptr = 25;
	
	printf("%s\n", test1);
	printf("%s\n", test2);
	printf("%d\n", *int_ptr);
	myfree(test1);
	myfree(test1);
	myfree(test2);
	myfree(&i);
	
	
	a = 1;
	for(; i<300; i++){
		
		printf("%d[%c %d %x]\n", i, myblock[i], myblock[i], myblock[i]);
		
	}
	
	metadata * first = (metadata *)myblock;
	a = 0;
	for(; first != NULL; first=first->next,j++){
		
		printf("%d[%c]\n", j,first+1);
		
	}
	
	a = 0;
	for(; first != NULL; first=first->next,j++){
		
		printf("%d[%c]\n", j,first+1);
		
	}
	





	
	///Spec Test Case 1///
	
	for(a = 0; a < 3000; a++){
		
		char * testa = mymalloc(sizeof(char *));
		work[a] = testa;
		
	}
	for(; a >=0; a--){
		
		myfree(work[a]);
		
	}
	
	///Spec Test Case 2///
	
	for(a = 0; a < 3000; a++){
		
		char * testb = mymalloc(sizeof(char *));
		myfree(testb);
		
	}*/
	
	
	///Spec Test Case 3///
	/*
	while (1) {
		int r = rand() % 2; //r=1=malloc, r=0=free
		
		if (mallocs == 3000) {
			r = 0;
			if (frees == 3000) {
				break;
			}
		}
	
		if (r) {
			char * testc = mymalloc(sizeof(char *));
			work[malloc_index] = testc;
			malloc_index++;
			mallocs++;
		} else {
			myfree(work[free_index]);
			if (free_index <= malloc_index) {
				free_index++;
				frees++;
			}
		}
	}
	*/

	///Spec Test Case 4///
	
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
			char * testd = mymalloc(rand_size);
			work[malloc_index] = testd;
			malloc_index++;
			mallocs++;
		} else {
			myfree(work[free_index]);
			if (free_index <= malloc_index) {
				free_index++;
				frees++;
			}
		}
	}
	
	gettimeofday(&finish, NULL);
	averageTime += (finish.tv_sec - start.tv_sec)*1000000L + finish.tv_usec - start.tv_usec;	
	
	}
	averageTime /= 100;
	printf("Avg time = %ld\n",averageTime);
	return 0;
}
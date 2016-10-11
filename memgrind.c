#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "mymalloc.h"

int main(int argc, char * argv[]) {
	
	struct timeval  start, finish;
	int a;
	int index;
	char* work[3000];
	int mall = 0;
	
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
		
		char * testa = mymalloc(1);
		work[a] = testa;
		
	}
	for(; a >=0; a--){
		
		myfree(work[a]);
		
	}
	
	///Spec Test Case 2///
	
	for(a = 0; a < 3000; a++){
		
		char* testb = mymalloc(1);
		myfree(testb);
		
	}
	
	*/
	///Spec Test Case 3///
	
	index = 10;
	for(a = 0; a < 6000; a++){
		
		
		int r = rand() % 2;
		if(mall < 3000){
			
			if(r == 0){
				
				
				char* testc = mymalloc(1);
				work[index] = testc;
				mall++;
				index++;
				
			}else if(r == 1){
				
				if(index <= 0){
					
					index = 1;
					
				}
				int R = rand() % index;
				myfree(work[R]);
				index--;
				
			}
			
		}else{
			
			a = index;
			for(; a > 9; a--){
				
				free(work[a]);
				
			}
			
		}
		
	}
	
	gettimeofday(&finish, NULL);
	printf("Time - %ld - microseconds\n",
			(finish.tv_sec - start.tv_sec)*1000000L
			+ finish.tv_usec - start.tv_usec
			);
			
	return 0;
}
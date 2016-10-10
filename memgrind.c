#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mymalloc.h"

int main(int argc, char * argv[]) {
	
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
	
	node * testNode = mymalloc(sizeof(node));
	testNode->test = 1;
	//testNode->word = mymalloc(3);
	//strcpy(testNode->word,"hi");
	

	printf("%s\n", test1);
	printf("%s\n", test2);
	
	printf("%d\n", *int_ptr);
	printf("%d\n",testNode->test);//testNode->word);


	int i =1;
	for(; i<300; i++){
		
		printf("%d[%c %d %x]\n", i, myblock[i], myblock[i], myblock[i]);
		
	}
	myfree(test1);

	metadata * first = (metadata *)myblock;

	
	int j =0;
	for(; first != NULL; first=first->next,j++){
		
		printf("%d[%c]\n", j,first+1);
		
	}
	myfree(test1);

	
	j =0;
	for(; first != NULL; first=first->next,j++){
		
		printf("%d[%c]\n", j,first+1);
		
	}
	myfree(test1);
	myfree(&i);*/
/*
	int j;
	for(j = 0; j < 2000; j++){
		char * ptr = mymalloc(sizeof(char *));
		if (ptr != NULL) {
			*ptr = 'a';
		printf("%d[%c]\n",j,*ptr);
		
		}
		if (j % 2 == 0) myfree(ptr);
		
		
	}*/
	char * test1 = mymalloc(2460);
		printf("---\n");

	char * test2 = mymalloc(2477);

	myfree(test1);
	myfree(test2);
	return 0;
}
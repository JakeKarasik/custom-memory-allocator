//#define malloc(x) mymalloc(x, __FILE__, __LINE__)
//#define free(x) myfree(x, __FILE__, __LINE__)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//******Structs*******//
typedef struct tag_ {
	int is_set;
	int size;
} tag;

//****Global Vars****//
static char myblock[5000];
static tag address_list[5000];
static int current_index = 0;

//*****Prototypes*****//
void * mymalloc(int size);
void myfree(void * ptr);

//*****Functions*****//
void * mymalloc(int size) {
	tag new_tag = {1, size};
	int returnIndex = current_index;
	address_list[current_index] = new_tag;

	int i;
	for (i=1;i<size;i++) {
		tag spacer_tag = {1, size-i};
		address_list[current_index+i] = spacer_tag;
	}

	if (current_index == 4999) {

		current_index = 0;

	} else {

		current_index += size;

	}

	return &myblock[returnIndex];
}

void myfree(void * ptr) {
	int position = abs((char *)ptr - (char *)&myblock[0]);
	int size = address_list[position].size;
	int i;
	for (i=0;i<size;i++) {
		tag clean_tag = {0,0};
		address_list[position+i] = clean_tag;
	} 
}

void printMem(int max_print_index) {
	int i;
	for (i=max_print_index;i>=0;i--) {
		printf("myblock[%d]=%d\n",i,myblock[i]);
	}
}

void printTags(int max_print_index) {
	int i;
	for (i=max_print_index;i>=0;i--) {
		printf("address_list[%d]\n",i);
		printf("\tis_set: %d\n", address_list[i].is_set);
		printf("\tsize: %d\n", address_list[i].size);
	}
}

void printArraysAsPicture(int max_print_index) {
	printf("myblock:\taddress_list:\n");
	int i;
	for (i=max_print_index;i>=0;i--) {
			printf("%5d[%d]\t",i,myblock[i]);
			printf("%5d[%s]\n",i,address_list[i].is_set ? "x" : " ");
	}
}
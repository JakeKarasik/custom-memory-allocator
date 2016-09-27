//#define malloc(x) mymalloc(x, __FILE__, __LINE__)
//#define free(x) myfree(x, __FILE__, __LINE__)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//******Structs*******//
typedef struct tag_ {
	int is_set;
	int size;
	int index;
} tag;

//****Global Vars****//
static char myblock[5000];
static tag address_list[5000];
static int current_index = 0;

//*****Prototypes*****//
void * mymalloc(int size);
void myfree(char * ptr);

//*****Functions*****//
void * mymalloc(int size) {
	tag new_tag;
	new_tag.is_set = 1;
	new_tag.size = size;
	new_tag.index = current_index;
	address_list[current_index] = new_tag;

	if (current_index == 4999) {

		current_index = 0;

	} else {

		current_index += size;

	}

	return &myblock[new_tag.index];
}

void myfree(char * ptr) {
	
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
		printf("\tindex: %d\n", address_list[i].index);
	}
}
//#define malloc(x) mymalloc(x, __FILE__, __LINE__)
//#define free(x) myfree(x, __FILE__, __LINE__)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MEM_CAP 5000


//****Structs*****//
typedef struct metadata_{
	
	int is_set;
	int size;
	long id;
	struct metadata_ * prev, * next;
	
}metadata;

typedef struct node_ {
	
	int test;
	char * word;
	
}node;

//*****Prototypes*****//
void * mymalloc(size_t size);
void myfree(void * ptr);

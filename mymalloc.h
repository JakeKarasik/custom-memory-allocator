//#define malloc(x) mymalloc(x, __FILE__, __LINE__)
//#define free(x) myfree(x, __FILE__, __LINE__)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MEM_SIZE 5000

//******Structs******//
typedef struct metadata_ {
	int size;
	int is_set;
	struct metadata_ * prev, * next;
} metadata;

//*****Prototypes*****//
void * mymalloc(size_t size);
void myfree(void * ptr);
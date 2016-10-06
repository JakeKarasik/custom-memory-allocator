//#define malloc(x) mymalloc(x, __FILE__, __LINE__)
//#define free(x) myfree(x, __FILE__, __LINE__)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//*****Prototypes*****//
void * mymalloc(size_t size);
void myfree(void * ptr);
int nextOpenSpot(size_t size);
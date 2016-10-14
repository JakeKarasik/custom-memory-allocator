//Jake Karasik
//Nicholas Petriello
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mymalloc.h"

//****Global Vars****//
static char myblock[MEM_CAP]; //Storage memory
int remaining_space = MEM_CAP; //Bytes left to allocate
int successful_mallocs = 0;
int successful_frees = 0;

//*****Functions*****//

/****
resetmyblock()
	Sets the memory back to its original empty space 
	so that we may run the tests without overlapping 
	of workloads affecting program times.
****/
void resetmyblock() {
	memset(myblock, 0, MEM_CAP);
	remaining_space = MEM_CAP;
	successful_mallocs = 0;
	successful_frees = 0;
}

/****
getSuccessfulMallocs()
	Returns value of global variable that tracks successful mallocs.
****/
int getSuccessfulMallocs() {
	return successful_mallocs;
}

/****
getSuccessfulFrees()
	Returns value of global variable that tracks successful frees.
****/
int getSuccessfulFrees() {
	return successful_frees;
}

/****
mymalloc()
	Takes in a size and returns a pointer to allocated 
	memory space. If the size is zero, less than 0 or too 
	large, a null pointer is returned. It creates a 
	metadata pointer that traverses a linked list delineating 
	memory blocks and finds an available block. If a list 
	doesn’t exist, a head is made and starts it. It also 
	sets the properties for each metadata struct in the list. 
****/
void * mymalloc(size_t size, char * file, int line){

	if (size < 0 || size > MEM_CAP) {
		printf("Error: Invalid size memory request.\n");
		return NULL;
	}	
	
	if (size == 0) {

		return NULL;

	}

	int curr_index = 0;
	metadata * curr = (metadata *)myblock;
	
	while(curr != NULL){

		if(curr->is_set == 0 && curr->size >= size){ //valid block found and block was initialized
			
			curr_index += size + sizeof(metadata);

			curr->is_set = 1;

			successful_mallocs++;

			return &myblock[curr_index-size];

		} else if (curr->is_set == 0 && curr->size == 0) { //valid block found and block was never initialized

			if(remaining_space < size + sizeof(metadata)){
		
				//printf("[%s, line %d] Error: Not enough memory left to allocate.\n", file, line);

				return NULL;
				
			} else {

				curr_index += size + sizeof(metadata);

				remaining_space = remaining_space - sizeof(metadata) - size;

				if (remaining_space >= FINAL_BLOCK_THRESHOLD + sizeof(metadata)) {

					metadata * next_block = (metadata *)(&myblock[curr_index]);
					next_block->is_set = 0;
					next_block->size = 0;
					next_block->id = UNIQUE_ID;
					next_block->next = NULL;

					curr->next = next_block;

				} else {

					curr->next = NULL;

				}

				curr->is_set = 1;
				curr->size = size;
				curr->id = UNIQUE_ID;

				successful_mallocs++;

				return &myblock[curr_index-size];

			}
		} else {

			curr_index += sizeof(metadata) + curr->size;
			curr = curr->next;

		}
	}

	//printf("[%s, line %d] Error: Not enough continuous memory available.\n", file, line);

	return NULL;
	
}

/****
myfree()
	Sets the is_set property in the metadata for the 
	passed in pointer so that it is deemed available 
	space by mymalloc. If a null value or already free 
	pointer is given, then an error is printed. This 
	function checks if the unique id defined in mymalloc.h
	is set to ensure the passed in pointer is valid.
****/
void myfree(void * ptr, char * file, int line){

	if (ptr == NULL) {

		printf("[%s, line %d] Error: Attempting to free NULL pointer.\n", file, line);

		return;
	}

	metadata * to_free = (metadata * )(ptr - sizeof(metadata));

	if (to_free->id == UNIQUE_ID && to_free->is_set == 1) {

		to_free->is_set = 0;
		
		successful_frees++;

	} else if (to_free->id == UNIQUE_ID && to_free->is_set == 0) {
		
		printf("[%s, line %d] Error: Pointer was already free'd.\n", file, line);
		
	} else {
		
		printf("[%s, line %d] Error: Invalid free.\n", file, line);
		
	}
	
}
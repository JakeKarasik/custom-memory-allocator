//Jake Karasik
//Nicholas Petriello
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mymalloc.h"

//_____Global Vars_____//
static char myblock[MEM_CAP]; //Storage memory
int remaining_space = MEM_CAP; //Bytes left to allocate
int successful_mallocs = 0; //Tracks succesful mallocs
int successful_frees = 0; //Tracks succesful frees

//_____Functions_____//

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

	//Invalid size returns error message and null
	if (size < 0 || size > MEM_CAP) {
		printf("Error: Invalid size memory request.\n");
		return NULL;
	}	
	
	//Allocation of size 0 returns null
	if (size == 0) {

		return NULL;

	}

	int curr_index = 0; //Set index to start of array
	metadata * curr = (metadata *)myblock; //Cast first chuck of memory as metadata struct
	
	//Loop through block of memory like linked list
	while(curr != NULL){

		//Valid block found and block was initialized
		if(curr->is_set == 0 && curr->size >= size){ 
			
			curr_index += size + sizeof(metadata); //Adjust index in prep to return memory

			curr->is_set = 1; //About to return memory, so mark as set

			successful_mallocs++; //Store for later access

			return &myblock[curr_index-size];

		//Valid block found and block was never initialized
		} else if (curr->is_set == 0 && curr->size == 0) { 

			//Not enough memory left to allocate
			if(remaining_space < size + sizeof(metadata)){

				return NULL;
			
			//Enough memory, prepare to allocate
			} else {

				curr_index += size + sizeof(metadata); //Adjust index in prep to return memory

				remaining_space = remaining_space - sizeof(metadata) - size; //Adjust remaining space for future mallocs

				//Create/initialize next metadata struct if enough space otherwise mark next as null
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

				curr->is_set = 1; //About to return memory, so mark as set
				curr->size = size; //Set size of block
				curr->id = UNIQUE_ID; //Set unique id from mymalloc.h

				successful_mallocs++; //Store for later access

				return &myblock[curr_index-size];

			}
		} else {
			//Move to next struct in memory block
			curr_index += sizeof(metadata) + curr->size;
			curr = curr->next;

		}
	}

	//Not enough continuous memory available
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

	//Pointer is null
	if (ptr == NULL) {

		printf("[%s, line %d] Error: Attempting to free NULL pointer.\n", file, line);

		return;
	}

	metadata * to_free = (metadata * )(ptr - sizeof(metadata)); //Select metadata struct

	//Valid free
	if (to_free->id == UNIQUE_ID && to_free->is_set == 1) {

		to_free->is_set = 0; //Mark as free
		
		successful_frees++; //Store for later access

	//Pointer already free'd
	} else if (to_free->id == UNIQUE_ID && to_free->is_set == 0) {
		
		printf("[%s, line %d] Error: Pointer was already free'd.\n", file, line);
		
	//Invalid free
	} else {
		
		printf("[%s, line %d] Error: Invalid free.\n", file, line);
		
	}
	
}
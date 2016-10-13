//Jake Karasik
//Nicholas Petriello
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mymalloc.h"

//****Global Vars****//
static char myblock[MEM_CAP]; //Storage memory
int remaining_space = MEM_CAP; //Bytes left to allocate

//*****Functions*****//
void resetmyblock() {//this resets the block so that it can be allocated a workload
	
	memset(myblock, 0, MEM_CAP);
	remaining_space = MEM_CAP;
	
}

void * mymalloc(size_t size, char * file, int line){//custom malloc
	
	if (size == 0) {//allocation of size 0 returns a null ptr

		return NULL;

	}

	int curr_index = 0;//keeps track of the part of memory that is currently being used
	
	metadata * curr = (metadata *)myblock;//this is the ptr metadata node that is used to traverse the list
	
	while(curr != NULL){//this loops through the list of nodes of metadata

		if(curr->is_set == 0 && curr->size >= size){ //valid block found and block was initialized
			
			curr_index += size + sizeof(metadata);
			curr->is_set = 1;

			//printf("Pointer successfully malloc'd.\n");

			return &myblock[curr_index-size];

		} else if (curr->is_set == 0 && curr->size == 0) { //valid block found and block was never initialized

			if(remaining_space < size + sizeof(metadata)){//executes when there is no more space left to allocate
		
				//printf("[%s, line %d] Error: Not enough memory left to allocate.\n", file, line);

				return NULL;
				
			} else {//sets up a new metadata node in the linked list

				curr_index += size + sizeof(metadata);

				remaining_space = remaining_space - sizeof(metadata) - size;

				if (remaining_space >= FINAL_BLOCK_THRESHOLD + sizeof(metadata)) {

					metadata * next_block = (metadata *)(&myblock[curr_index]);
					next_block->is_set = 0;
					next_block->size = 0;
					next_block->id = UNIQUE_ID;
					next_block->next = NULL;
					curr->next = next_block;

				} else {//goes to the next metadata node

					curr->next = NULL;

				}

				curr->is_set = 1;
				curr->size = size;
				curr->id = UNIQUE_ID;

				//printf("Pointer successfully malloc'd.\n");

				return &myblock[curr_index-size];

			}
		} else {

			//printf("Not saving here... moving to next block.\n");

			curr_index += sizeof(metadata) + curr->size;
			curr = curr->next;

		}
	}

	//printf("[%s, line %d] Error: Not enough continuous memory available.\n", file, line);

	return NULL;
	
}

void myfree(void * ptr, char * file, int line){//custom free

	if (ptr == NULL) {//returns error for invalid memory addresses

		printf("[%s, line %d] Error: Attempting to free NULL pointer.\n", file, line);

		return;
	}

	metadata * to_free = (metadata * )(ptr - sizeof(metadata));//ptr to traverse link list

	if (to_free->id == UNIQUE_ID && to_free->is_set == 1) {//just sets the metadata is_set to free or not free

		to_free->is_set = 0;
		
		//printf("Successfully free'd\n");

	} else if (to_free->id == UNIQUE_ID && to_free->is_set == 0) {
		
		printf("[%s, line %d] Error: Pointer was already free'd.\n", file, line);
		
	} else {
		
		printf("[%s, line %d] Error: Invalid free.\n", file, line);
		
	}
	
}
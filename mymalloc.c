//Jake Karasik
//Nicholas Petriello
#include "mymalloc.h"

//*((int*)ptr) = 5006;
//printf("%d", *ptr);

//****Global Vars****//
static char myblock[MEM_CAP]; //Storage memory
int remaining_space = MEM_CAP; //Bytes left to allocate

//*****Functions*****//
void * mymalloc(size_t size){
	if(remaining_space < size + sizeof(metadata)){
		
		printf("Error: Not enough memory left to allocate.\n");
		return NULL;
		
	}	

	int curr_index = 0;
	metadata * curr = (metadata *)myblock;
	
	while(curr != NULL && curr_index < MEM_CAP){
		//printf("sizeofmetadata=%d,curr_index=%d\n",(int)sizeof(metadata),curr_index);
		//valid block found
		//printf("curr->is_set=%d,curr->size=%d\n",curr->is_set,curr->size);
		if(curr->is_set == 0 && curr->size >= size){ //block was initialized
			//printf("Saving here, block was initialized\n");

			//printf("Pointer returned at index %d\n",curr_index+(int)sizeof(metadata));
			curr_index += size + sizeof(metadata);
			curr->is_set = 1;

			remaining_space -= sizeof(metadata) + size;
			return curr + (int)sizeof(metadata);
		} else if (curr->is_set == 0 && curr->size == 0) { //block was never initialized
			//printf("Saving here, block was never initialized.\n");
			//if head not set, mark as set
			if (curr_index == 0) {
				curr->prev = NULL;
			}
			metadata * next_block = (metadata *)(&myblock[curr_index+sizeof(metadata)]);
			//printf("Pointer returned at index %d\n",curr_index+(int)sizeof(metadata));
			curr_index += size + sizeof(metadata);

			next_block->is_set = 0;
			next_block->size = 0;
			next_block->id = 0xdaedbeaf;
			next_block->prev = curr;
			next_block->next = NULL;

			curr->next = next_block;
			curr->is_set = 1;
			curr->size = size;
			curr->id = 0xdaedbeaf;

			remaining_space -= sizeof(metadata) + size;
			return curr + (int)sizeof(metadata);
		} else {
			//printf("Not saving here... moving to next block.\n");
			curr_index += sizeof(metadata) + curr->size;
			curr = curr->next;
		}
	}
	printf("Error: Not enough continuous memory available.\n");
	return NULL;
	
}

void myfree(void * ptr){
	metadata * to_free = (metadata * )(ptr - sizeof(metadata));
	printf("struct {is_set=%d,size=%d,id=%ld}\n",to_free->is_set,to_free->size,to_free->id);

	if (to_free->id == 0xdaedbeaf && to_free->is_set == 1) {

		to_free->is_set = 0;
		remaining_space += to_free->size;

	} else if (to_free->id == 0xdaedbeaf && to_free->is_set == 0) {
		
		printf("Error: Pointer was already free'd\n");
		
	} else {
		
		printf("Error: Invalid free!\n");
		
	}
	
}

int main(int argn, char* argv[]){
	
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
	testNode->word = mymalloc(3);
	strcpy(testNode->word,"hi");
	

	printf("%s\n", test1);
	printf("%s\n", test2);
	printf("%d\n", *int_ptr);
	printf("%d,%s\n",testNode->test,testNode->word);

	int i;
	for(i = 0; i < 30; i++){
		
		printf("%d[%c]\n", i,myblock[i]);
		
	}
	myfree(test1);

	for(i = 0; i < 30; i++){
		
		printf("%d[%c]\n", i,myblock[i]);
		
	}
	myfree(test1);
	myfree(&i);
/*
	int j;
	for(j = 0; j < 2000; j++){
		char * ptr = mymalloc(1);
		if (ptr != NULL) {
			*ptr = 'a';
		printf("%d[%c]\n",j,*ptr);
		}
		
		
	}*/
	return 0;
	
}
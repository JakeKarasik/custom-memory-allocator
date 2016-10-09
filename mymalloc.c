//Jake Karasik
//Nicholas Petriello
#include "mymalloc.h"

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
	
	while(curr != NULL){
		//printf("curr->is_set=%d,curr->size=%d\n",curr->is_set,curr->size);


		if(curr->is_set == 0 && curr->size >= size){ //valid block found and block was initialized

			printf("Saving here, block was initialized\n");

			
			curr_index += size + sizeof(metadata);
			printf("Pointer returned at index %d\n",curr_index-(int)size);
			curr->is_set = 1;

			remaining_space -= sizeof(metadata) + size;

			return &myblock[curr_index-size];

		} else if (curr->is_set == 0 && curr->size == 0) { //valid block found and block was never initialized
			printf("Saving here, block was never initialized.\n");
			//if head not set, mark as set
			if (curr_index == 0) {
				curr->prev = NULL;
			}

			curr_index += size + sizeof(metadata);

			printf("Pointer returned at index %d\n",curr_index-(int)size);

			remaining_space -= sizeof(metadata) + size;

			if (remaining_space >= FINAL_BLOCK_THRESHOLD) {
				metadata * next_block = (metadata *)(&myblock[curr_index]);
				next_block->is_set = 0;
				next_block->size = 0;
				next_block->id = 0xdaedbeaf;
				next_block->prev = curr;
				next_block->next = NULL;

				curr->next = next_block;
			} else {
				curr->next = NULL;
			}

			curr->is_set = 1;
			curr->size = size;
			curr->id = 0xdaedbeaf;

			return &myblock[curr_index-size];

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

	if (ptr == NULL) {
		return;
	}

	metadata * to_free = (metadata * )(ptr - sizeof(metadata));
	//printf("struct {is_set=%d,size=%d,id=%ld}\n",to_free->is_set,to_free->size,to_free->id);

	if (to_free->id == 0xdaedbeaf && to_free->is_set == 1) {

		to_free->is_set = 0;
		remaining_space += to_free->size + sizeof(metadata);

	} else if (to_free->id == 0xdaedbeaf && to_free->is_set == 0) {
		
		printf("Error: Pointer was already free'd\n");
		
	} else {
		
		printf("Error: Invalid free!\n");
		
	}
	
}

int main(int argc, char* argv[]){
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

	int j;
	for(j = 0; j < 2000; j++){
		char * ptr = mymalloc(sizeof(char *));
		if (ptr != NULL) {
			*ptr = 'a';
		printf("%d[%c]\n",j,*ptr);
		
		}
		if (j % 2 == 0) myfree(ptr);
		
		
	}
	return 0;
	
}
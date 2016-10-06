//Jake Karasik
//Nicholas Petriello
#include "mymalloc.h"

//*((int*)ptr) = 5006;
//printf("%d", *ptr);

//****Global Vars****//
static char myblock[MEM_CAP];
int remaining_space = MEM_CAP;
int curr_index = 0;
int head_used = 0;
metadata * head = (metadata*)myblock;

//*****Functions*****//
void * mymalloc(size_t size){
	
	//printf("CURRENT INDEX %d\n", curr_index);
	if(remaining_space < size + sizeof(metadata)){
		
		printf("Error: Not enough memory left to allocate.\n");
		return NULL;
		
	}
	
	if (!head_used) {
		head->is_set = 0;
		head->size = 0;
		head->prev = NULL;
		head->next = NULL;
		remaining_space -= sizeof(metadata);
		curr_index += sizeof(metadata);
		head_used = 1;
	}
	
	metadata * curr = head;
	
	while(curr != NULL){
		
		//valid block found
		if((curr->is_set == 0 && curr->size >= size) || (curr->is_set == 0 && curr->size == 0)){
			//if head not set, mark as set
			if (curr_index == 0) {
				head_used = 1;
			}
			metadata * new_block = (metadata *)(&myblock[curr_index+size]);
			curr_index += size + sizeof(metadata);
			new_block->is_set = 0;
			new_block->size = 0;
			new_block->prev = curr;
			new_block->next = NULL;
			curr->next = new_block;
			curr->is_set = 1;
			remaining_space -= sizeof(metadata) + size;
			//printf("SPACE REM %d\n", remaining_space);
			//curr_index += sizeof(metadata) + size;
			//printf("CURRENT INDEX %d\n", curr_index);
			printf("SUCCESSFUL MALLOC\n");
			return curr + 1;
			
		}else{
			
			curr = curr->next;
			
		}
		
	}
	printf("Error: Not enough continuous memory available.\n");
	return NULL;
	
}

void myfree(void * ptr){
	
	return;
}

int main(int argn, char* argv[]){
	
	printf("START\n");
	
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
	//printf("%d\n", *int_ptr);
	printf("%d,%s\n",testNode->test,testNode->word);
	int i;
	for(i = 0; i < 200; i++){
		
		printf("%d[%c]\n", i,myblock[i]);
		
	}
	
	return 0;
	
}
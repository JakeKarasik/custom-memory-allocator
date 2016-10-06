//Jake Karasik
//Nicholas Petriello
#include "mymalloc.h"

//*((int*)ptr) = 5006;
//printf("%d", *ptr);

//****Global Vars****//
static char myblock[MEM_SIZE];
int remaining_space = MEM_SIZE;

//*****Functions*****//
void * mymalloc(size_t size) {

	if (size+sizeof(metadata) > remaining_space) {
		printf("Error: Not enough memory remaining to allocate.\n");
		return NULL;
	}

	metadata * curr_node;
	for (curr_node = (metadata *)&myblock[0];curr_node != NULL;curr_node = curr_node->next) {
		if (curr_node->is_set == 0 && curr_node->next == NULL) {
			if (curr_node->size == 0) {
				metadata * end_node = {0,0,curr_node,NULL};
				curr_node->size = size;
				curr_node->is_set = 1;
				curr_node->next = curr_node->next->is_set ? curr_node->next : end_node;
				return curr_node+1; //?should it be +1?
			} else if (size <= curr_node->size) { //
				metadata * end_node = ;
				curr_node->is_set = 1;
				curr_node->next = curr_node->next->is_set ? curr_node->next : end_node;
				return curr_node+1; //should it be +1?
			}
		}
	}	

	return NULL;
}

void myfree(void * ptr) {
	/*
	int position = abs((char *)ptr - (char *)&myblock[0]);
	int size = address_list[position].size;
	int i;
	for (i=0;i<size;i++) {
		tag clean_tag = {0,0};
		address_list[position+i] = clean_tag;
	}*/
}

int main(int argc, char * argv[]) {
	/*
	//test mymalloc of string
	char * set_string = "hello";
	char * a_string = mymalloc(strlen(set_string)+1);
	strcpy(a_string,set_string);
	printf("%s\n",a_string);
	
	//test mymalloc of int
	int	set_int = 5;
	int * a_int = mymalloc(sizeof(int));
	*a_int = set_int;
	printf("%d\n",*a_int);
*/
	return 0;
}
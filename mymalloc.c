//Jake Karasik
//Nicholas Petriello
#include "mymalloc.h"

//*((int*)ptr) = 5006;
//printf("%d", *ptr);

//****Global Vars****//
static char myblock[5000];
int current_index = 0;

//*****Functions*****//
int nextOpenSpot(size_t size) {

	int i;
	for (i=current_index;i<5000;i++) {
		if () {

		}
	}
}

void * mymalloc(size_t size) {
	int return_address = &myblock[current_index];

	

	return return_address;
}

void myfree(void * ptr) {
	int position = abs((char *)ptr - (char *)&myblock[0]);
	int size = address_list[position].size;
	int i;
	for (i=0;i<size;i++) {
		tag clean_tag = {0,0};
		address_list[position+i] = clean_tag;
	}
}

void printMem(int max_print_index) {
	int i;
	for (i=max_print_index;i>=0;i--) {
		printf("myblock[%d]=%d\n",i,myblock[i]);
	}
}

void printTags(int max_print_index) {
	int i;
	for (i=max_print_index;i>=0;i--) {
		printf("address_list[%d]\n",i);
		printf("\tis_set: %d\n", address_list[i].is_set);
		printf("\tsize: %d\n", address_list[i].size);
	}
}

void printArraysAsPicture(int max_print_index) {
	printf("myblock:\taddress_list:\n");
	int i;
	for (i=max_print_index;i>=0;i--) {
			printf("%5d[%d]\t",i,myblock[i]);
			printf("%5d[%s]\n",i,address_list[i].is_set ? "x" : " ");
	}
}


int main(int argc, char * argv[]) {
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

	//print view of memory and tag list
	///printArraysAsPicture(10);
	//myfree(a_string);
	//myfree(a_int);
	//printf("---------\n");
	//printArraysAsPicture(10);

	return 0;
}
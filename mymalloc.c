//Jake Karasik
//Nicholas Petriello
#include "mymalloc.h"

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
	printArraysAsPicture(10);
	myfree(a_string);
	myfree(a_int);
	printf("---------\n");
	printArraysAsPicture(10);

	return 0;
}
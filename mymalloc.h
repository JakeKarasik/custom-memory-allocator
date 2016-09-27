#define malloc(x) mymalloc(x, __FILE__, __LINE__)
#define free(x) myfree(x, __FILE__, __LINE__)
//it is wise to wipe afterwards
//*****Prototypes*****//
char * malloc(int size);
void free(char * ptr);

//*****Functions*****//
char * malloc(int size) {
	printf("Memory of size %d allocated\n",size);
	return 0x0;
}

void free(char * ptr) {
	
}
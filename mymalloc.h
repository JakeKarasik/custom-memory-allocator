#define malloc(x) mymalloc(x, __FILE__, __LINE__)
#define free(x) myfree(x, __FILE__, __LINE__)
#define MEM_CAP 5000
#define FINAL_BLOCK_THRESHOLD 8
#define UNIQUE_ID 0xdaedbeaf


//****Structs*****//
typedef struct metadata_{//these structs hold data on the block and link to each other making a list
	
	int is_set;//determines if the memory block is free
	int size;//byte size of the block
	long id;//UNIQUE_ID
	struct metadata_ * next;//ptr to next node in list
	
} metadata;

//*****Prototypes*****//
void * mymalloc(size_t size, char * file, int line);//customized malloc
void myfree(void * ptr, char * file, int line);//customized free
void resetmyblock();//memgrind tool
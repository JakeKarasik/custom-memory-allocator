#define malloc(x) mymalloc(x, __FILE__, __LINE__)
#define free(x) myfree(x, __FILE__, __LINE__)
#define MEM_CAP 5000
#define FINAL_BLOCK_THRESHOLD 8
#define UNIQUE_ID 0xdaedbeaf


//****Structs*****//
typedef struct metadata_{
	
	int is_set;
	int size;
	long id;
	struct metadata_ * next;
	
} metadata;

//*****Prototypes*****//
void * mymalloc(size_t size, char * file, int line);
void myfree(void * ptr, char * file, int line);
void resetmyblock();
int getSuccessfulMallocs();
int getSuccessfulFrees();
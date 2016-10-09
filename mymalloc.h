//#define malloc(x) mymalloc(x, __FILE__, __LINE__)
//#define free(x) myfree(x, __FILE__, __LINE__)
#define MEM_CAP 5000
#define FINAL_BLOCK_THRESHOLD 40


//****Structs*****//
typedef struct metadata_{
	
	int is_set;
	int size;
	long id;
	struct metadata_ * prev, * next;
	
}metadata;

//*****Prototypes*****//
void * mymalloc(size_t size);
void myfree(void * ptr);
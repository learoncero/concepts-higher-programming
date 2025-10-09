typedef struct heapBlockHeader {
	size_t size; // size of the usable memory after this header
	int free;    // 1 if free, other (0) if allocated
} heapManager_heapBlockHeader_t;

void* heapManager_alloc(size_t size);
void heapManager_init();
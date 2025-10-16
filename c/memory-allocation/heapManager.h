#include <stdint.h>

#ifndef HEAP_SIZE
#define HEAP_SIZE 4096
#endif // !HEAP_SIZE

typedef struct heapBlockHeader {
	size_t size;   // size of the usable memory after this header
	uint8_t free;  // 1 if free, 0 if allocated
} heapManager_heapBlockHeader_t;

void* heapManager_alloc(size_t size);
void heapManager_init();
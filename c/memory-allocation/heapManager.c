#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "heapManager.h"

// Helper macros to extract bytes from a value (little-endian)
#define BYTE0(x) ((uint8_t)((x) & 0xFF))
#define BYTE1(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define BYTE2(x) ((uint8_t)(((x) >> 16) & 0xFF))
#define BYTE3(x) ((uint8_t)(((x) >> 24) & 0xFF))
#define BYTE4(x) ((uint8_t)(((x) >> 32) & 0xFF))
#define BYTE5(x) ((uint8_t)(((x) >> 40) & 0xFF))
#define BYTE6(x) ((uint8_t)(((x) >> 48) & 0xFF))
#define BYTE7(x) ((uint8_t)(((x) >> 56) & 0xFF))

#define ALIGNMENT 4
#define ALIGN(size) (((size) + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1))
#define INITIAL_SIZE (HEAP_SIZE - sizeof(heapManager_heapBlockHeader_t))
#define INITIAL_FREE 1

#if (HEAP_SIZE % ALIGNMENT) != 0
#error "HEAP_SIZE must be a multiple of 4"
#endif


// heap structure: [Header1][data........][Header2][data........][Header3][data........]
static uint8_t gHeap[HEAP_SIZE] = {
	// size_t size (8 bytes, little-endian)
	BYTE0(INITIAL_SIZE), BYTE1(INITIAL_SIZE), BYTE2(INITIAL_SIZE), BYTE3(INITIAL_SIZE),
	BYTE4(INITIAL_SIZE), BYTE5(INITIAL_SIZE), BYTE6(INITIAL_SIZE), BYTE7(INITIAL_SIZE),
	// uint8_t free (1 byte)
	INITIAL_FREE
};

//void heapManager_init() {
//	heapManager_heapBlockHeader_t* initialHeader = (heapManager_heapBlockHeader_t*)gHeap;
//	initialHeader->size = HEAP_SIZE - sizeof(heapManager_heapBlockHeader_t);
//	initialHeader->free = 1;
//}

void* heapManager_alloc(size_t size) {
	// Align the requested size to ALIGNMENT bytes
	size_t alignedSize = ALIGN(size);

	heapManager_heapBlockHeader_t* pCurrent = gHeap;
	uint8_t* pHeapEnd = gHeap + HEAP_SIZE;

	while (pCurrent != NULL && (uint8_t*)pCurrent < pHeapEnd) {
		if ((pCurrent->free) && (pCurrent->size >= alignedSize)) {
			// heap block is exactly the size needed
			if (pCurrent->size > alignedSize + sizeof(heapManager_heapBlockHeader_t)) {
				// split the free heap block
				heapManager_heapBlockHeader_t* pNewHeaderBlock = (heapManager_heapBlockHeader_t*)
					((uint8_t*)pCurrent
						+ sizeof(heapManager_heapBlockHeader_t)
						+ alignedSize);
				pNewHeaderBlock->size = pCurrent->size - alignedSize - sizeof(heapManager_heapBlockHeader_t);
				pNewHeaderBlock->free = 1;
				pCurrent->size = alignedSize;
			}
			pCurrent->free = 0;
			return (uint8_t*)pCurrent + sizeof(heapManager_heapBlockHeader_t);
		}

		// go to the next header block
		pCurrent = (heapManager_heapBlockHeader_t*)((uint8_t*)pCurrent + (sizeof(heapManager_heapBlockHeader_t) + pCurrent->size));
	}

	return NULL; // no suitable block found
}

int heapManager_free(uint8_t* address) {
    if (address == NULL) {
        return 0;
    }

	heapManager_heapBlockHeader_t* pHeaderToFree = (heapManager_heapBlockHeader_t*)
		(address - sizeof(heapManager_heapBlockHeader_t));
    
    // check heap boundaries
    uint8_t* heapStart = gHeap;
    uint8_t* heapEnd = gHeap + HEAP_SIZE;

    if ((uint8_t*)pHeaderToFree < heapStart || (uint8_t*)pHeaderToFree >= heapEnd) {
        return 0; // address not valid
    }

	pHeaderToFree->free = 1;

	heapManager_heapBlockHeader_t* pNext = (heapManager_heapBlockHeader_t*)
		((uint8_t*)pHeaderToFree + (sizeof(heapManager_heapBlockHeader_t) + pHeaderToFree->size));

	while ((uint8_t*)pNext < heapEnd && pNext->free == 1) {
		pHeaderToFree->size += sizeof(heapManager_heapBlockHeader_t) + pNext->size;

		// go to the next header block
		pNext = (heapManager_heapBlockHeader_t*)
			((uint8_t*)pHeaderToFree + (sizeof(heapManager_heapBlockHeader_t) + pHeaderToFree->size));
	}

	return pHeaderToFree->size;
}

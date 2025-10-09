#include <stdio.h>
#include <stdlib.h>
#include "heapManager.h"

#define HEAP_SIZE 4096

// heap structure: [Header1][data........][Header2][data........][Header3][data........]
static unsigned char heap[HEAP_SIZE] = {0xAF, 0xFE};

static heapManager_heapBlockHeader_t* pFreeList = NULL;

void heapManager_init() {
	pFreeList = (heapManager_heapBlockHeader_t*)heap;
	pFreeList->size = HEAP_SIZE - sizeof(heapManager_heapBlockHeader_t);
	pFreeList->free = 1;
}

void* heapManager_alloc(size_t size) {
	heapManager_heapBlockHeader_t* pCurrent = pFreeList;
	unsigned char* heapEnd = heap + HEAP_SIZE;

	while (pCurrent != NULL && (unsigned char*)pCurrent < heapEnd) {
		if ((pCurrent->free) && (pCurrent->size >= size)) {
			// heap block is exactly the size needed
			if (pCurrent->size > size + sizeof(heapManager_heapBlockHeader_t)){
				// split the free heap block
				heapManager_heapBlockHeader_t* pNewHeaderBlock = (heapManager_heapBlockHeader_t*)
					((unsigned char*)pCurrent 
					+ sizeof(heapManager_heapBlockHeader_t) 
					+ size);
				pNewHeaderBlock->size = pCurrent->size - size - sizeof(heapManager_heapBlockHeader_t);
				pNewHeaderBlock->free = 1;
				pCurrent->size = size;
			}
			pCurrent->free = 0;
			return (unsigned char*)pCurrent + sizeof(heapManager_heapBlockHeader_t);
		}

		// go to the next header block
		pCurrent = (heapManager_heapBlockHeader_t*)((unsigned char*)pCurrent + (sizeof(heapManager_heapBlockHeader_t) + pCurrent->size));
	}

	return NULL; // no suitable block found
}

int heapManager_free(unsigned char* address) {
    if (address == NULL) {
        return 0;
    }

	heapManager_heapBlockHeader_t* pHeaderToFree = (heapManager_heapBlockHeader_t*)
		(address - sizeof(heapManager_heapBlockHeader_t));
    
    // check heap boundaries
    unsigned char* heapStart = heap;
    unsigned char* heapEnd = heap + HEAP_SIZE;

    if ((unsigned char*)pHeaderToFree < heapStart || (unsigned char*)pHeaderToFree >= heapEnd) {
        return 0; // address not valid
    }

	pHeaderToFree->free = 1;

	heapManager_heapBlockHeader_t* pNext = (heapManager_heapBlockHeader_t*)
		((unsigned char*)pHeaderToFree + (sizeof(heapManager_heapBlockHeader_t) + pHeaderToFree->size));

	while ((unsigned char*)(pNext < heapEnd) && (pNext->free == 1)) {
		pHeaderToFree->size += sizeof(heapManager_heapBlockHeader_t) + pNext->size;

		// go to the next header block
		pNext = (heapManager_heapBlockHeader_t*)
			((unsigned char*)pHeaderToFree + (sizeof(heapManager_heapBlockHeader_t) + pHeaderToFree->size));
	}

	return pHeaderToFree->size;
}

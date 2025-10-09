#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heapManager.h"

int main(int argc, char* argv[]) {
    // Initialize heap
    heapManager_init();
    
    printf("=== Heap Manager Tests ===\n");
    
    // Test 1: Simple allocation
    printf("Test 1: Allocate 4 bytes\n");
    unsigned char* address1 = (unsigned char*)heapManager_alloc(4);
    if (address1) {
        printf("Successfully allocated at address: %p\n", address1);
        // Write test data
        address1[0] = 'T';
        address1[1] = 'E';
        address1[2] = 'S';
        address1[3] = 'T';
        printf("  Written: %.4s\n", address1);
    } else {
        printf("Allocation failed\n");
    }
    
    // Test 2: Additional allocation
    printf("\nTest 2: Allocate additional 8 bytes\n");
    unsigned char* address2 = (unsigned char*)heapManager_alloc(8);
    if (address2) {
        printf("Successfully allocated at address: %p\n", address2);
        strcpy_s((char*)address2, 8, "HELLO");
        printf("  Written: %s\n", address2);
    } else {
        printf("Allocation failed\n");
    }
    
    // Test 3: Large allocation
    printf("\nTest 3: Allocate 1000 bytes\n");
    unsigned char* address3 = (unsigned char*)heapManager_alloc(1000);
    if (address3) {
        printf("Successfully allocated at address: %p\n", address3);
    } else {
        printf("Allocation failed\n");
    }
    
    // Test 4: Check if original data is still correct
    printf("\nTest 4: Check data integrity\n");
    if (address1 && address1[0] == 'T') {
        printf("First allocation still intact: %.4s\n", address1);
    } else {
        printf("First allocation corrupted\n");
    }
    
    if (address2 && strcmp((char*)address2, "HELLO") == 0) {
        printf("Second allocation still intact: %s\n", address2);
    } else {
        printf("Second allocation corrupted\n");
    }
    
    // Test 5: Free memory and test reallocation
    printf("\nTest 5: Free first allocation\n");
    if (address1) {
        int freedSize = heapManager_free(address1);
        printf("Freed %d bytes from address: %p\n", freedSize, address1);
        address1 = NULL; // Avoid dangling pointer
    }
    
    printf("\nTest 6: Free second allocation\n");
    if (address2) {
        int freedSize = heapManager_free(address2);
        printf("Freed %d bytes from address: %p\n", freedSize, address2);
        address2 = NULL; // Avoid dangling pointer
    }
    
    // Test 7: Try to allocate after freeing
    printf("\nTest 7: Allocate 10 bytes after freeing (should reuse freed space)\n");
    unsigned char* address4 = (unsigned char*)heapManager_alloc(10);
    if (address4) {
        printf("Successfully reallocated at address: %p\n", address4);
        strcpy_s((char*)address4, 10, "REUSED");
        printf("  Written: %s\n", address4);
    } else {
        printf("Reallocation failed\n");
    }
    
    // Test 8: Free remaining allocations
    printf("\nTest 8: Free remaining allocations\n");
    if (address3) {
        int freedSize = heapManager_free(address3);
        printf("Freed %d bytes from large allocation\n", freedSize);
        address3 = NULL;
    }
    
    if (address4) {
        int freedSize = heapManager_free(address4);
        printf("Freed %d bytes from reused allocation\n", freedSize);
        address4 = NULL;
    }
    
    // Test 9: Final allocation test (should have almost full heap available)
    printf("\nTest 9: Final allocation test (large block)\n");
    unsigned char* address5 = (unsigned char*)heapManager_alloc(2000);
    if (address5) {
        printf("Successfully allocated 2000 bytes at address: %p\n", address5);
        int freedSize = heapManager_free(address5);
        printf("Freed %d bytes\n", freedSize);
    } else {
        printf("Large allocation failed\n");
    }
    
    printf("\n=== All tests completed ===\n");
    
    return 0;
}
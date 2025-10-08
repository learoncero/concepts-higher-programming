#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListGen.h"

// Example callbacks
void printNode(linkedListGen_node_t* node) {
	linkedListGen_intNode_t* intNode = (linkedListGen_intNode_t*)node;
    printf("%d\n", intNode->data);
}


int addFive(int x) {
    return x + 5;
}

int main(void) {
    linkedListGen_node_t* head = NULL;

    // ---- INT NODE ----
    linkedListGen_intNode_t* intNode1 = (linkedListGen_intNode_t*)linkedListGen_createNode(sizeof(linkedListGen_intNode_t));
    intNode1->data = 10;

    linkedListGen_intNode_t* intNode2 = (linkedListGen_intNode_t*)linkedListGen_createNode(sizeof(linkedListGen_intNode_t));
    intNode2->data = 20;

    linkedListGen_insertAtFirst(&head, (linkedListGen_node_t*)intNode1);
    linkedListGen_insertAtEnd(&head, (linkedListGen_node_t*)intNode2);

	// ---- Traverse List ----
	int count = linkedListGen_forEach(head, printNode);
	printf("Total nodes: %d\n", count);
    

    // ---- Cleanup ----
    linkedListGen_deleteFromFirst(&head); // delete nodes until empty
    linkedListGen_deleteFromFirst(&head);

    return 0;
}

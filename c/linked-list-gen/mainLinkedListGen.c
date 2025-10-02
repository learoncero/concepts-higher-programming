#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListGen.h"

// Example callbacks
int doubleInt(int x) {
    return x * 2;
}

int addFive(int x) {
    return x + 5;
}

int main(void) {
    linkedListGen_node_t* head = NULL;

    // ---- INT NODE ----
    linkedListGen_intNode_t* intNode1 = (linkedListGen_intNode_t*)linkedListGen_createNode(sizeof(linkedListGen_intNode_t));
    intNode1->base.type = INT_NODE;
    intNode1->data = 10;

    linkedListGen_intNode_t* intNode2 = (linkedListGen_intNode_t*)linkedListGen_createNode(sizeof(linkedListGen_intNode_t));
    intNode2->base.type = INT_NODE;
    intNode2->data = 20;

    linkedListGen_insertAtFirst(&head, (linkedListGen_node_t*)intNode1);
    linkedListGen_insertAtEnd(&head, (linkedListGen_node_t*)intNode2);

    // ---- DOUBLE NODE ----
    linkedListGen_doubleNode_t* doubleNode = (linkedListGen_doubleNode_t*)linkedListGen_createNode(sizeof(linkedListGen_doubleNode_t));
    doubleNode->base.type = DOUBLE_NODE;
    doubleNode->data = 3.14159;

    linkedListGen_insertAtEnd(&head, (linkedListGen_node_t*)doubleNode);

    // ---- STRING NODE ----
    linkedListGen_stringNode_t* stringNode = (linkedListGen_stringNode_t*)linkedListGen_createNode(sizeof(linkedListGen_stringNode_t));
    stringNode->base.type = STRING_NODE;
    stringNode->data = "Hello World";

    linkedListGen_insertAtEnd(&head, (linkedListGen_node_t*)stringNode);

    // ---- Print initial list ----
    printf("Initial list:\n");
    linkedListGen_printAll(head);

    // ---- forEach on ints only ----
    printf("After doubling integers:\n");
    linkedListGen_forEach(head, doubleInt);
    linkedListGen_printAll(head);

    printf("After adding 5 to integers:\n");
    linkedListGen_forEach(head, addFive);
    linkedListGen_printAll(head);

    // ---- Cleanup ----
    linkedListGen_deleteFromFirst(&head); // delete nodes until empty
    linkedListGen_deleteFromFirst(&head);
    linkedListGen_deleteFromFirst(&head);
    linkedListGen_deleteFromFirst(&head);

    return 0;
}

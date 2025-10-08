#ifndef LINKED_LIST_GEN_H__
#define LINKED_LIST_GEN_H__

#include <stddef.h>

typedef struct node {
    struct node* pNext;
} linkedListGen_node_t;

typedef struct intNode {
    linkedListGen_node_t base;
    int data;
} linkedListGen_intNode_t;

typedef struct doubleNode {
    linkedListGen_node_t base;
    double data;
} linkedListGen_doubleNode_t;

typedef struct stringNode {
    linkedListGen_node_t base;
    char* data;
} linkedListGen_stringNode_t;

typedef void (*callbackFunc_t)(linkedListGen_node_t*);

linkedListGen_node_t* linkedListGen_createNode(size_t size);
int linkedListGen_insertAtFirst(linkedListGen_node_t** pHead, linkedListGen_node_t* pNewNode);
int linkedListGen_insertAtEnd(linkedListGen_node_t** pHead, linkedListGen_node_t* pNewNode);
int linkedListGen_insertAtPosition(linkedListGen_node_t** pHead, linkedListGen_node_t* pNewNode, int position);
int linkedListGen_deleteFromFirst(linkedListGen_node_t** pHead);
int linkedListGen_deleteFromEnd(linkedListGen_node_t** pHead);
int linkedListGen_deleteAtPosition(linkedListGen_node_t** pHead, int position);
int linkedListGen_forEach(linkedListGen_node_t* pHead, callbackFunc_t callback);

#endif#pragma once

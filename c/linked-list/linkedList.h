#ifndef LIST_H_
#define LIST_H_

typedef struct node {
    int data;
    struct node* pNext;
} node_t;

node_t* linkedList_createNode(int data);
int linkedList_insertAtFirst(node_t** pHead, int data);
int linkedList_insertAtEnd(node_t** pHead, int data);
int linkedList_insertAtPosition(node_t** pHead, int data, int position);
int linkedList_deleteFromFirst(node_t** pHead);
int linkedList_deleteFromEnd(node_t** pHead);
int linkedList_deleteAtPosition(node_t** pHead, int position);
int linkedList_print(node_t* pHead);

#endif
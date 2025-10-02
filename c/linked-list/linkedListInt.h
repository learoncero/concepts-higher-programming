#ifndef LINKED_LIST_INT_H__
#define LINKED_LIST_INT_H__

typedef struct node {
    int data;
    struct node* pNext;
} linkedListInt_node_t;

linkedListInt_node_t* linkedListInt_createNode(int data);
int linkedListInt_insertAtFirst(linkedListInt_node_t** pHead, int data);
int linkedListInt_insertAtEnd(linkedListInt_node_t** pHead, int data);
int linkedListInt_insertAtPosition(linkedListInt_node_t** pHead, int data, int position);
int linkedListInt_deleteFromFirst(linkedListInt_node_t** pHead);
int linkedListInt_deleteFromEnd(linkedListInt_node_t** pHead);
int linkedListInt_deleteAtPosition(linkedListInt_node_t** pHead, int position);
int linkedListInt_printAll(linkedListInt_node_t* pHead);
int linkedListInt_forEach(linkedListInt_node_t* pHead, int (*func) (int));

#endif
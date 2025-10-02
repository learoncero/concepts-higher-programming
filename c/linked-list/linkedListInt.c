#include "linkedListInt.h"
#include <stdio.h>
#include <stdlib.h>



linkedListInt_node_t* linkedListInt_createNode(int data) {
    linkedListInt_node_t* pNewNode = (linkedListInt_node_t*)malloc(sizeof(linkedListInt_node_t));

    if (pNewNode == NULL) {
        return NULL;
    }

    pNewNode->data = data;
    pNewNode->pNext = NULL;

    return pNewNode;
}

int linkedListInt_insertAtFirst(linkedListInt_node_t** pHead, int data) {
    linkedListInt_node_t* pNewNode = linkedListInt_createNode(data);
    pNewNode->pNext = *pHead;
    *pHead = pNewNode;

    return 0;
}

int linkedListInt_insertAtEnd(linkedListInt_node_t** pHead, int data) {
    linkedListInt_node_t* pNewNode = linkedListInt_createNode(data);

    if (*pHead == NULL) {
        *pHead = pNewNode;
        return 0;
    }

    linkedListInt_node_t* pTemp = *pHead;
    while (pTemp->pNext != NULL) {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = pNewNode;

    return 0;
}

int linkedListInt_insertAtPosition(linkedListInt_node_t** pHead, int data, int position) {
    linkedListInt_node_t* pNewNode = linkedListInt_createNode(data);

    if (position == 0) {
        linkedListInt_insertAtFirst(pHead, data);
        return 0;
    }

    linkedListInt_node_t* pTemp = *pHead;
    int i = 0;

    while ((pTemp->pNext != NULL) && (i < position - 1)) {
        pTemp = pTemp->pNext;
        i += 1;
    }

    if (pTemp == NULL) {
        printf("Position out of range.\n");
        free(pNewNode);
        return -1;
    }

    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;

    return 0;
}

int linkedListInt_deleteFromFirst(linkedListInt_node_t** pHead) {
    if (*pHead == NULL) {
        printf("List is empty.\n");
        return -1;
    }

    linkedListInt_node_t* pTemp = *pHead;
    *pHead = pTemp->pNext;
    free(pTemp);

    return 0;
}

int linkedListInt_deleteFromEnd(linkedListInt_node_t** pHead) {
    if (*pHead == NULL) {
        printf("List is empty");
        return -1;
    }

    // list has only one entry
    linkedListInt_node_t* pTemp = *pHead;
    if (pTemp->pNext == NULL) {
        free(pTemp);
        *pHead = NULL;
        return 0;
    }

    while (pTemp->pNext->pNext != NULL) {
        pTemp = pTemp->pNext;
    }

    free(pTemp->pNext);
    pTemp->pNext = NULL;

    return 0;
}

int linkedListInt_deleteAtPosition(linkedListInt_node_t** pHead, int position) {
    if (*pHead == NULL) {
        printf("List is empty.\n");
        return -1;
    }

    linkedListInt_node_t* pTemp = *pHead;
    if (position == 0) {
        linkedListInt_deleteFromFirst(pHead);
        return 0;
    }

    int i = 0;
    while ((pTemp->pNext != NULL) && (i < position - 1)) {
        pTemp = pTemp->pNext;
        i += 1;
    }

    if ((pTemp == NULL) || (pTemp->pNext == NULL)) {
        printf("Position out of range.\n");
        return -1;
    }

    linkedListInt_node_t* pToDelete = pTemp->pNext;
    pTemp->pNext = pToDelete->pNext;
    free(pToDelete);

    return 0;
}

int linkedListInt_forEach(linkedListInt_node_t* pHead, int (*func) (int)) {
    if (pHead == NULL) {
        printf("List is empty.\n");
        return 0;
    }

    int i = 0;

    while (pHead != NULL) {
        pHead->data = func(pHead->data);
        i += 1;
        pHead = pHead->pNext;
    }

    return i;
}

int linkedListInt_printAll(linkedListInt_node_t* pHead) {
    linkedListInt_node_t* current = pHead;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->pNext;
    }
    printf("NULL\n");

    return 0;
}

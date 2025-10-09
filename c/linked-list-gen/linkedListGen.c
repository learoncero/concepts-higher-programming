#include "linkedListGen.h"
#include <stdio.h>
#include <stdlib.h>

linkedListGen_node_t* linkedListGen_createNode(size_t size) {
    linkedListGen_node_t* pNewNode = malloc(size);

    if (pNewNode == NULL) {
        return NULL;
    }

    pNewNode->pNext = NULL;

    return pNewNode;
}

int linkedListGen_insertAtFirst(linkedListGen_node_t** pHead, linkedListGen_node_t* pNewNode) {
    pNewNode->pNext = *pHead;
    *pHead = pNewNode;

    return 0;
}

int linkedListGen_insertAtEnd(linkedListGen_node_t** pHead, linkedListGen_node_t* pNewNode) {
    if (*pHead == NULL) {
        *pHead = pNewNode;
        return 0;
    }

    linkedListGen_node_t* pTemp = *pHead;
    while (pTemp->pNext != NULL) {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = pNewNode;

    return 0;
}

int linkedListGen_insertAtPosition(linkedListGen_node_t** pHead, linkedListGen_node_t* pNewNode, int position) {
    if (position == 0) {
        linkedListGen_insertAtFirst(pHead, pNewNode);
        return 0;
    }

    linkedListGen_node_t* pTemp = *pHead;
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

int linkedListGen_deleteFromFirst(linkedListGen_node_t** pHead) {
    if (*pHead == NULL) {
        printf("List is empty.\n");
        return -1;
    }

    linkedListGen_node_t* pTemp = *pHead;
    *pHead = pTemp->pNext;
    free(pTemp);

    return 0;
}

int linkedListGen_deleteFromEnd(linkedListGen_node_t** pHead) {
    if (*pHead == NULL) {
        printf("List is empty");
        return -1;
    }

    // list has only one entry
    linkedListGen_node_t* pTemp = *pHead;
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

int linkedListGen_deleteAtPosition(linkedListGen_node_t** pHead, int position) {
    if (*pHead == NULL) {
        printf("List is empty.\n");
        return -1;
    }

    linkedListGen_node_t* pTemp = *pHead;
    if (position == 0) {
        linkedListGen_deleteFromFirst(pHead);
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

    linkedListGen_node_t* pToDelete = pTemp->pNext;
    pTemp->pNext = pToDelete->pNext;
    free(pToDelete);

    return 0;
}


int linkedListGen_forEach(linkedListGen_node_t* pHead, callbackFunc_t callback) {
    if (pHead == NULL) {
        printf("List is empty.\n");
        return 0;
    }

    int count = 0;
    linkedListGen_node_t* pCurrent = pHead;

    while (pCurrent != NULL) {
        callback(pCurrent);
        count += 1;
        pCurrent = pCurrent->pNext;
    }

    return count;
}


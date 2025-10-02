#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>



node_t* linkedList_createNode(int data) {
    node_t* pNewNode = (node_t*)malloc(sizeof(node_t));

    if (pNewNode == NULL) {
        return NULL;
    }

    pNewNode->data = data;
    pNewNode->pNext = NULL;

    return pNewNode;
}

int linkedList_insertAtFirst(node_t** pHead, int data) {
    node_t* pNewNode = linkedList_createNode(data);
    pNewNode->pNext = *pHead;
    *pHead = pNewNode;

    return 0;
}

int linkedList_insertAtEnd(node_t** pHead, int data) {
    node_t* pNewNode = linkedList_createNode(data);

    if (*pHead == NULL) {
        *pHead = pNewNode;
        return 0;
    }

    node_t* pTemp = *pHead;
    while (pTemp->pNext != NULL) {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = pNewNode;

    return 0;
}

int linkedList_insertAtPosition(node_t** pHead, int data, int position) {
    node_t* pNewNode = linkedList_createNode(data);

    if (position == 0) {
        linkedList_insertAtFirst(pHead, data);
        return 0;
    }

    node_t* pTemp = *pHead;
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

int linkedList_deleteFromFirst(node_t** pHead) {
    if (*pHead == NULL) {
        printf("List is empty.\n");
        return -1;
    }

    node_t* pTemp = *pHead;
    *pHead = pTemp->pNext;
    free(pTemp);

    return 0;
}

int linkedList_deleteFromEnd(node_t** pHead) {
    if (*pHead == NULL) {
        printf("List is empty");
        return -1;
    }

    // list has only one entry
    node_t* pTemp = *pHead;
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

int linkedList_deleteAtPosition(node_t** pHead, int position) {
    if (*pHead == NULL) {
        printf("List is empty.\n");
        return -1;
    }

    node_t* pTemp = *pHead;
    if (position == 0) {
        linkedList_deleteFromFirst(pHead);
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

    node_t* pToDelete = pTemp->pNext;
    pTemp->pNext = pToDelete->pNext;
    free(pToDelete);

    return 0;
}

int linkedList_print(node_t* pHead) {
    node_t* current = pHead;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->pNext;
    }
    printf("NULL\n");

    return 0;
}

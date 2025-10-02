#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(void) {
    node_t* head = NULL;   // start with an empty list

    linkedList_insertAtFirst(&head, 10);
    printf("Linked list after inserting the node:10 at the beginning \n");
    linkedList_print(head);

    printf("Linked list after inserting the node:20 at the end \n");
    linkedList_insertAtEnd(&head, 20);
    linkedList_print(head);

    printf("Linked list after inserting the node:5 at the end \n");
    linkedList_insertAtEnd(&head, 5);
    linkedList_print(head);

    printf("Linked list after inserting the node:30 at the end \n");
    linkedList_insertAtEnd(&head, 30);
    linkedList_print(head);

    printf("Linked list after inserting the node:15 at position 2 \n");
    linkedList_insertAtPosition(&head, 15, 2);
    linkedList_print(head);

    printf("Linked list after deleting the first node: \n");
    linkedList_deleteFromFirst(&head);
    linkedList_print(head);

    printf("Linked list after deleting the last node: \n");
    linkedList_deleteFromEnd(&head);
    linkedList_print(head);

    printf("Linked list after deleting the node at position 1: \n");
    linkedList_deleteAtPosition(&head, 1);
    linkedList_print(head);

    return 0;
}

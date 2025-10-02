#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int doubleValue(int x) {
    return x * 2;
}

int addTen(int x) {
    return x + 10;
}

int main(void) {
    linkedListInt_node_t* head = NULL;   // start with an empty list

    linkedListInt_insertAtFirst(&head, 10);
    printf("Linked list after inserting the node:10 at the beginning \n");
    linkedListInt_printAll(head);

    printf("Linked list after inserting the node:20 at the end \n");
    linkedListInt_insertAtEnd(&head, 20);
    linkedListInt_printAll(head);

    printf("Linked list after inserting the node:5 at the end \n");
    linkedListInt_insertAtEnd(&head, 5);
    linkedListInt_printAll(head);

    printf("Linked list after inserting the node:30 at the end \n");
    linkedListInt_insertAtEnd(&head, 30);
    linkedListInt_printAll(head);

    printf("Linked list after inserting the node:15 at position 2 \n");
    linkedListInt_insertAtPosition(&head, 15, 2);
    linkedListInt_printAll(head);

    printf("Linked list after deleting the first node: \n");
    linkedListInt_deleteFromFirst(&head);
    linkedListInt_printAll(head);

    printf("Linked list after deleting the last node: \n");
    linkedListInt_deleteFromEnd(&head);
    linkedListInt_printAll(head);

    printf("Linked list after deleting the node at position 1: \n");
    linkedListInt_deleteAtPosition(&head, 1);
    linkedListInt_printAll(head);

    printf("Linked list after doubling each value: \n");
    linkedListInt_forEach(head, doubleValue);
    linkedListInt_printAll(head);

    printf("Linked list after adding 10 to each value: \n");
    linkedListInt_forEach(head, addTen);
    linkedListInt_printAll(head);

    return 0;
}

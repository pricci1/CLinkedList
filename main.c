#include <stdio.h>
#include <stdlib.h>



typedef struct Node{
    struct Node* head;
    struct Node* next;
    int value;
} Node ;


void createList(Node *head, int value);
Node* addNode(Node *head, int value);
void printList(Node *head);
void deleteList(Node *head);
void removeNode(Node *head, Node *nodeToDelete);

int main() {
    printf("Linked List!\n");

    Node headNodo;
    createList(&headNodo, 1);


    Node* n2 = addNode(&headNodo, 2);
    Node* n3 = addNode(&headNodo, 3);
    addNode(&headNodo, 4);
    addNode(&headNodo, 5);
    addNode(&headNodo, 6);
    addNode(&headNodo, 7);


    printList(&headNodo);

    removeNode(&headNodo, n3);


    printList(&headNodo);


    deleteList(&headNodo);

//    free(n2);
    return 0;
}

void createList(Node *head, int value){
    head->head = head;
    head->value = value;
    head->next = NULL;
}

Node* addNode(Node *head, int value){
    Node* temp = malloc(sizeof(Node));
//    Node temp;

    Node* nodop = head;
    while (nodop->next != NULL){
        nodop = nodop->next;
    }
    nodop->next = temp;
    nodop = temp;
    nodop->head = head;
    nodop->value = value;
    nodop->next = NULL;
    return nodop;
}

void printList(Node *head){
    Node* nodop = head;
    printf("[0] value: [0]: %d\n", nodop->value);
    int i = 1;
    while (nodop->next != NULL){
        nodop = nodop->next;
        printf("[%d] value: %d\n", i++, nodop->value);
    }
}

void deleteList(Node *head){
    Node* nodop = head->next;
    Node* previousNode = NULL;
    while (nodop->next != NULL){
        previousNode = nodop;
        nodop = nodop->next;
        free(previousNode);
    }
}

void removeNode(Node *head, Node *nodeToDelete){
    Node* nodop = head;
    while (nodop->next != nodeToDelete){
        nodop = nodop->next;
    }
    nodop->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node removed\n");
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main() {
    // create simple list: head -> 10 -> 20 -> NULL
    Node *head = malloc(sizeof(Node));
    head->data = 10;
    head->next = malloc(sizeof(Node));
    head->next->data = 20;
    head->next->next = NULL;

    Node *q = head;  // pointer to first node

    // 1. Visit (see data)
    printf("Visit: %d\n", q->data);   // prints 10

    // 2. Insertion (insert 15 after q)
    Node *newNode = malloc(sizeof(Node));
    newNode->data = 15;
    newNode->next = q->next;
    q->next = newNode;  // list: 10 -> 15 -> 20

    // 3. Extraction (remove node after q)
    q->next = q->next->next;  // removes 15
    // final list: 10 -> 20

    // visit again
    printf("After ops: %d -> %d\n", head->data, head->next->data);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;  // front of queue
struct Node* rear = NULL;   // rear of queue

// Enqueue = insert at rear
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {          // if queue is empty
        front = rear = newNode;  // first node
    } else {
        rear->next = newNode;    // link new node
        rear = newNode;          // update rear
    }
    printf("%d enqueued\n", value);
}

// Dequeue = remove from front
void dequeue() {
    if (front == NULL) {
        printf("Queue empty\n");
        return;
    }
    printf("%d dequeued\n", front->data);
    struct Node* temp = front;
    front = front->next;    // move front
    if (front == NULL) {    // if queue becomes empty
        rear = NULL;
    }
    free(temp);
}

// Display queue
void display() {
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();   // Queue: 10 20 30

    dequeue();   // removes 10
    display();   // Queue: 20 30

    return 0;
}

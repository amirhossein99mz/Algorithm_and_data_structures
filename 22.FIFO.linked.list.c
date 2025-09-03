#include <stdio.h>
#include <stdlib.h>

// Node structure
struct e {
    int data;
    struct e *next;
};

// Enqueue function (insert at rear)
struct e* enqueue(struct e *tail, int value) {
    struct e* newNode = (struct e*)malloc(sizeof(struct e));
    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return tail;
    }
    newNode->data = value;
    if (tail == NULL) {
        // first node → points to itself
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next; // link new node to front
        tail->next = newNode;       // old tail points to new node
        tail = newNode;             // update tail
    }
    printf("%d enqueued\n", value);
    return tail;
}

// Dequeue function (remove from front)
struct e* dequeue(struct e *tail, int *value, int *status) {
    if (tail == NULL) {  // empty queue
        printf("Queue Underflow\n");
        *status = 0;
        return tail;
    }
    struct e* front = tail->next;  // front is next of tail
    *value = front->data;          // store dequeued value
    *status = 1;
    if (front == tail) {           // only one element
        free(front);
        tail = NULL;
    } else {
        tail->next = front->next;  // bypass old front
        free(front);
    }
    printf("%d dequeued\n", *value);
    return tail;
}

// Display queue
void display(struct e* tail) {
    if (tail == NULL) {
        printf("Queue empty\n");
        return;
    }
    struct e* temp = tail->next;  // start from front
    printf("Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

// Main function
int main() {
    struct e *tail = NULL;
    int val, status;

    tail = enqueue(tail, 10);
    tail = enqueue(tail, 20);
    tail = enqueue(tail, 30);
    display(tail);  // Queue: 10 20 30

    tail = dequeue(tail, &val, &status); // removes 10
    display(tail);  // Queue: 20 30

    tail = dequeue(tail, &val, &status); // removes 20
    display(tail);  // Queue: 30

    return 0;
}


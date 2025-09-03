#include <stdio.h>   // for printf
#include <stdlib.h>  // for malloc, free

// Node structure
struct e {
    int data;          // store value
    struct e *next;    // pointer to next node
};

// Enqueue function (insert at rear)
struct e* enqueue(struct e *tail, int value) {
    struct e* newNode = (struct e*)malloc(sizeof(struct e)); // allocate memory
    if (newNode == NULL) {                                   // if memory full
        printf("Queue Overflow\n");                          // error
        return tail;                                         // return unchanged
    }
    newNode->data = value;    // store value in new node
    if (tail == NULL) {       // if queue is empty
        newNode->next = newNode;  // new node points to itself (circular)
        tail = newNode;           // tail is the only node
        // Example: enqueue(10) → tail→[10]->(points to itself)
    } else {
        newNode->next = tail->next; // new node points to front
        tail->next = newNode;       // old tail points to new node
        tail = newNode;             // update tail to new node
        // Example: enqueue(20) → tail→[20]→[10]→(back to 20)
    }
    printf("%d enqueued\n", value); // show success
    return tail;                     // return new tail
}

// Dequeue function (remove from front)
struct e* dequeue(struct e *tail, int *value, int *status) {
    if (tail == NULL) {            // if queue is empty
        printf("Queue Underflow\n"); // error
        *status = 0;                 // failed
        return tail;                 // unchanged
    }
    struct e* front = tail->next;  // front = node after tail
    *value = front->data;          // store front value
    *status = 1;                   // success flag
    if (front == tail) {           // only one node
        free(front);               // free node
        tail = NULL;               // queue empty
        // Example: dequeue when only [10] → queue empty
    } else {
        tail->next = front->next;  // bypass old front
        free(front);               // free old front
        // Example: dequeue from [10,20,30] → removes 10, now [20,30]
    }
    printf("%d dequeued\n", *value); // show value removed
    return tail;                      // return new tail
}

// Display queue
void display(struct e* tail) {
    if (tail == NULL) {               // if empty
        printf("Queue empty\n");
        return;
    }
    struct e* temp = tail->next;      // start from front
    printf("Queue: ");
    do {
        printf("%d ", temp->data);    // print each value
        temp = temp->next;            // move next
    } while (temp != tail->next);     // loop until back at front
    printf("\n");
}

// Main function
int main() {
    struct e *tail = NULL;  // tail pointer, initially empty
    int val, status;        // for dequeue results

    tail = enqueue(tail, 10); // Queue: 10
    tail = enqueue(tail, 20); // Queue: 10 20
    tail = enqueue(tail, 30); // Queue: 10 20 30
    display(tail);            // prints: Queue: 10 20 30

    tail = dequeue(tail, &val, &status); // removes 10
    display(tail);                       // prints: Queue: 20 30

    tail = dequeue(tail, &val, &status); // removes 20
    display(tail);                       // prints: Queue: 30

    return 0; // end program
}


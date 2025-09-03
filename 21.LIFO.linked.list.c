#include <stdio.h>   // for printf
#include <stdlib.h>  // for malloc, free

// Node structure
struct Node {
    int data;            // store stack value
    struct Node* next;   // pointer to next node
};

struct Node* top = NULL;  // stack top pointer

// Push (insert at beginning)
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // allocate memory
    if (newNode == NULL) {                                           // check if memory full
        printf("Stack Overflow\n");                                  // print overflow
        return;                                                      // exit push
    }
    newNode->data = value;     // store value
    newNode->next = top;       // link new node to previous top
    top = newNode;             // update top pointer
    printf("%d pushed\n", value); // show success
}

// Pop (remove from beginning)
void pop() {
    if (top == NULL) {            // check if stack empty
        printf("Stack Underflow\n"); // print underflow
        return;                      // exit pop
    }
    printf("%d popped\n", top->data); // show value being popped
    struct Node* temp = top;          // store current top
    top = top->next;                  // move top to next node
    free(temp);                       // free old top
}

// Display stack
void display() {
    struct Node* temp = top;      // start from top
    printf("Stack: ");            // label
    while (temp != NULL) {        // loop till end
        printf("%d ", temp->data); // print each value
        temp = temp->next;        // move to next node
    }
    printf("\n");                 // new line
}

// Main function
int main() {
    push(10);   // push 10
    push(20);   // push 20
    push(30);   // push 30
    display();  // show stack

    pop();      // remove top
    display();  // show stack again

    return 0;   // end program
}

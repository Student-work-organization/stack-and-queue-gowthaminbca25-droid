#include <stdio.h>
#include <stdlib.h>

// Structure for Node
struct Node {
    int data;
    struct Node* next;
};

// Structure for Stack
struct Stack {
    struct Node* top;
};

// Function to initialize stack
void initStack(struct Stack* s) {
    s->top = NULL;
}

// 1. Push operation
void push(struct Stack* s, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;

    printf("%d pushed to stack\n", data);
}

// 2. Pop operation
int pop(struct Stack* s) {
    if (s->top == NULL) {
        printf("Stack Underflow\n");
        return -1; // Returning -1 instead of None in C
    }

    struct Node* temp = s->top;
    int popped = temp->data;
    s->top = temp->next;

    free(temp);
    return popped;
}

// 3. Peek operation
int peek(struct Stack* s) {
    if (s->top == NULL) {
        return -1;
    }
    return s->top->data;
}

// 4. Empty operation
int empty(struct Stack* s) {
    return (s->top == NULL);
}

// Main function to test
int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element is: %d\n", peek(&s));

    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));

    if (empty(&s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    return 0;
}

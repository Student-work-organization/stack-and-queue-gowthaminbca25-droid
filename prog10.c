#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Push
void push(int data) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}

// Pop
void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped element = %d\n", stack[top--]);
}

// Peek
void peek() {
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element = %d\n", stack[top]);
}

// Check empty
void isEmpty() {
    if(top == -1)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    peek();
    pop();
    peek();
    isEmpty();

    return 0;
}
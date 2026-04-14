#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue
void enqueue(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Front element
void frontElement() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element = %d\n", front->data);
}

// Check empty
void isEmpty() {
    if(front == NULL)
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");
}

// Traverse
void traverse() {
    struct Node* temp = front;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    traverse();
    frontElement();
    isEmpty();

    return 0;
}
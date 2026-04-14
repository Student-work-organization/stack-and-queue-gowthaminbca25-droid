#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Check if full
int isFull() {
    return (front == (rear + 1) % MAX);
}

// Check if empty
int isEmpty() {
    return (front == -1);
}

// Enqueue
void enqueue(int data) {
    if(isFull()) {
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = data;
}

// Dequeue
void dequeue() {
    if(isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element = %d\n", queue[front]);

    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Front element
void frontElement() {
    if(isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element = %d\n", queue[front]);
}

// Display queue
void display() {
    if(isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    printf("Queue: ");

    while(1) {
        printf("%d ", queue[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    frontElement();

    if(isEmpty())
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");

    return 0;
}
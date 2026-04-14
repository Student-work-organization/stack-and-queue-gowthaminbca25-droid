#include <stdio.h>
#include <stdlib.h>

struct CircularNode {
    int data;
    struct CircularNode* next;
};

struct CircularLinkedList {
    struct CircularNode* head;
};

void insert_at_end(struct CircularLinkedList* list, int data) {
    struct CircularNode* newNode = (struct CircularNode*)malloc(sizeof(struct CircularNode));
    newNode->data = data;

    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = list->head;
        return;
    }

    struct CircularNode* temp = list->head;

    while (temp->next != list->head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = list->head;
}

void delete_node(struct CircularLinkedList* list, int data) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct CircularNode *current = list->head, *prev = NULL;

    if (current->data == data) {
        
        if (current->next == list->head) {
            free(current);
            list->head = NULL;
            return;
        }

        struct CircularNode* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }

        list->head = current->next;
        temp->next = list->head;
        free(current);
        return;
    }

    prev = current;
    current = current->next;

    while (current != list->head) {
        if (current->data == data) {
            prev->next = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Value not found in list\n");
}

void display(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct CircularNode* temp = list->head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);

    printf("(back to head)\n");
}

int main() {
    struct CircularLinkedList list;
    list.head = NULL;

    insert_at_end(&list, 10);
    insert_at_end(&list, 20);
    insert_at_end(&list, 30);

    printf("Circular Linked List:\n");
    display(&list);

    delete_node(&list, 20);

    printf("After deleting 20:\n");
    display(&list);

    return 0;
}
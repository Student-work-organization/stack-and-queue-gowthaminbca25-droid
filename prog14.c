#include <stdio.h>
#include <stdlib.h>

// Structure for Tree Node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Simple insertion (level order)
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    // Using a simple queue (array)
    struct TreeNode* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* temp = queue[front++];

        // Insert as left child
        if (temp->left == NULL) {
            temp->left = createNode(data);
            break;
        } else {
            queue[rear++] = temp->left;
        }

        // Insert as right child
        if (temp->right == NULL) {
            temp->right = createNode(data);
            break;
        } else {
            queue[rear++] = temp->right;
        }
    }

    return root;
}

// Pre-order Traversal (Root → Left → Right)
void pre_order_traversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

// Main function
int main() {
    struct TreeNode* root = NULL;

    // Inserting elements
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);

    printf("Pre-order Traversal: ");
    pre_order_traversal(root);

    return 0;
}
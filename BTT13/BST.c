#include <stdio.h>

typedef struct {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* Create_Node(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

typedef struct {
    Node* root;
} Tree;

Tree* Create_Tree() {
    Tree* t;
    t->root = NULL;
}


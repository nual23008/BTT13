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

void Insert_Recursive(Node** Current_Node, int data) {
    if((*Current_Node) == NULL) {
        *Current_Node = Create_Node(data);
        return;
    }
    if((*Current_Node)->data < data) {
        if((*Current_Node)->left == NULL) {
            (*Current_Node)->left = Create_Node(data);
            return;
        }
        else {
            Insert_Recursive((*Current_Node)->left, data);
        }
    }
    else {
        if((*Current_Node)->right == NULL) {
            (*Current_Node)->right = Create_Node(data);
            return;
        }
        else {
            Insert_Recursive((*Current_Node)->right, data);
        }
    }
}

void Insert(Tree* t, int data) {
    Insert_Recursive(&(t->root), data);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int data;
    struct Node* Left;
    struct Node* Right;
}Node;

Node* Create_Node(int value) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = value;
    p->Left = NULL;
    p->Right = NULL;
    return p;
}

typedef struct {
    Node* root;
    int total_node;
}Tree;

Tree* Create_Tree() {
    Tree* t = (Tree*)malloc(sizeof(Tree));
    t->root = NULL;
    t->total_node = 0;
    return t;
}

void Insert_Recursive(Node** Current_Node, int data) {
    if(*Current_Node == NULL) {
        *Current_Node = Create_Node(data);
        return;
    }

    if(data < (*Current_Node)->data) {
        Insert_Recursive(&((*Current_Node)->Left), data);
    }

    if(data > (*Current_Node)->data) {
        Insert_Recursive(&((*Current_Node)->Right), data);
    }
}
#include <stdio.h>
#include <stdlib.h>

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
    int total_node;
} Tree;

void Insert_Recursive(Node** Current_Node, int data) {
    if((*Current_Node) == NULL) {
        *Current_Node = Create_Node(data);
        return;
    }
    if((*Current_Node)->data >= data) {
        if((*Current_Node)->left == NULL) {
            (*Current_Node)->left = Create_Node(data);
            return;
        }
        else {
            Insert_Recursive(&(*Current_Node)->left, data);
        }
    }
    else {
        if((*Current_Node)->right == NULL) {
            (*Current_Node)->right = Create_Node(data);
            return;
        }
        else {
            Insert_Recursive(&(*Current_Node)->right, data);
        }
    }
}

void Insert(Tree* t, int data) {
    Insert_Recursive(&(t->root), data);
}

void Print_Tree(Node* Current_Node) {
    if(Current_Node != NULL) {
        Print_Tree(Current_Node->left);
        printf("%d ", Current_Node->data);
        Print_Tree(Current_Node->right);
    }
}

void Search(Node* Current_Node, int data, int count) {
    if(Current_Node->data == NULL) {
        printf("khong tim thay gia tri can tim");
        return;
    }
    if(Current_Node->data == data) {
        printf("Node so: %d, co gia tri la: %d", count, data);
        return;
    }
    else {
        if(Current_Node->data >= data) {
            count++;
            Search(Current_Node->left, data, count);
        }
        else {
            count++;
            Search(Current_Node->right, data, count);
        }
    }
}

void Create_Tree(Tree* t, int* arr, int arr_size) {
    for(int i = 0; i < arr_size; i++) {
        Insert(t, arr[i]);
    }
}
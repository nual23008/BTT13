#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
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
    if(Current_Node == NULL) {
        printf("khong tim thay gia tri can tim");
        return;
    }
    if(Current_Node->data == data) {
        printf("Node can tim nam o vi tri so: %d", count);
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

int main() {
    Tree* t = (Tree*)malloc(sizeof(Tree));
    t->root = NULL;
    t->total_node = 0;

    int arr[] = {2001, 2002, 2006, 2007, 2003, 2004, 2005, 2001, 1999, 2004};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    Create_Tree(t, arr, arr_size);
    Print_Tree(t->root);
    printf("\n");
    Search(t->root, 2004, 0);
    return 0;
}
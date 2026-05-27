#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
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

void Insert(Tree* T, int data) {
    Insert_Recursive(&(T->root), data);
}

void Print_Tree(Node* Current_Node) {
    if(Current_Node != NULL) {
        Print_Tree(Current_Node->Left);
        printf("%d ", Current_Node->data);
        Print_Tree(Current_Node->Right);
    }
}

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        Swap(&arr[i], &arr[largest]);

        Heapify(arr, n, largest);
    }
}

void Print_Array(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void HeapSort(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        Heapify(arr, n, i);
    }
    Print_Array(arr, n);

    for (int i = n - 1; i > 0; i--) {
        Swap(&arr[0], &arr[i]);

        Heapify(arr, i, 0);
        Print_Array(arr, n);
    }
}

int main() {
    // Cay trong slide
    Tree* T = Create_Tree();
    int a[] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    printf("\n Cay 1 \n");

    for(int i = 0; i < 11; i++) {   
        printf("%d ", a[i]);
    }
    HeapSort(a, 11);
    
    printf("\n Ket qua cuoi \n");

    for(int i = 0; i < 11; i++) {   
        printf("%d ", a[i]);
    }

    return 0;
}
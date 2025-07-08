#include <stdio.h>
#include <stdlib.h>

struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
};

struct Tree* createNode(int value){
    struct Tree* node = (struct Tree*)malloc(sizeof(struct Tree));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printInOrder(struct Tree* head) {
    if (head == NULL)
        return;
    printInOrder(head->left);

    printf("%c->", head->data);

    printInOrder(head->right);
}

int main(){
    char c1 = 'A';
    char c2 = 'B';
    char c3 = 'C';
    struct Tree* root = createNode(c1);
    struct Tree* leftChild = createNode(c2);
    struct Tree* rightChild = createNode(c3);

    root->left = leftChild;
    root->right = rightChild;

    printInOrder(root);

    free(root);
    free(leftChild);
    free(rightChild);
}


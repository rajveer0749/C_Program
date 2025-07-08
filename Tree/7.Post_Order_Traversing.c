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

void printPostOrder(struct Tree* head) {  //Post-order: Left → Right → Node
    if (head == NULL)
        return;
    printPostOrder(head->left);
    printPostOrder(head->right);
    printf("%c->", head->data);
}

int main(){
    char c1 = 'A';
    char c2 = 'B';
    char c3 = 'C';
    char c4 = 'D';
    char c5 = 'E';
    struct Tree* root = createNode(c1);
    struct Tree* leftChild = createNode(c2);
    struct Tree* rightChild = createNode(c3);
    struct Tree* rightLeftChild = createNode(c4);
    struct Tree* rightRightChild = createNode(c5);

    root->left = leftChild;
    root->right = rightChild;
    rightChild->left = rightLeftChild;
    rightChild->right = rightRightChild;

    printPostOrder(root);

    free(root);
    free(leftChild);
    free(rightChild);
    free(rightLeftChild);
    free(rightRightChild);
}
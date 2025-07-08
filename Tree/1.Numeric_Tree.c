#include <stdio.h>
#include<stdlib.h>

struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
};

struct Tree* createNode(int value){
    struct Tree* node =(struct Tree*)malloc(sizeof(struct Tree));
    node->data = value;
    return node;
}

int main(){
    int num1 = 10, num2 = 20, num3 = 30, num4 = 40, num5 = 50, num6 = 70, num7 = 80;

    struct Tree* root = createNode(num1);
    struct Tree* leftChild = createNode(num2);
    struct Tree* rightChild = createNode(num3);
    struct Tree* leftLeftChild = createNode(num4);
    struct Tree* leftRightChild = createNode(num5);
    struct Tree* rightLeftChild = createNode(num6);
    struct Tree* rightRightChild = createNode(num7);
    
    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftLeftChild;
    leftChild->right = leftRightChild;
    rightChild->left = rightLeftChild;
    rightChild->right = rightRightChild;

    printf("%d\n", root->data);
    printf("%d\n", leftChild->data);
    printf("%d\n", rightChild->data);
    printf("%d\n", leftLeftChild->data);
    printf("%d\n", leftRightChild->data);
    printf("%d\n", rightLeftChild->data);
    printf("%d\n", rightRightChild->data);
    
    free(root);
    free(leftChild);
    free(rightChild);
    free(leftLeftChild);
    free(leftRightChild);
    free(rightLeftChild);
    free(rightRightChild);
}
 #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool searchElementInTree(struct Tree* root, int element){
    if(root == NULL){
        return false;
    }
    if(root->data == element){
        return true;
    }
    return searchElementInTree(root->left, element);
    return searchElementInTree(root->right, element);
}

int main(){
    int search, num1 = 2, num2 = 4, num3 = 6, num4 = 7, num5 = 5;

    printf("Please enter the element : ");
    scanf("%d", &search);

    struct Tree* root = createNode(num1);
    struct Tree* leftChild = createNode(num2);
    struct Tree* rightChild = createNode(num3);
    struct Tree* leftLeftChild = createNode(num4);
    struct Tree* leftRightChild = createNode(num5);
    
    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftLeftChild;
    leftChild->right = leftRightChild;

    bool isExist = searchElementInTree(root, search);

    if(isExist){
        printf("The element exist in the tree\n");
    }else{
        printf("the element does not exist in the tree\n");
    }

    free(root);
    free(leftChild);
    free(rightChild);
    free(leftLeftChild);
    free(leftRightChild);
    return 0;
}
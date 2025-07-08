#include <stdio.h>
#include <stdlib.h>

struct Tree{
    char data;
    struct Tree* left;
    struct Tree* right;
};

struct Tree* createNode(char value){
    struct Tree* node = (struct Tree*)malloc(sizeof(struct Tree));
    node->data = value;
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
    /*if(a > b){
        return a
    }else{
        return b}*/
}

int height(struct Tree* node){
    if (node == NULL){
        return -1;
    }
    return max(height(node->left), height(node->right)) + 1;
}


int main(){
    int num1 = 10, num2 = 20, num3 = 30, num4 = 40, num5 = 50, num6 = 60, num7 = 70, num8 = 80, num9 = 90;

    struct Tree* root = createNode(num1);
    struct Tree* leftChild = createNode(num2);
    struct Tree* rightChild = createNode(num3);
    struct Tree* leftLeftChild = createNode(num4);
    struct Tree* leftRightChild = createNode(num5);
    struct Tree* rightLeftChild = createNode(num6);
    struct Tree* rightRightChild = createNode(num7);
    struct Tree* leftLeftLeftChild = createNode(num8);
    struct Tree* rightRightRightChild = createNode(num9);
    
    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftLeftChild;
    leftChild->right = leftRightChild;
    rightChild->left = rightLeftChild;
    rightChild->right = rightRightChild;
    leftLeftChild->left = leftLeftLeftChild;
    rightRightChild->right = rightRightRightChild;

    int height_of_tree = height(root);
    printf("The height of the tree : %d\n", height_of_tree);

    free(root);
    free(leftChild);
    free(rightChild);
    free(leftLeftChild);
    free(leftRightChild);
    free(rightLeftChild);
    free(rightRightChild);
    free(leftLeftLeftChild);
    free(rightRightRightChild);
}





#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Tree{
    int data;
    struct Tree* right;
    struct Tree* left;
};

struct Tree* createTree(int value){
    struct Tree* newNode = (struct Tree*)malloc(sizeof(struct Tree));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Tree* parentOfTheNode(struct Tree* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    
    if ((root->left != NULL && root->left->data == key) || (root->right != NULL && root->right->data == key)) {
        return root;
    }

    struct Tree* leftResult = parentOfTheNode(root->left, key);
    if (leftResult != NULL) {
        return leftResult;
    }

    return parentOfTheNode(root->right, key);
}

void freeTree(struct Tree* root){
    if (root == NULL){
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(){
    int key;

    struct Tree* root = createTree(10);
    struct Tree* leftParent = createTree(20);
    struct Tree* rightParent = createTree(30);
    struct Tree* leftLeftChild = createTree(40);
    struct Tree* leftRightChild = createTree(50);
    struct Tree* rightLeftChild = createTree(60);
    struct Tree* rightRightChild = createTree(70);



    root->left = leftParent;
    root->right = rightParent;
    leftParent->left = leftLeftChild;
    leftParent->right = leftRightChild;
    rightParent->left = rightLeftChild;
    rightParent->right = rightRightChild;

    printf("Please enter the node: ");
    scanf("%d", &key);

    struct Tree* parent = parentOfTheNode(root, key);
    if (parent == NULL) {
        printf("Parent not found for node %d\n", key);
    } else {
        printf("The parent of the node %d is: %d\n", key, parent->data);
    }

    freeTree(root);
    return 0;
}
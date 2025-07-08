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

int main(){
    char c1 = 'A';
    char c2 = 'B';
    char c3 = 'C';
    struct Tree* root = createNode(c1);
    struct Tree* leftChild = createNode(c2);
    struct Tree* rightChild = createNode(c3);

    root->left = leftChild;
    root->right = rightChild;

    printf("%c\n", root->data);
    printf("%c\n", leftChild->data);
    printf("%c\n", rightChild->data);

    free(root);
    free(leftChild);
    free(rightChild);
}

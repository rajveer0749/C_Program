#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tree{
    char data[20];
    struct Tree* left;
    struct Tree* right;
};

struct Tree* createNode(char name[]){
    struct Tree* node = (struct Tree*)malloc(sizeof(struct Tree));
    strcpy(node->data, name);
    return node;
}

int main(){
    char teacher[20] = "Bhawani Shanker";
    char student1[20] = "Ayush";
    char student2[20] = "Rajveer";

    struct Tree* root = createNode(teacher);
    struct Tree* leftChild = createNode(student1);
    struct Tree* rightChild = createNode(student2);

    root->left = leftChild;
    root->right = rightChild;

    printf("%s\n", root->data);
    printf("%s\n", leftChild->data);
    printf("%s\n", rightChild->data);

    free(root);
    free(leftChild);
    free(rightChild);
}
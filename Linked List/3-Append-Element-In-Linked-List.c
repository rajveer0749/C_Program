#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int element){
    struct Node* node =(struct Node*)malloc(sizeof(struct Node));
    node->data = element;
    return node;
}

void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* append(struct Node* head, int value){
    struct Node* newNode = createNode(value);
    if(head == NULL){
        head = newNode;
        return head;
    }
    struct Node* last = head;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newNode;
    return head;
}

int main(){
    struct Node* root = NULL;
    root = append(root, 10);
    root = append(root, 20);
    root = append(root, 30);
    root = append(root, 40);
    root = append(root, 50);
    printList(root);
}

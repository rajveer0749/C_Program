#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
}; 

struct Node* createNode(int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    int num1 = 5;
    int num2 = 10;
    int num3 = 15;

    struct Node* head = createNode(num1);
    struct Node* first = createNode(num2);
    struct Node* second = createNode(num3);
    
    head->next = first;
    first->next = second;

    printList(head);
    free(head);
    free(first);
    free(second);
}

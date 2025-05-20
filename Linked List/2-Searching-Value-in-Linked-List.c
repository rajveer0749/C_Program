#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool searchValueInList(struct Node* head, int element){
    bool isExist = false;
    struct Node* temp;
    temp = head;
    while(temp != NULL){
        if(element == temp->data){
            isExist = true;
            break;
        }
        temp = temp->next;
    }
    return isExist;
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
    int num1 = 12;
    int num2 = 24;
    int num3 = 34;

    struct Node* head = createNode(num1);
    struct Node* first = createNode(num2);
    struct Node* second = createNode(num3);

    head->next = first;
    head->next->next = second;

    printList(head);
    
    int element;
    printf("Enter number for searching: ");
    scanf("%d", &element);

    bool isPresent = searchValueInList(head, element);
    if(isPresent == true){
        printf("The searched element %d does Exist in list\n", element);
    }
    else{
        printf("The searched element %d does not Exist in list\n", element);
    }
}

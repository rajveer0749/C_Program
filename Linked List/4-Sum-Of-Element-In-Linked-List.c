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
    struct Node* temp;
    temp = head;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* append(struct Node* head, int value){
    struct Node* newNode = createNode(value);
    if(head == NULL){                         //when the list is empty
        head = newNode;
        return head;
    }
    struct Node* last;                        //to check for last node 
    last = head;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newNode;                     //to append the new node 
    return head;
}

int sum(struct Node* root){
    int sum = 0;
    struct Node* temp = root;
    while(temp != NULL){
        sum = sum + temp->data;
        temp = temp->next;
    }
    return sum;
}

int main(){
    int times, num;
    printf("the number of elements:");
    scanf("%d", &times);

    struct Node* root = NULL;
    for(int i = 1; i <= times; i++){
        printf("please enter the number:");
        scanf("%d", &num);
        root = append(root, num);
    }
    printList(root);
    int result = sum(root);
    printf("the sum of the elements : %d\n", result);
    free(root);
}

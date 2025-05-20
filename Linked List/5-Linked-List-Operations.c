#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
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

void printLinkedList(struct Node* head){
    struct Node* temp;
    temp = head;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
}

struct Node* append(struct Node* head,int value){
    struct Node* newNode = createNode(value);
    if(head == NULL){
        head = newNode;
        return head;
    }
    struct Node* last;
    last = head;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newNode;
    return head;
}

struct Node* insertAtFront(struct Node* head, int value){
    struct Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

struct Node* insertAfterSpecificValue(struct Node* head, int targetValue, int newValue){
    struct Node* newNode = createNode(newValue);
    struct Node* temp = head;
    while (temp != NULL){
        if(temp->data == targetValue){
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

struct Node* insertAfterSpecificIndex(struct Node* head, int targetPosition, int newValue){
    struct Node* newNode = createNode(newValue);
    struct Node* temp = head;
    int position = 1;
    while(temp != NULL){
        if(position == targetPosition){
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        position++;
        temp = temp->next;
    }
    return head;
}

struct Node* insertBeforeSpecificValue(struct Node* head, int targetValue, int newValue){
    struct Node* newNode = createNode(newValue);
    if(head == NULL){
        printf("Error in the operation!!");
        return head;
    }
    if(head->data == targetValue){
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    while(current->next != NULL && current->next->data != targetValue){
        current = current->next;
    }

    if(current->next == NULL){
        printf("Target not found !!!"); 
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

struct Node* insertBeforeSpecificIndex(struct Node* head, int targetPosition, int newValue){
    struct Node* newNode = createNode(newValue);
    if(head == NULL){
        printf("Linked list in blank");
    }
    int position = 1;
    if(position  == targetPosition){
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    for(int i = 1; i < targetPosition - 1; i++){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

struct Node* replaceSpecificNode(struct Node* head, int targetValue, int newValue){
    struct Node* temp = head;
    while(temp->next != NULL){
        if(temp->data == targetValue){
            temp->data = newValue;
            break;
        }
        temp = temp->next;
    }
    return head;
}

struct Node* replaceAtSpecificIndex(struct Node* head, int targetIndex, int newValue){
    struct Node* temp = head;
    for(int i = 1; i < targetIndex; i++){
        temp = temp->next;
    }
    temp->data = newValue;
    return head;
}

struct Node* deleteNodeByValue(struct Node* head, int targetValue){
    struct Node* temp = head;
    struct Node* previous = NULL;
    while(temp != NULL && temp->data != targetValue){
        previous = temp;  
        temp = temp->next;
    }
    previous->next = temp->next;
    return previous;
}

struct Node* deleteNodeByPosition(struct Node* head, int position){
    struct Node* temp = head;
    struct Node* previous = NULL;
    for(int i = 1; i < position; i++){
        previous = temp;
        temp = temp->next;
    }
    previous->next = temp->next;
    return previous;
}

void printInReverseOrder(struct Node* head){
    struct Node* temp = head;
    if(temp == NULL){
        return;
    }
    printInReverseOrder(temp->next);
    printf("%d->", temp->data); 
}
 
int main(){
    printf("1.Insert in the beginning of linked-list\n2.Insert at the end of linked list\n3.Insert after a specific value of linked list\n4.Insert after a specific index of linked list\n5.insert before of specific value of linked list\n6.Insert before a specific index of linked list\n7.Replace a value of node using value\n8.replace a value of node using index\n9.Delete a node using value\n10.Delete a node using index\n");
    char choice[5] = "yes";
    char default_choice[5] = "yes";

    struct Node* head = NULL;

     while(strcmp(default_choice, choice) == 0){
        printf("do you want to continue , enter Yes or No :");
        scanf("%s", choice);
        if(strcmp(default_choice, choice) != 0){
            printInReverseOrder(head);
            break;
        }
        int len = strlen(choice);
        for(int i = 0; i < len; i++){
            choice[i] = tolower(choice[i]);
        }
        int option;
        printf("Please select the operation :");
        scanf("%d", &option);
        printf("\n");

        int num, value, position;
        switch (option){
            case 1:
            printf("Please enter the element :");
            scanf("%d", &num);
            head = insertAtFront(head, num);
            printLinkedList(head);
            printf("\n\n");
            break;

            case 2:
            printf("Please enter the elements : ");
            scanf("%d", &num);
            head = append(head, num);
            printLinkedList(head);
            printf("\n\n");
            break;

            case 3:
            printf("Please enter the the specific value :");
            scanf("%d", &value);
            printf("Please enter the element : ");
            scanf("%d", &num);
            head = insertAfterSpecificValue(head, value, num);
            printLinkedList(head);
            printf("\n\n");
            break;

            case 4:
            printf("Please enter the position :");
            scanf("%d", &position);
            printf("Please enter the element :");
            scanf("%d", &value);
            head = insertAfterSpecificIndex(head, position, value);
            printLinkedList(head);
            printf("\n\n");
            break;

            case 5:
            printf("Please enter the specific value : ");
            scanf("%d", &value);
            printf("Please enter the element :");
            scanf("%d", &num);
            head = insertBeforeSpecificValue(head, value, num);
            printLinkedList(head);
            printf("\n\n");
            break;

            case 6:
            printf("Please enter the index position : ");
            scanf("%d", &position);
            printf("Please enter the element : ");
            scanf("%d", &num);
            head = insertBeforeSpecificIndex(head, position, num);
            printLinkedList(head);
            printf("\n\n");
            free(head);
            break;

            case 7:
            printf("Please enter the specific existing value: ");
            scanf("%d", &value);
            printf("Please enter the new value: ");
            scanf("%d", &num);
            head = replaceSpecificNode(head, value, num);
            printLinkedList(head);
            printf("\n\n");
            free(head);
            break;

            case 8:
            printf("Please enter the Specific Index: ");
            scanf("%d", &position);
            printf("Enter the new Value: ");
            scanf("%d", &num);
            head = replaceAtSpecificIndex(head, position, num);
            printLinkedList(head);
            printf("\n\n");
            free(head);
            break;

            case 9:
            printf("Please Enter the Value you want to delete: ");
            scanf("%d", &value);
            head = deleteNodeByValue(head, value);
            printLinkedList(head);
            printf("\n\n");
            free(head);
            break;

            case 10:
            printf("Please Enter the index Position to delete: ");
            scanf("%d", &position);
            head = deleteNodeByPosition(head, position);
            printLinkedList(head);
            printf("\n\n"); 
            free(head);
            break;

            default :
            printf("Invalid Number ");
            printf("\n\n");   
        }
    }
}

#include <stdio.h>
int main()
{ 
    int num;
    printf("Enter the size of array: ");
    scanf("%d", &num);
    int arr[num];
    for(int i = 0; i < num; i++){
        int value;
        printf("Enter the value: ");
        scanf("%d", &value);
        arr[i] = value;
    }
    for(int i = 0; i < num; i++){
        printf("The value of array: %d\n", arr[i]);
    }
    return 0;
}

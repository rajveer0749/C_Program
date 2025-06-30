#include <stdio.h>

int main(){
    int num, original;
    printf("Please enter a number:");
    scanf("%d", &num);
    original =  num;
    int sum = 0;
    while ( num != 0){
        sum = sum + num % 10;
        num /= 10;
    }
    printf("the sum of digits of %d is : %d", original, sum);
    return 0;
}
#include <stdio.h>
#include <math.h>

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int original = num, remainder = 0, count = 0;
    int temp = num;
    while (temp != 0){
        count += 1;
        temp /= 10;
    }
    while (num != 0){
        int digit = num % 10;
        remainder = remainder + pow(digit, count);
        num /= 10;
    }
    if (remainder == original){
        printf("The number %d is Armstrong\n", original);
    } else{ 
        printf("The number %d is not Armstrong\n", original);
    }
}

#include <stdio.h> 

int main(){
    int num, original, remainder = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    original = num; 
    while(num != 0){
        int digit = num % 10;
        remainder = (remainder * 10) + digit;
        num /= 10;
    }
    printf("Reverse order of %d = %d", original, remainder);
    return 0;
}
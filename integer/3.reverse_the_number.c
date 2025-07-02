#include <stdio.h> 

int main(){
    int num, original;
    printf("Enter a number: ");
    scanf("%d", &num);
    original = num;  //123 3210
    int remainder = 0;
    while ( num != 0){
        int digit = num % 10;
        remainder = remainder * 10 + digit;
        num /= 10;
    }
    printf("Reverse order of %d is %d", original, remainder);
}
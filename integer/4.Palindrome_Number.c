#include <stdio.h> 

int main(){
    int num, original, remainder = 0;
    printf("Enter the number: ");
    scanf("%d", &num);
    original = num; 
    
    while(num != 0){
        int digit = num % 10;
        remainder = (remainder * 10) + digit;
        num /= 10;
    }
    if(original == remainder){
        printf("%d is Palindrome Number", original);
    }else{
        printf("%d is not Palindrome Number", original);
    }
    return 0;
}

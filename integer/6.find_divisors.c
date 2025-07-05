#include <stdio.h>

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int count = 0;
    for(int i = 1; i <= num; i++){
        if(num % i == 0){
            printf("%d is divisible by %d\n", num, i);
            count += 1;
        }
    }
    printf("Given number has total %d divisors\n", count);
}
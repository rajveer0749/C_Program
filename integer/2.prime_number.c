#include <stdio.h>
int main()
{
    for(int i = 2; i <= 100; i++){
        int prime = 0;
        for(int num = 2; num <= i / 2 ; num++){
            if(i % num == 0){
                prime++;
            }
        }
        if(prime == 0){
            printf("prime number: %d\n", i);
        }
    }
    return 0;
}
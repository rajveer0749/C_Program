#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void characters(char *str){
    int vowels = 0, consonants = 0, space = 0, digit = 0;
      for(int i = 0; str[i] !='\0'; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            vowels++;
        } else if(str[i] >= 'a' && str[i] <='z'){
            consonants++;;
        } else if(str[i] >= '0' && str[i] <= '9'){
            digit++;
        } else if(str[i] == ' '){
            space++;
        }
    }
    printf("The number of vowels: %d\n", vowels);
    printf("The number of consonants: %d\n", consonants);
    printf("The number of digit: %d\n", digit);
    printf("The number of space: %d\n", space);
}

char *reverse(char *str){
    int len = strlen(str);
    char *rev = malloc(len + 1);

    for (int i = 0; i < len; i++){
        rev[i] = str[len - 1 - i];
    }
    rev[len] = '\0'; 
    printf("The string after reverse: %s\n", rev);
    return rev;
}

void countWord(char *str) {
    int i = 0, count = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0')) {
            count++;
        }
        i++;
    }
    printf("The number of words: %d\n", count);
}

void palindrome(char *rev, char *str){
    char tempStr[30], tempRev[30];
    strncpy(tempStr, str, sizeof(tempStr));
    strncpy(tempRev, rev, sizeof(tempRev));
    tempStr[sizeof(tempStr) - 1] = '\0';
    tempRev[sizeof(tempRev) - 1] = '\0';

    size_t len = strlen(tempStr);
    if (len > 0 && tempStr[len - 1] == '\n') {
        tempStr[len - 1] = '\0';
    }
    len = strlen(tempRev);
    if (len > 0 && tempRev[len - 1] == '\n') {
        tempRev[len - 1] = '\0';
    }

    if (strcmp(tempRev, tempStr) == 0){
        printf("The string is palindrome\n");
    } else{
        printf("The string is not palindrome\n");
    }
}

void uppercase(char *str){
    int i = 0;
    while (str[i] != '\0'){
        str[i] = toupper(str[i]);
        //tolower(str[i]); for lowercase
        i++;
    }
    printf("Uppercase: %s", str);
}


int main(){
    char string[30];
    printf("Please enter the string: ");
    fgets(string, sizeof(string), stdin);

    size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }

    characters(string);
    char *reversed = reverse(string);
    palindrome(reversed, string);
    countWord(string);
    uppercase(string);

    free(reversed);     
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void stringPalindrome(char *str); 
char strinf_palindrom[100];
int main() {
    char string_word[] = "madam";
    char *temp = string_word;
    stringPalindrome(temp);
    printf("%s\n",strinf_palindrom);
    if(strcmp(strinf_palindrom, string_word)==0) {
        printf("String is palindrome");
    }
    else {
        printf("String is not palindrome");
    }
    return 0;
}
void stringPalindrome(char *str) {
    char *end = str + strlen(str)-1;
    int i=0;
    while (str<=end)
    {
        char temp = *str;
        *str = *end;
        *end = temp;
        strinf_palindrom[i] = *str;
        i++;
        
        str++;
        end--;
        //printf("%s ",strinf_palindrom);
    }
    strinf_palindrom[i]= '\0';
}
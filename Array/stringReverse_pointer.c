// input -> "Hi Hello World"
// output -> "iH olleH dlroW"

#include<stdio.h>
void reverseString(char *str);
void reverseWord(char *start, char *end);
int main() {
    char string_word[] = "Hi Hello World";
    printf("%s\n",string_word);
    reverseString(string_word);
    printf("%s",string_word);
    return 0;
}
void reverseString(char *str) {
    char *temp = str;
    char *word_start = str;

    while (*temp!='\0')
    {
        if(*temp == ' ')
        {
            reverseWord(word_start, temp-1);
            word_start = temp+1;
        }
        temp++;
        /* code */
    }
    reverseWord(word_start,temp-1);
    
}
void reverseWord(char *start, char *end) {
    
    while (start<end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
        /* code */
    }
    
}
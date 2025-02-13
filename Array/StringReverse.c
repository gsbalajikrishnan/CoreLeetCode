#include<stdio.h>
#include<string.h>
void reverseWord(char name[])
{
    int i=0;
    int j = strlen(name)-1;

    while (i < j)
    {
        char temp = name[i];
        name[i]=  name[j];
        name[j] = temp;
        i++;
        j--;
        /* code */
    }
}
int main()
{
    char name[] = "Hi balaji how are you";
    int i=0,wordIndex=0;
    int j = strlen(name)-1;
    char word[100];

    while (i<=j)
    {
        if(name[i]==' ' || name[i]=='\0')
        {
            word[wordIndex] = '\0';
            reverseWord(word);
            printf("%s ",word);
            wordIndex = 0;

        }
        else
        {
            word[wordIndex] = name[i];
            wordIndex++;
        }
        i++;
    }
    word[wordIndex] = '\0';
    reverseWord(word);
    printf("%s ",word);   
}
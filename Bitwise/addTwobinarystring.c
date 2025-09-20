#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *addTwobinary(char *str1, char *str2) {
    int i,j,sum=0,carry=0;
    i  = strlen(str1)-1;
    j  =  strlen(str2)-1;
    int maxlen = (i>j ? i:j)+1;
    int k=0;
    char *result = (char*)malloc(maxlen+2);
    while(i>=0 || j>=0 || carry!=0)
    {
        sum =  carry;
        if(i>=0) 
            sum = sum + str1[i]-'0';
        if(j>=0)
            sum = sum + str2[j]-'0';
        
        result[k] = sum%2 + '0';
        carry = sum / 2;
        i--;
        j--;
        k++;
        /* code */
    }
    result[k]='\0';
    int l=0;
    int len = k-1;
    while(l<=len)
    {
        char temp = result[l];
        result[l] = result[len];
        result[len] = temp;
        l++;
        len--;
    }
    return result;
}
int main() {
    char str1[]="1101";
    char str2[]="0110";
    printf("Before add: \n %s \n %s \n",str1,str2);
    char *value = addTwobinary(str1,str2);
    printf("After add: %s",value);
    free(value);
    
    return 0;
}
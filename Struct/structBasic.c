#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "strucBasic.h"
#include <stddef.h>
int data;
union aes
{
    int iv;
    char mode[20];
    float key;
    
    /* data */
};
void func(union aes *a)
{
    a->iv = 20;
    a->key = 190585;
    strcpy(a->mode, "ECE");
    /* data */
};
int main()
{
    union aes ae;
    ae.iv = 10;
    strcpy(ae.mode, "CBC");
    
    ae.key = 12345;
    //data = 10;
    printf("Before : %d\n", data);

    printf("%d\n", ae.iv);
    printf("%d\n",ae.key);
    printf("%s\n",ae.mode);

    printf("%d bytes\n",sizeof(ae));

    
    /* printf("mode offset: %ld\n", offsetof(struct aes, mode));
    printf("iv offset: %ld\n", offsetof(struct aes, iv));
    printf("key offset: %ld\n", offsetof(struct aes, key));
 */


    func(&ae);

    printf("After\n");

    printf("%d\n", ae.iv);
    printf("%d\n",ae.key);
    printf("%s",ae.mode);
    
    return 0;    
}

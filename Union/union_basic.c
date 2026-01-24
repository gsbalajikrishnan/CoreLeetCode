#include<stdio.h>

struct rsa
{
    int num;
    int max;
    /* data */
};
struct ecc
{
    int num;
    int max;
    /* data */
};
union crypto
{
    struct rsa rs;
    struct ecc ec;
};
int main()
{
    union crypto cry;
    cry.rs.num = 10;
    cry.rs.max = 20;
    //cry.ec.max= 30;
    //cry.ec.num = 50;
    printf("%d ",sizeof(cry));
    printf("%d ",cry.rs.num);
    printf("%d ", cry.rs.max);
    printf("%d ",cry.ec.num);
    printf("%d ", cry.ec.max);
    
    return 0;
}

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
    printf("%d ",sizeof(cry));
    printf("%d ",cry.rs.num);
    return 0;
}

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#define MAX_SIZE 10

int buffer[MAX_SIZE];
int receivebuffer[MAX_SIZE];
pthread_mutex_t lock;
void *send(void *args) {
    int i;
    printf("Thread %d started\n",*(int*)args);
    pthread_mutex_lock(&lock);
    for(i=0;i<MAX_SIZE;i++)
    {
        buffer[i] = rand()%10;
        printf("%d ",buffer[i]);
    }
    sleep(2);
    pthread_mutex_unlock(&lock);
    return NULL;
}
void *receive(void *args) {
    int i;
    printf("\nThread %d started\n",*(int*)args);
    pthread_mutex_lock(&lock);
    for(i=0;i<MAX_SIZE;i++)
    {
        receivebuffer[i]=buffer[i];
        printf("%d ",receivebuffer[i]);
    }
    
    pthread_mutex_unlock(&lock);
    return NULL;
}
int main()
{
    int i;
    pthread_t t1,t2;
    int id1=1,id2=2;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&t1,NULL,send,&id1);
    pthread_create(&t2,NULL,receive,&id2);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
    return 0;
}
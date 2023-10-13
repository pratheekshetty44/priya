#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int id;
    id=fork();

    if(id<0)
    {
        printf("not valid");

    }
    else if(id==0)
    {
        sleep(8);
        printf("am the child\n");
        //printf("%d\n",getpid());
    }

    else
    {
        //wait((int*)NULL);
        printf("am the parent");
        //printf("%d\n",getpid());
    }
    return 0;
}
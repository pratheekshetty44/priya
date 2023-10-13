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
        printf("invalid");
    }
    else if(id==0)
    {
        printf("list of files\n");
        system("ls -1");

    }
    else
    {
        wait((int*)NULL);
        printf("parent:child process completed \n");
    }
    return 0;
}
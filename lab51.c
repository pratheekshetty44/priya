#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int id;
    id=fork();
    if(id==-1)
    {
        printf("fork failed");
        exit(-1);
    }
    else if(id==0)
    {
        printf("Am the child with id %d\n,am the parent with id %d\n ",getpid(),getppid());
    }
    else
    {
        printf("parent process with id %d,child process with id %d\n",getpid(),id);
    }

    return 0;

}
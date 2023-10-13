#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int id;
    int status;
    id=fork();

    if(id<0)
    {
        printf("invalid");
    }
    else if(id==0)
    {
        printf("Priyanka H B\n");
        exit(255);
    }
    else
    {
        wait(&status);
        if(WIFEXITED(status)){
            printf("Parent:child process completed with exit value %d",WEXITSTATUS(status));
        }
    }
    return 0;
}
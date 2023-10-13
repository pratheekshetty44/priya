#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int id,id2,id3;
    id=fork();
    
    int status;

    if(id<0)
    {
        printf("invalid");
    }
    else if(id==0)
    {
         execl("/bin/ls","ls",NULL);
        printf("list of files\n");
        system("ls");
    }

    id2=fork();
    
    if(id2<0)
    {
        printf("invalid");
    }
    else if(id2==0)
    {
         execl("/bin/date","date",NULL);
        printf("printing date\n");
        system("date");
    }

    id3=fork();

    if(id3<0)
    {
        printf("invalid");
    }
    else if(id3==0)
    {
         execl("/bin/pwd","pwd",NULL);
        printf("printing pwd\n");
        system("pwd");
    }

    wait(NULL);
     wait(NULL);
      wait(NULL);
    printf("all the process completed");
    
    return 0;
}

    
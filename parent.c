#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>

int main(void)
{
    int id=0;
    id=fork();
    if(id>0)
    {
        sleep(5);
        printf("I,m parent my id is %d\n",getpid());

    }
    else if(id==0)
    {
        printf("I'm child my id is %d\n",getpid());
        printf("Hello MSIS\n");

    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{   
    int n;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    int id=fork();
    if(id<0){
        printf("process not created\n");
        exit(-1);
    }
    else if(id==0){
        int sum=0;
        for(int i=1;i<=n;i++)
        sum+=i;
    printf("child process executed sum of n is %d\n",sum);
    }
    else{
        wait(NULL);
        printf("Parent :child process has completed\n");
    }
    return 0;
}
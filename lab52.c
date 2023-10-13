#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
   int id=0;
   int status;
   id=fork();

   if(id<0)
   {
    printf("fork failed");
    
   } 
   else if(id==0)
   {
    int count=0;
    while(count<1000)
        count++;
    printf("child with id %d\n",getpid());
    exit(255);
    
   }
   else
   {
    waitpid(id,&status,0);
    printf("the parent process with id %d\n",getpid());
    if(WIFEXITED(status)){
    printf("parent: child process completed \n");
    printf("the exit status %d\n",WEXITSTATUS(status));
    }
    
   }
   return 0;
}

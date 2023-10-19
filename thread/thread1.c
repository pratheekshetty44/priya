#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *thread_function(void *arg)
{
    int upper_limit = *((int *)arg);
    int sum=0;

    for(int i=1; i<=upper_limit; i++)
    {
        sum = sum + i;
    }
    printf("Thread ID: %lu, Sum of first %d numbers: %d\n", pthread_self(), upper_limit, sum);

    pthread_exit(NULL);
}

int main()
{
    pid_t pid = getpid();
    printf("Main Thread PID: %d\n", pid);

    int upper_limit;
    printf("Enter the upper limit for summation: ");
    scanf("%d", &upper_limit);

    pthread_t t1;
    int rc;

    rc = pthread_create(&t1, NULL, thread_function, (void *)&upper_limit);
    if(rc)
    {
        printf("Error creating thread; return code: %d\n", rc);
        exit(-1);
    }

    pthread_join(t1, NULL);

    return 0;
}
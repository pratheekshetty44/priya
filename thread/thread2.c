/* case 1 -> using a global variable for 'n' */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// global variable to store the value of n

int n = 0;

void *thread_function(void *arg)
{
    char *msg = (char *)arg;
    for(int i=0; i<n; i++)
    {
        printf("%s\n", msg);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1[3];
    char msg[100];

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(int i=0; i<3; i++)
    {
        printf("Enter a message for thread %d: ", i+1);
        scanf("%s", msg);
        pthread_create(&t1[i], NULL, thread_function, (void *)msg);
    }

    for(int i=0; i<3; i++)
    {
        pthread_join(t1[i], NULL);
    }

    return 0;
}
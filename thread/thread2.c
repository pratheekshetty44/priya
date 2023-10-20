

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>



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
    char msg1[100];
    char msg2[100];
    char msg3[100];

    printf("Enter the value of n: ");
    scanf("%d", &n);

   
    
        printf("Enter a message for thread 1: ");
        scanf("%s", msg1);
         printf("Enter a message for thread 2: ");
        scanf("%s", msg2);
         printf("Enter a message for thread 3: ");
        scanf("%s", msg3);

        pthread_create(&t1[0], NULL, thread_function, (void *)msg1);
        pthread_create(&t1[1], NULL, thread_function, (void *)msg2);
        pthread_create(&t1[2], NULL, thread_function, (void *)msg3);
    

    for(int i=0; i<3; i++)
    {
        pthread_join(t1[i], NULL);
    }

    return 0;
}
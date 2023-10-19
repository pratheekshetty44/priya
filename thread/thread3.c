#include <pthread.h>
#include <stdio.h>

void *f1(void* p1)
{
    int n1 = *(int *)p1;
    for(int i=0; i<n1; i++)
    {
        printf("Hello, thread1 here!!!!\n");
    }
    pthread_exit(0);
}

void *f2(void* p2)
{
    int n2 = *(int *)p2;
    for(int i=0; i<n2; i++)
    {
        printf("Hello, thread2 here!!!!\n");
    }
    pthread_exit(0);
}

int main()
{
    pthread_t t1, t2;
    int n1, n2;

    printf("Hello, main thread here !!!\n");

    //read n1 and n2 from the user
    printf("Enter an integer n1 within 1 to 9: ");
    scanf("%d", &n1);
    printf("Enter an integer n2 within 1 to 9: ");
    scanf("%d", &n2);

    if(n1 < 1 || n1>9 || n2<1 || n2>9)
    {
        printf("Invalid input. n1 and n2 should be between 1 and 9 \n");
        return 1;
    }

    pthread_create(&t1, NULL, f1, &n1);
    pthread_create(&t2, NULL, f2, &n2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}

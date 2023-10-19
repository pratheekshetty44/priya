#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100

int global_array[MAX_ARRAY_SIZE];
int array_len;

void *f1(void* p1)
{
    int *arr = (int *)p1;
    int sum=0;

    for(int i=0; i<array_len; i++)
    {
       sum = sum + arr[i];
    }

    printf("Sum of array elements: %d \n", sum);
    pthread_exit(0);
}

void *f2(void* p2)
{
    int *arr = (int *)p2;

    printf("Odd numbers in the array: ");
    for(int i=0; i<array_len; i++)
    {
       if(arr[i]%2 != 0)
       {
           printf("%d", arr[i]);
       }
    }

    printf("\n");
    pthread_exit(0);
}

int main()
{
    pthread_t t1, t2;

    printf("Enter the length of the array from 1 to 100: ");
    scanf("%d", &array_len);

    if(array_len<1 || array_len > MAX_ARRAY_SIZE)
    {
        printf("Invalid array length. Should be between 1 and 100 \n");
        return 1;
    }

    printf("Enter %d elements for the array: \n", array_len);
    for(int i=0; i<array_len; i++)
    {
        scanf("%d", &global_array[i]);
    }

    pthread_create(&t1, NULL, f1, global_array);
    pthread_create(&t2, NULL, f2, global_array);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
#include <stdio.h>
#include <pthread.h>

#define MAX_ARRAY_SIZE 100


int array[MAX_ARRAY_SIZE];
int array_length;


void *computeSum(void *args) {
    int sum = 0;
    for (int i = 0; i < array_length; i++) {
        sum += array[i];
    }
    printf("Sum of array elements: %d\n", sum);
    pthread_exit(NULL);
}


void *publishOddNumbers(void *args) {
    printf("Odd numbers in the array: ");
    for (int i = 0; i < array_length; i++) {
        if (array[i] % 2 != 0) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
    pthread_exit(NULL);
}

int main() {
  
    printf("Enter the length of the array: ");
    scanf("%d", &array_length);

    if (array_length <= 0 || array_length > MAX_ARRAY_SIZE) {
        printf("Invalid array length.\n");
        return 1;
    }


    printf("Enter %d elements for the array:\n", array_length);
    for (int i = 0; i < array_length; i++) {
        scanf("%d", &array[i]);
    }

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, computeSum, NULL);
    pthread_create(&thread2, NULL, publishOddNumbers, NULL);


    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

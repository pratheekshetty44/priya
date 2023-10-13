#include <stdio.h>
#include <pthread.h>


int n1, n2;


void *displayMessage(void *args) {
    char *message = (char *)args;
    int count = *((int *)args + 1);

    for (int i = 0; i < count; i++) {
        printf("%s\n", message);
    }

    pthread_exit(NULL);
}

int main() {

    printf("Hello, main thread here!\n");


    printf("Enter the value of n1 (1-9): ");
    scanf("%d", &n1);
    printf("Enter the value of n2 (1-9): ");
    scanf("%d", &n2);


    pthread_t thread1, thread2;
    char message1[] = "Hello, thread1 here!";
    char message2[] = "Hello, thread2 here!";


    int params1[2] = {n1, n1};
    int params2[2] = {n2, n2};

    pthread_create(&thread1, NULL, displayMessage, params1);
    pthread_create(&thread2, NULL, displayMessage, params2);


    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

#include <stdio.h>
#include <pthread.h>
#include <string.h>


void *displayMessage(void *args) {
    char *message = (char *)args;
    int count = *((int *)args + 1);

    for (int i = 0; i < count; i++) {
        printf("%s\n", message);
    }

    pthread_exit(NULL);
}

int main() {

    pthread_t thread1, thread2, thread3;
    char message1[100], message2[100], message3[100];
    
    int n1, n2, n3;
    
    printf("Enter the value of n for thread 1: ");
    scanf("%d", &n1);
    printf("Enter the value of n for thread 2: ");
    scanf("%d", &n2);
    printf("Enter the value of n for thread 3: ");
    scanf("%d", &n3);

    printf("Enter message for thread 1: ");
    scanf("%s", message1);
    printf("Enter message for thread 2: ");
    scanf("%s", message2);
    printf("Enter message for thread 3: ");
    scanf("%s", message3);


    int params1[2] = {n1, n1};
    int params2[2] = {n2, n2};
    int params3[2] = {n3, n3};

    pthread_create(&thread1, NULL, displayMessage, params1);
    pthread_create(&thread2, NULL, displayMessage, params2);
    pthread_create(&thread3, NULL, displayMessage, params3);

 
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}

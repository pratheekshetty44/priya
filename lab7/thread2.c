#include <stdio.h>
#include <pthread.h>
#include <string.h>

int n;


void *displayMessage(void *message) {
    char *msg = (char *)message;
    for (int i = 0; i < n; i++) {
        printf("%s\n", msg);
    }
    pthread_exit(NULL);
}

int main() {
    
    printf("Enter the value of n: ");
    scanf("%d", &n);

    
    pthread_t thread1, thread2, thread3;
    char message1[] = "Im thread 1";
    char message2[] = "Im thread 2";
    char message3[] = "Im thread 3";

    pthread_create(&thread1, NULL, displayMessage, message1);
    pthread_create(&thread2, NULL, displayMessage, message2);
    pthread_create(&thread3, NULL, displayMessage, message3);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}

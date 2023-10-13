#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct ThreadParams {
    int upper_limit;
};


void *calculateSum(void *args) {
    struct ThreadParams *params = (struct ThreadParams *)args;
    int upper_limit = params->upper_limit;
    int sum = 0;

    for (int i = 1; i <= upper_limit; i++) {
        sum += i;
    }

    printf("Thread ID: %lu\n", pthread_self());
    printf("Sum of numbers from 1 to %d: %d\n", upper_limit, sum);
    
    pthread_exit(NULL);
}

int main() {

    pid_t main_pid = getpid();
    printf("Main Thread PID: %d\n", main_pid);


    pthread_t thread;
    struct ThreadParams params;

    printf("Enter the upper limit for summation: ");
    scanf("%d", &params.upper_limit);

 
    if (pthread_create(&thread, NULL, calculateSum, &params) != 0) {
        perror("Thread creation failed");
        return 1;
    }

    pthread_join(thread, NULL);

    return 0;
}

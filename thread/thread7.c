/* If you want to compute the sum of rows with 3 threads
and then calculate the total sum in the main thread, you can use the following modified program: */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROWS 3
#define COLUMNS 4

int global_matrix[ROWS][COLUMNS];

// Function for thread to compute row sum
void *row_sum_function(void *arg) {
    int row = *(int *)arg;
    int sum = 0;

    for (int j = 0; j < COLUMNS; j++) {
        sum += global_matrix[row][j];
    }

    printf("Thread: Row %d Sum = %d\n", row, sum);
    pthread_exit((void *)(intptr_t)sum);
}

int main() {
    pthread_t threads[ROWS];
    int row;

    // Populate the matrix with integers
    printf("Enter %d x %d matrix elements:\n", ROWS, COLUMNS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            scanf("%d", &global_matrix[i][j]);
        }
    }

    int total_sum = 0;

    // Create 3 threads, each computing row sum
    for (row = 0; row < ROWS; row++) {
        pthread_create(&threads[row], NULL, row_sum_function, &row);
    }

    // Wait for the threads to finish and compute the total sum
    for (row = 0; row < ROWS; row++) {
        void *result;
        pthread_join(threads[row], &result);
        total_sum += (int)(intptr_t)result;
    }

    printf("Total Sum of Matrix = %d\n", total_sum);

    return 0;
}
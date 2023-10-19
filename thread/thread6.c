/* To create a C program that defines a global integer matrix, populates it,
 and then creates 4 threads to compute the column sum, you can use the following code: */

 #include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROWS 3
#define COLUMNS 4

int global_matrix[ROWS][COLUMNS];

// Function for thread to compute column sum
void *column_sum_function(void *arg) {
    int col = *(int *)arg;
    int sum = 0;

    for (int i = 0; i < ROWS; i++) {
        sum += global_matrix[i][col];
    }

    printf("Thread: Column %d Sum = %d\n", col, sum);
    pthread_exit((void *)(intptr_t)sum);
}

int main() {
    pthread_t threads[COLUMNS];
    int col;

    // Populate the matrix with integers
    printf("Enter %d x %d matrix elements:\n", ROWS, COLUMNS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            scanf("%d", &global_matrix[i][j]);
        }
    }

    // Create 4 threads, each computing column sum
    for (col = 0; col < COLUMNS; col++) {
        pthread_create(&threads[col], NULL, column_sum_function, &col);
    }

    int total_sum = 0;

    // Wait for the threads to finish and compute total sum
    for (col = 0; col < COLUMNS; col++) {
        void *result;
        pthread_join(threads[col], &result);
        total_sum += (int)(intptr_t)result;
    }

    printf("Total Sum of Matrix = %d\n", total_sum);

    return 0;
}

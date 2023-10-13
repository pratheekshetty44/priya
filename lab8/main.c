#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{Process *my_process;
    int n;
    printf("Enter the number process to be created:\n");
    scanf("%d",&n);
    my_process=initialise(n);
    burst_time(my_process,n);
    turnaround_time(my_process,n);
    waiting_time(my_process,n);
    display(my_process,n);
    display_avg(my_process,n);
    return 0;
    }

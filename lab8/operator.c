#include<stdio.h>
#include <stdlib.h>

#include "header.h"
Process *initialise(int size)
{
    Process *my_process;
    my_process=(Process*)malloc(sizeof(Process));
    my_process->total_process=size;
    my_process->data=(Pdata*)malloc(sizeof(Pdata)*size);
    return my_process;
}
int burst_time(Process *P,int size)
{
    int i;
    for(i=0;i<size;i++){
        printf("Enter the burst time of process %d:\n",i+1);
        scanf("%d",&P->data[i].burst_time);
    }
    return SUCCESS;
}
int turnaround_time(Process *my_process,int size)
{
    int i;
    for(i=0;i<size;i++){
        if(i==0)
            my_process->data[i].turnaround_time=my_process->data[i].burst_time;
        else{
            my_process->data[i].turnaround_time=my_process->data[i-1].turnaround_time+my_process->data[i].burst_time;
        }
    }
    return SUCCESS;
}
int waiting_time(Process* my_process,int size)
{
    int i;
    for(i=0;i<size;i++){
        if(i==0)
            my_process->data[i].waiting_time=0;
        else
            my_process->data[i].waiting_time=my_process->data[i-1].turnaround_time;
    }
    return SUCCESS;
}
void display(Process*my_process,int size)
{
    int i;
    printf("Process\tB.t\tT.A.T\tW.T\n");
    for(i=0;i<size;i++){
        printf("P%d\t%d\t%d\t%d\n",i+1,my_process->data[i].burst_time,my_process->data[i].turnaround_time,my_process->data[i].waiting_time);
    }
}
void display_avg(Process*my_process,int size)
{
    int i;
    float sum_t=0,sum_wa=0;
    for(i=0;i<size;i++){
        sum_t=sum_t+my_process->data[i].turnaround_time;
        sum_wa=sum_wa+my_process->data[i].waiting_time;
    }
    printf("The average turnaround time is %f\n",sum_t/size);
    printf("The average waiting time is %f\n",sum_wa/size);
}

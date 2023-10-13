#define FAIL 0
#define SUCCESS 1
struct _processdata_
{
    int burst_time;
    int arrival_time;
    int turnaround_time;
    int waiting_time;
};
typedef struct _processdata_ Pdata;

struct _process_
{
    Pdata *data;
    int total_process;
};
typedef struct _process_ Process;
Process *initialise(int size);
int burst_time(Process *,int);
int turnaround_time(Process *,int);
int waiting_time(Process*,int);
void display(Process*,int);

void display_avg(Process*,int);

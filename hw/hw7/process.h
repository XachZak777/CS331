#ifndef PROCESS_H
#define PROCESS_H

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
};

void FCFS(struct Process p[], int n);
void SJF(struct Process p[], int n);

#endif

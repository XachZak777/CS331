#include <stdio.h>
#include "process.h"

void sortByArrival(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void displayGantt(struct Process p[], int order[], int n) {
    printf("Gantt Chart:\n");
    for (int i = 0; i < n; i++) printf("|  P%d  ", order[i]);
    printf("|\n\n");
}

void FCFS(struct Process p[], int n) {
    struct Process proc[50];
    for (int i = 0; i < n; i++) proc[i] = p[i];
    sortByArrival(proc, n);

    int current_time = 0;
    float total_wt = 0, total_tat = 0, total_rt = 0;
    int order[50];

    for (int i = 0; i < n; i++) {
        if (current_time < proc[i].arrival_time)
            current_time = proc[i].arrival_time;

        proc[i].waiting_time = current_time - proc[i].arrival_time;
        proc[i].response_time = proc[i].waiting_time;
        current_time += proc[i].burst_time;
        proc[i].turnaround_time = current_time - proc[i].arrival_time;

        total_wt += proc[i].waiting_time;
        total_tat += proc[i].turnaround_time;
        total_rt += proc[i].response_time;
        order[i] = proc[i].pid;
    }

    printf("\nFirst Come First Served (FCFS)\n");
    displayGantt(proc, order, n);

    printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               proc[i].pid, proc[i].arrival_time, proc[i].burst_time,
               proc[i].waiting_time, proc[i].turnaround_time, proc[i].response_time);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Response Time: %.2f\n", total_rt / n);
}


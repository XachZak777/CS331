#include <stdio.h>
#include "process.h"

void SJF(struct Process p[], int n) {
    struct Process proc[50];
    for (int i = 0; i < n; i++) proc[i] = p[i];

    int completed[50] = {0};
    int current_time = 0, completed_count = 0;
    float total_wt = 0, total_tat = 0, total_rt = 0;
    int order[50], order_index = 0;

    printf("\nShortest Job First (SJF)\n");

    while (completed_count < n) {
        int idx = -1;
        int min_bt = 99999;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && proc[i].arrival_time <= current_time) {
                if (proc[i].burst_time < min_bt) {
                    min_bt = proc[i].burst_time;
                    idx = i;
                } else if (proc[i].burst_time == min_bt) {
                    if (proc[i].arrival_time < proc[idx].arrival_time)
                        idx = i;
                }
            }
        }

        if (idx == -1) {
            current_time++;
            continue;
        }

        proc[idx].waiting_time = current_time - proc[idx].arrival_time;
        proc[idx].response_time = proc[idx].waiting_time;
        current_time += proc[idx].burst_time;
        proc[idx].turnaround_time = current_time - proc[idx].arrival_time;

        total_wt += proc[idx].waiting_time;
        total_tat += proc[idx].turnaround_time;
        total_rt += proc[idx].response_time;
        order[order_index++] = proc[idx].pid;

        completed[idx] = 1;
        completed_count++;
    }

    printf("Gantt Chart:\n");
    for (int i = 0; i < order_index; i++) printf("|  P%d  ", order[i]);
    printf("|\n\n");

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


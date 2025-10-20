#include <stdio.h>
#include "process.h"

int main() {
    int n;
    struct Process p[20];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
    }

    FCFS(p, n);
    SJF(p, n);

    return 0;
}


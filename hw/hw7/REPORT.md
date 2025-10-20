# Process Scheduling Simulation (FCFS & SJF)
The goal of this assignment is to implement and compare two **non-preemptive CPU scheduling algorithms** in C:
1. **First Come First Served (FCFS)**
2. **Shortest Job First (SJF)**
The program simulates how processes are executed based on arrival and burst times, and calculates:
- **Waiting Time**
- **Turnaround Time**
- **Response Time**
---
### Algorithms Implemented
- **FCFS (First Come First Served)**  
  - Processes are executed in the order they arrive.  
  - Sorting is done by `arrival_time`.  
- **SJF (Shortest Job First, Non-preemptive)**  
  - Among available processes, the one with the smallest `burst_time` is executed next.  
  - If two processes have the same burst time, the one with the earlier `arrival_time` is chosen.
---
## How to Compile and Run
```bash
gcc main.c fcfs.c sjf.c -o scheduler
./scheduler
```
---
## Sample Input
```
Enter the number of processes: 4
Enter Arrival Time and Burst Time for Process 1: 0 8
Enter Arrival Time and Burst Time for Process 2: 1 4
Enter Arrival Time and Burst Time for Process 3: 2 9
Enter Arrival Time and Burst Time for Process 4: 3 5
```
---
## Sample Output
### **FCFS Scheduling**
```
First Come First Served (FCFS)
Gantt Chart:
|  P1  |  P2  |  P3  |  P4  |

PID   AT   BT   WT   TAT  RT
1     0    8    0    8    0
2     1    4    7    11   7
3     2    9    10   19   10
4     3    5    18   23   18

Average Waiting Time: 8.75
Average Turnaround Time: 15.25
Average Response Time: 8.75
```
### **SJF Scheduling**
```
Shortest Job First (SJF)
Gantt Chart:
|  P2  |  P4  |  P1  |  P3  |

PID   AT   BT   WT   TAT  RT
1     0    8    0    8    0
2     1    4    7    11   7
4     3    5    9    14   9
3     2    9    15   24   15

Average Waiting Time: 7.75
Average Turnaround Time: 14.25
Average Response Time: 7.75
```
---
## Explanation

In **FCFS**, processes are executed in the order of arrival.  
  This can lead to **long waiting times** if an early process has a long burst time.  

In **SJF**, shorter jobs are executed first, which **reduces the average waiting time**.  
  However, it requires knowledge of burst times beforehand and can cause **starvation** for longer processes.

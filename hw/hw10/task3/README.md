To run Task 3 use the following command:

```shell
gcc -lpthread assignment3.c -o task3 && ./task3
```
*Short Explanation*

Semaphores alone manage resource availability (buffer slots) but do not protect simultaneous access to shared data structures. The mutex prevents multiple threads from corrupting the buffer or counters during concurrent updates.

*Output*

```shell
khachikz@ubuntu-aua-os:~/CS331/hw/hw10/task3$ gcc -lpthread assignment3.c -o a3 && ./a3
[INFO] Starting Producer-Consumer Simulation...
[INFO] Producer produced 1 
[INFO] Consumer consumed 1 
[INFO] Producer produced 2 
[INFO] Consumer consumed 2 
[INFO] Producer produced 3 
[INFO] Producer produced 4 
[INFO] Consumer consumed 3 
[INFO] Consumer consumed 4 
[INFO] Producer produced 5 
[INFO] Consumer consumed 5 
[INFO] Producer produced 6 
[INFO] Consumer consumed 6 
[INFO] Producer produced 7 
[INFO] Consumer consumed 7 
[INFO] Producer produced 8 
[INFO] Consumer consumed 8 
[INFO] Producer produced 9 
[INFO] Producer produced 10 
[INFO] Consumer consumed 9 
[INFO] Consumer consumed 10 
[INFO] Producer produced 11 
[INFO] Producer produced 12 
[INFO] Consumer consumed 11 
[INFO] Consumer consumed 12 
[INFO] Producer produced 13 
[INFO] Consumer consumed 13 
[INFO] Producer produced 14 
[INFO] Consumer consumed 14 
[INFO] Producer produced 15 
[INFO] Consumer consumed 15 
[INFO] Producer produced 16 
[INFO] Consumer consumed 16 
[INFO] All Threads Executed Successfully... 
[TASK] Total items produced: 16
[TASK] Total items consumed: 16
[INFO] Completing Program...
```

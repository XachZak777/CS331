To run Task 5 use the following command:

```shell
gcc -lpthread assignment5.c -o task5 && ./task5
```
*Short Explanation*

A counting semaphore ensures that no more than K threads enter the printing section at the same time.
If the semaphore is initialized to 1, it behaves like a mutex, which means that only one printer, so jobs run one at a time.
If it is initialized to a value greater than the real number of printers, too many threads enter the printing section simultaneously, violating resource limits.

*Output*

```shell
khachikz@ubuntu-aua-os:~/CS331/hw/hw10/task5$ gcc -lpthread assignment5.c -o task5 && ./task5
[INFO] Starting Printer Pool Simulation...
[INFO] Total threads: 10, Available printers: 3
[INFO] Semaphore initialized with 3 printers.
[THREAD 0] Waiting for a free printer...
[THREAD 0] Started printing. Active printers: 1
[THREAD 1] Waiting for a free printer...
[THREAD 1] Started printing. Active printers: 2
[THREAD 6] Waiting for a free printer...
[THREAD 6] Started printing. Active printers: 3
[THREAD 5] Waiting for a free printer...
[THREAD 8] Waiting for a free printer...
[THREAD 2] Waiting for a free printer...
[THREAD 3] Waiting for a free printer...
[THREAD 4] Waiting for a free printer...
[THREAD 9] Waiting for a free printer...
[THREAD 7] Waiting for a free printer...
[THREAD 0] Finished printing. Active printers: 2
[THREAD 5] Started printing. Active printers: 3
[THREAD 1] Finished printing. Active printers: 2
[THREAD 2] Started printing. Active printers: 3
[THREAD 6] Finished printing. Active printers: 2
[THREAD 3] Started printing. Active printers: 3
[THREAD 5] Finished printing. Active printers: 2
[THREAD 4] Started printing. Active printers: 3
[THREAD 2] Finished printing. Active printers: 2
[THREAD 8] Started printing. Active printers: 3
[THREAD 3] Finished printing. Active printers: 2
[THREAD 9] Started printing. Active printers: 3
[THREAD 4] Finished printing. Active printers: 2
[THREAD 7] Started printing. Active printers: 3
[THREAD 8] Finished printing. Active printers: 2
[THREAD 9] Finished printing. Active printers: 1
[THREAD 7] Finished printing. Active printers: 0
[INFO] All print jobs completed.
[INFO] Program Finished.
```

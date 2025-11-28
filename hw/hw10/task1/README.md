To run Task 1 use the following command:
```shell
gcc -lpthread assignment1.c -o task1
./task1
```
User will be prompted to use arguments:
```shell
Usage: ./task1 [A | B | C]
A = No sync
B = Mutex
C = Spinlock
```
Then user can use the following commands for running with different approaches:
```shell
./task1 A
./task1 B
./task1 C
```
*Short Explanation*

Version A can give the wrong result because `counter++` is not atomic. Two threads can read-modify-write simultaneously and overwrite updates (race condition). Versions B and C lock access to the shared variable using mutex or spinlock, ensuring only one thread updates counter at a time and preventing lost updates.

*Output*

Part A
```shell
khachikz@ubuntu-aua-os:~/CS331/hw/hw10/task1$ ./a1 A
[INFO] Starting Program...
[INFO] Mode Selected: A
[INFO] Creating 4 threads 
[INFO] Creating threads...
[THREAD] Started with mode A
[INFO] Waiting for threads to complete...
[THREAD] Started with mode A
[THREAD] Started with mode A
[THREAD] Started with mode A
[THREAD] Finished mode A
[THREAD] Finished mode A
[THREAD] Finished mode A
[THREAD] Finished mode A
[INFO] All Threads Executed Successfully... 
[RESULT] Expected: 4000000
[RESULT] Actual:   1988235
[INFO] Program Completed.
```
Part B
```shell
khachikz@ubuntu-aua-os:~/CS331/hw/hw10/task1$ ./a1 B
[INFO] Starting Program...
[INFO] Mode Selected: B
[INFO] Creating 4 threads 
[INFO] Initializing MUTEX...
[INFO] Creating threads...
[THREAD] Started with mode B
[INFO] Waiting for threads to complete...
[THREAD] Started with mode B
[THREAD] Started with mode B
[THREAD] Started with mode B
[THREAD] Finished mode B
[THREAD] Finished mode B
[THREAD] Finished mode B
[THREAD] Finished mode B
[INFO] All Threads Executed Successfully... 
[RESULT] Expected: 4000000
[RESULT] Actual:   4000000
[INFO] Program Completed.
```
Part C
```shell
khachikz@ubuntu-aua-os:~/CS331/hw/hw10/task1$ ./a1 C
[INFO] Starting Program...
[INFO] Mode Selected: C
[INFO] Creating 4 threads 
[INFO] Initializing SPINLOCK...
[INFO] Creating threads...
[THREAD] Started with mode C
[INFO] Waiting for threads to complete...
[THREAD] Started with mode C
[THREAD] Started with mode C
[THREAD] Started with mode C
[THREAD] Finished mode C
[THREAD] Finished mode C
[THREAD] Finished mode C
[THREAD] Finished mode C
[INFO] All Threads Executed Successfully... 
[RESULT] Expected: 4000000
[RESULT] Actual:   4000000
[INFO] Program Completed.
```

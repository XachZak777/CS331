To run Task 2 use the following command:
```shell
gcc -lpthread assignment2.c -o bank_account
```
Then user can use the following commands for running with different approaches:
```shell
./bank_account mutex short   # Mutex + short CS
./bank_account spin short    # Spinlock + short CS
./bank_account mutex long    # Mutex + long CS
./bank_account spin long     # Spinlock + long CS
```
*Short Explanation*

Mutexes are ideal for long critical sections because threads waiting on a mutex sleep, freeing CPU resources.
Spinlocks are suitable for very short critical sections because the overhead of sleeping/waking is higher than busy waiting.
Using spinlocks for long critical sections causes CPU wastage as threads spin in a loop, reducing overall performance.
Both mutex and spinlock correctly protect the shared balance variable from race conditions, ensuring the final balance is always 0.

*Output*

Part 1: Mutex + short CS
```shell
khachikz@ubuntu-aua-os:~/CS331/hw/hw10/task2$ ./bank_account mutex short
[INFO] Starting Bank Simulation
[INFO] Lock: MUTEX | CS: SHORT
[INFO] Initializing mutex...
[INFO] Creating threads...
[THREAD] Deposit started
[THREAD] Deposit started
[THREAD] Deposit started
[THREAD] Deposit started
[INFO] Waiting for all threads to finish...
[THREAD] Withdraw started
[THREAD] Withdraw started
[THREAD] Withdraw started
[THREAD] Withdraw started
[THREAD] Deposit finished
[THREAD] Withdraw finished
[THREAD] Withdraw finished
[THREAD] Deposit finished
[THREAD] Withdraw finished
[THREAD] Deposit finished
[THREAD] Withdraw finished
[THREAD] Deposit finished
[INFO] All Threads Executed Successfully... 
[RESULT] Expected balance: 0
[RESULT] Actual balance:   0
[INFO] Bank Simulation Completed
```
Part 2: Spinlock + short CS
```shell
khachikz@ubuntu-aua-os:~/CS331/hw/hw10/task2$ ./bank_account spin short  
[INFO] Starting Bank Simulation
[INFO] Lock: SPINLOCK | CS: SHORT
[INFO] Initializing spinlock...
[INFO] Creating threads...
[THREAD] Deposit started
[INFO] Waiting for all threads to finish...
[THREAD] Deposit started
[THREAD] Deposit started
[THREAD] Deposit started
[THREAD] Withdraw started
[THREAD] Withdraw started
[THREAD] Withdraw started
[THREAD] Withdraw started
[THREAD] Deposit finished
[THREAD] Deposit finished
[THREAD] Withdraw finished
[THREAD] Deposit finished
[THREAD] Withdraw finished
[THREAD] Withdraw finished
[THREAD] Deposit finished
[THREAD] Withdraw finished
[INFO] All Threads Executed Successfully... 
[RESULT] Expected balance: 0
[RESULT] Actual balance:   0
[INFO] Bank Simulation Completed
```
Part 3: Mutex + long CS
```shell
khachikz@ubuntu-aua-os:~/CS331/hw/hw10/task2$ ./bank_account mutex long
[INFO] Starting Bank Simulation
[INFO] Lock: MUTEX | CS: LONG
[INFO] Initializing mutex...
[INFO] Creating threads...
[THREAD] Deposit started
[THREAD] Deposit started
[THREAD] Deposit started
[THREAD] Deposit started
[THREAD] Withdraw started
[INFO] Waiting for all threads to finish...
[THREAD] Withdraw started
[THREAD] Withdraw started
[THREAD] Withdraw started
[THREAD] Deposit finished
[THREAD] Withdraw finished
[THREAD] Withdraw finished
[THREAD] Withdraw finished
[THREAD] Deposit finished
[THREAD] Withdraw finished
[THREAD] Deposit finished
[THREAD] Deposit finished
[INFO] All Threads Executed Successfully... 
[RESULT] Expected balance: 0
[RESULT] Actual balance:   0
[INFO] Bank Simulation Completed
```
Part 4: Spinlock + long CS
```shell
khachikz@ubuntu-aua-os:~/CS331/hw/hw10/task2$ ./bank_account spin long
[INFO] Starting Bank Simulation
[INFO] Lock: SPINLOCK | CS: LONG
[INFO] Initializing spinlock...
[INFO] Creating threads...
[THREAD] Deposit started
[THREAD] Deposit started
[INFO] Waiting for all threads to finish...
[THREAD] Deposit started
[THREAD] Withdraw started
[THREAD] Deposit started
[THREAD] Withdraw started
[THREAD] Withdraw started
[THREAD] Withdraw started
[THREAD] Deposit finished
[THREAD] Withdraw finished
[THREAD] Deposit finished
[THREAD] Withdraw finished
[THREAD] Withdraw finished
[THREAD] Deposit finished
[THREAD] Deposit finished
[THREAD] Withdraw finished
[INFO] All Threads Executed Successfully... 
[RESULT] Expected balance: 0
[RESULT] Actual balance:   0
[INFO] Bank Simulation Completed
```

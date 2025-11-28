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

To run Task 5 use the following command:

```shell
gcc -lpthread assignment5.c -o task5 && ./task5
```
*Short Explanation*

A counting semaphore ensures that no more than K threads enter the printing section at the same time.
If the semaphore is initialized to 1, it behaves like a mutex, which means that only one printer, so jobs run one at a time.
If it is initialized to a value greater than the real number of printers, too many threads enter the printing section simultaneously, violating resource limits.

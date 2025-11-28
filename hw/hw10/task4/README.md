To run Task 4 use the following command:

```shell
gcc -lpthread assignment4.c -o task4 && ./task4
```
*Short Explanation*

`sleep()` cannot reliably enforce ordering because thread scheduling is controlled by the OS and is not deterministic.
Semaphores enforce strict ordering by blocking threads until the required event occurs, ensuring deterministic A -> B -> C execution.

*Output*

```shell
khachikz@ubuntu-aua-os:~/CS331/hw/hw10/task4$ gcc assignment4.c -o a4 && ./a4
[INFO] Starting Ordered Printing Program...
[INFO] Creating Threads A, B, C... 
[INFO] Waiting for threads to finish...
[THREAD A] A 0
[THREAD B] B 0
[THREAD C] C 0
[THREAD A] A 1
[THREAD B] B 1
[THREAD C] C 1
[THREAD A] A 2
[THREAD B] B 2
[THREAD C] C 2
[THREAD A] A 3
[THREAD B] B 3
[THREAD C] C 3
[THREAD A] A 4
[THREAD B] B 4
[THREAD C] C 4
[INFO] All threads completed successfully...
[INFO] Program Completed.
```

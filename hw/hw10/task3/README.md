To run Task 3 use the following command:

```shell
gcc -lpthread assignment3.c -o task3 && ./task3
```
*Short Explanation*

Semaphores alone manage resource availability (buffer slots) but do not protect simultaneous access to shared data structures. The mutex prevents multiple threads from corrupting the buffer or counters during concurrent updates.

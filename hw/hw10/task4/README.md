To run Task 4 use the following command:

```shell
gcc -lpthread assignment4.c -o task4 && ./task4
```
*Short Explanation*

sleep() cannot reliably enforce ordering because thread scheduling is controlled by the OS and is not deterministic.
Semaphores enforce strict ordering by blocking threads until the required event occurs, ensuring deterministic A → B → C execution.

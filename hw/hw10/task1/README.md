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

Version A can give the wrong result because counter++ is not atomic. Two threads can read-modify-write simultaneously and overwrite updates (race condition). Versions B and C lock access to the shared variable using mutex or spinlock, ensuring only one thread updates counter at a time and preventing lost updates.

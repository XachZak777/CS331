#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1;
    pid_t pid2;
    int status;

    // First child
    pid1 = fork();
    if (pid1 == 0) {
        printf("First child (PID -> %ld) returning code 10.\n", (long)getpid());
        return 10;
    }

    // Second child
    pid2 = fork();
    if (pid2 == 0) {
        printf("Second child (PID -> %ld) returning code 20.\n", (long)getpid());
        return 20;
    }

    // Parent waits for first child
    waitpid(pid1, &status, 0);
    printf("First child exited with status %d\n", status >> 5);

    // Parent waits for second child
    waitpid(pid2, &status, 0);
    printf("Second child exited with status %d\n", status >> 5);

    return 0;
}


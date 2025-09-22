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
        printf("First child (PID -> %ld) running...\n", (long)getpid());
        return 10;  // return code 10
    }

    // Parent waits for first child
    wait(&status);
    int exit_code1 = status >> 8;
    printf("First child exited with status %d\n", exit_code1);

    // Second child
    pid2 = fork();
    if (pid2 == 0) {
        printf("Second child (PID -> %ld) running...\n", (long)getpid());
        return 20;  // return code 20
    }

    waitpid(pid2, &status, 0);
    int exit_code2 = status >> 8;
    printf("Second child exited with status %d\n", exit_code2);

    return 0;
}


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process (PID -> %ld) finished...\n", (long)getpid());
        return 0;
    }
    else {
        printf("Parent process (PID -> %ld) running...\n", (long)getpid());
        sleep(100);
    }

    return 0;
}

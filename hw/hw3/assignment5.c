#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process (PID -> %ld) finished.\n", (long)getpid());
        return 0;
    }
    else {
        // Parent process
        printf("Parent process (PID -> %ld) runnin.\n", (long)getpid());

        // wait(NULL);

        sleep(10);  // observe zombie before parent exits
    }

    return 0;
}


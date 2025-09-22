#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("Process started: PID=%d, PPID=%d\n", getpid(), getppid());

    fork(); 
    fork();
    fork();

    printf("Process: PID=%d, PPID=%d\n", getpid(), getppid());
    return 0;
}

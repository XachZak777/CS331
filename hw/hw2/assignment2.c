#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t pid1 = fork();

    if (pid1 == 0) {
        execl("/bin/ls", "ls", NULL);
    }
    waitpid(pid1, NULL, 0);

    pid_t pid2 = fork();

    if (pid2 == 0) {
        execl("/bin/date", "date", NULL);
    }
    waitpid(pid2, NULL, 0);

    printf("Parent Process Done\n");
    return 0;
}

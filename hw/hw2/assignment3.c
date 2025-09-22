#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        execl("/bin/echo", "echo", "Barlus from Artashat", NULL);
    } else {
        wait(NULL);
        printf("Parent Process Done\n");
    }
    return 0;
}

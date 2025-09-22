#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        execl("/bin/ls", "ls", NULL);
    } else  {
        wait(NULL);
	printf("Parent Process Done\n");
    }
    return 0;
}

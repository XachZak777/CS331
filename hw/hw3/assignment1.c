#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();
	
	if (pid == 0) {
		printf("Child Process: PID -> %ld\n", (long)getpid());
	} else if (pid > 0) {
		printf("Parent Process: PID -> %ld\n", (long)getpid());
	}

	return 0;
}

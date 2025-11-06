#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    
    printf("[INFO] Starting Program... \n");
    const char *filename = "log.txt";

    printf("[INFO] Opening File in Append Mode... \n");
    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("[ERROR] Open Command Execution Failed");
        return 1;
    }
    char input[256];

    printf("[INPUT] Input log message: ");
    fflush(stdout);

    ssize_t len = read(STDIN_FILENO, input, sizeof(input) - 1);
    if (len <= 0) {
        perror("[ERROR] Read Command Execution Failed");
        close(fd);
        return 1;
    }
    input[len] = '\0';
    if (input[len - 1] == '\n') input[len - 1] = '\0';

    printf("[INFO] Writing Log Message to the File... \n");
    char logline[512];
    snprintf(logline, sizeof(logline), "PID=%d: %s\n", getpid(), input);

    if (write(fd, logline, strlen(logline)) < 0) {
        perror("[ERROR] Write Command Execution Failed");
        close(fd);
        return 1;
    }

    printf("[INFO] Getting The Offset... \n");
    off_t pos = lseek(fd, 0, SEEK_CUR);
    printf("[TASK] Current File Offset: %ld\n", (long)pos);



    printf("[INFO] Completing Program... \n");
    close(fd);
    return 0;
}

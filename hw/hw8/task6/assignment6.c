#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("[INFO] Starting Program...  \n");

    const char *filename = "numbers.txt";
    int fd;

    printf("[INFO] Creating and Opening the File... \n");
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("[ERROR] Open Command Execution Failed");
        return 1;
    }

    printf("[INFO] Writing numbers 1 to 10 into %s ... \n", filename);
    char buffer[8];
    for (int i = 1; i <= 10; i++) {
        snprintf(buffer, sizeof(buffer), "%d\n", i);
        if (write(fd, buffer, strlen(buffer)) < 0) {
            perror("[ERROR] Write Command Execution Failed");
            close(fd);
            return 1;
        }
    }
    close(fd);

    printf("[INFO] Reopening the File for Read/Write... \n");
    fd = open(filename, O_RDWR);
    if (fd < 0) {
        perror("[ERROR] Open Command Execution Failed");
        return 1;
    }

    char content[2048];
    ssize_t len = read(fd, content, sizeof(content) - 1);
    
    if (len < 0) {
        perror("[ERROR] Read Command Execution Failed");
        close(fd);
        return 1;
    }
    content[len] = '\0';

    printf("[INFO] Splitting content into lines...\n");
    char *lines[128];
    int line_count = 0;
    char *ptr = strtok(content, "\n");
    while (ptr != NULL && line_count < 128) {
        lines[line_count++] = ptr;
        ptr = strtok(NULL, "\n");
    }

    int target_line = 4;

    printf("[INFO] Replacing line %d with '100'...\n", target_line);
    if (target_line > 0 && target_line <= line_count) {
        lines[target_line - 1] = "100";
    } else {
        printf("[WARN] Line %d does not exist in file.\n", target_line);
    }

    printf("[INFO] Truncating and rewriting the file...\n");
    if (ftruncate(fd, 0) < 0) {
        perror("[ERROR] ftruncate Command Execution Failed");
        close(fd);
        return 1;
    }
    lseek(fd, 0, SEEK_SET);

    for (int i = 0; i < line_count; i++) {
        dprintf(fd, "%s\n", lines[i]);
    }

    close(fd);

    printf("[INFO] Verifying the final content of %s:\n", filename);
    fd = open(filename, O_RDONLY);

    if (fd < 0) {
        perror("[ERROR] Open Command Execution Failed");
        return 1;
    }

    char outbuf[256];
    ssize_t n;
    while ((n = read(fd, outbuf, sizeof(outbuf))) > 0) {
        write(STDOUT_FILENO, outbuf, n);
    }
    printf("\n");

    printf("[INFO] Completing Program...  \n");
    close(fd);
    return 0;
}


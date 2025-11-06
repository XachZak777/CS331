#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main() {

    printf("[INFO] Starting Program... \n");
    
    char src[256];
    char dest[256];

    printf("[INPUT] Input Source File Path: ");
    scanf("%255s", src);
    printf("[INFO] Source File Detected... \n");

    printf("[INPUT] Input Destination File Path: ");
    scanf("%255s", dest);
    printf("[INFO] Destination File Detected... \n");

    printf("[INFO] Opening Source File... \n");
    int fd_src = open(src, O_RDONLY);
    
    if (fd_src < 0) {
        perror("[ERROR] Open Command Execution Failed");
        return 1;
    }

    printf("[INFO] Opening Destination File... \n");
    int fd_dest = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    if (fd_dest < 0) {
        perror("[ERROR] Open Command Execution Failed");
        close(fd_src);
        return 1;
    }

    char buffer[BUF_SIZE];
    ssize_t bytes_read;
    ssize_t bytes_written;
    ssize_t total = 0;
    
    printf("[INFO] Performing Data Transfer and Byte Count... \n");
    while ((bytes_read = read(fd_src, buffer, BUF_SIZE)) > 0) {
        bytes_written = write(fd_dest, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("[ERROR] Write Command Execution Failed");
            close(fd_src);
            close(fd_dest);
            return 1;
        }
        total += bytes_written;
    }

    if (bytes_read < 0)
        perror("[ERROR] Read Command Execution Failed");
    else
        printf("[TASK] Total bytes copied: %ld\n", total);

    printf("[INFO] Completing Program... \n");

    close(fd_src);
    close(fd_dest);
    
    return 0;
}


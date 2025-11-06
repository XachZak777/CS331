#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    
    printf("[INFO] Starting Program... \n");

    printf("[INFO] Creating File and Writing Data to it... \n");

    const char *filename = "data.txt";
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    if (fd < 0) { 
	    perror("[ERROR] Open Command Execution Failed"); 
	    return 1; 
    }
    
    write(fd, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26);
    close(fd);

    fd = open(filename, O_RDWR);
    
    if (fd < 0) { 
	    perror("[ERROR] Open Command Execution Failed"); 
	    return 1; 
    }


    off_t size = lseek(fd, 0, SEEK_END);
    printf("[TASK] Original size: %ld bytes\n", size);

    printf("[INFO] Truncating File... \n");

    if (ftruncate(fd, 10) < 0) { 
	    perror("[ERROR] ftruncate Command Execution Failed"); 
	    close(fd); return 1; 
    }

    size = lseek(fd, 0, SEEK_END);
    printf("[TASK] Truncated Size: %ld bytes\n", size);

    lseek(fd, 0, SEEK_SET);
    char buffer[64] = {0};
    read(fd, buffer, sizeof(buffer)-1);
    
    printf("[TASK] Remaining Content: %s\n", buffer);
    
    printf("[INFO] Completing Program... \n");

    close(fd);
    
    return 0;
}


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    
    printf("[INFO] Starting Program... \n");

    const char *filename = "sparse.bin";
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    printf("[INFO] Opening the File... \n");
    if (fd < 0) { 
	    perror("[ERROR] Open Command Execution Failed"); 
	    return 1; 
    }


    printf("[INFO] Writing 'START' to File... \n");
    write(fd, "START", 5);

    printf("[INFO] Adding Skip for 1MiB... \n");
    lseek(fd, 1024*1024, SEEK_CUR);

    printf("[INFO] Writing 'END' to File... \n");
    write(fd, "END", 3);
    
    close(fd);

    printf("[INFO] Opening File in readonly... \n");
    fd = open(filename, O_RDONLY);
    off_t size = lseek(fd, 0, SEEK_END);
    printf("[TASK] Apparent file size: %ld bytes\n", size);
    // Disk usage is smaller because holes (unwritten gaps) are not stored.
    printf("[INFO] Completing Program... \n");
    close(fd);
    return 0;
}

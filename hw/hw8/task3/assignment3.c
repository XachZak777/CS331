#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    
    printf("[INFO] Starting Program... \n");

    char path[256];
    printf("Input Source File Path: ");
    scanf("%255s", path);
    int fd = open(path, O_RDONLY);
    
    if (fd < 0) { 
	    perror("[ERROR] Open Command Execution Failed"); 
	    return 1; 
    }
    
    printf("[INFO] File Opened With No Issues... \n");

    off_t size = lseek(fd, 0, SEEK_END);
    
    if (size == 0) { 
	    printf("\n"); 
	    close(fd); 
	    return 0; 
    }

    char ch;

    printf("[INFO] Reversing Data Inside the file... \n");

    for (off_t i = size - 1; i >= 0; i--) {
	lseek(fd, i, SEEK_SET);
        
	if (read(fd, &ch, 1) != 1) { 
		break; 
	}
        
	write(STDOUT_FILENO, &ch, 1);
    }
    printf("\n");
    printf("[INFO] Completing Program... \n");

    write(STDOUT_FILENO, "\n", 1);
    close(fd);
    
    return 0;
}

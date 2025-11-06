#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF 512

int main() {
    printf("[INFO] Starting Program...  \n");

    char f1[256], f2[256];
    printf("[INPUT] Input First File Path: ");
    scanf("%255s", f1);
    printf("[INPUT] Input Second File Path: ");
    scanf("%255s", f2);

    printf("[INFO] Opening files for comparison... \n");
    int fd1 = open(f1, O_RDONLY);
    int fd2 = open(f2, O_RDONLY);
    if (fd1 < 0 || fd2 < 0) {
        perror("[ERROR] Open Command Execution Failed");
        if (fd1 >= 0) {
            close(fd1);
        }
        if (fd2 >= 0) {
            close(fd2);
        }
        return 1;
    }

    unsigned char buf1[BUF];
    unsigned char buf2[BUF];
    ssize_t r1;
    ssize_t r2;
    off_t total = 0;

    printf("[INFO] Beginning byte-by-byte comparison... \n");

    while (1) {
        r1 = read(fd1, buf1, BUF);
        r2 = read(fd2, buf2, BUF);

        if (r1 < 0 || r2 < 0) {
            perror("[ERROR] Read Command Execution Failed");
            close(fd1);
            close(fd2);
            return 1;
        }
        ssize_t min = (r1 < r2) ? r1 : r2;
        for (ssize_t i = 0; i < min; i++) {
            if (buf1[i] != buf2[i]) {
                printf("[TASK] Files differ at byte %ld\n", total + i);
                close(fd1);
                close(fd2);
                return 1;
            }
        }

        if (r1 != r2) {
            printf("[TASK] Files differ at byte %ld (EOF of shorter file)\n", total + min);
            close(fd1);
            close(fd2);
            return 1;
        }

        if (r1 == 0 && r2 == 0) {
            break;
        }
        total += r1;
    }

    printf("[TASK] Files are identical\n");
    close(fd1);
    close(fd2);
    printf("[INFO] Completing Program... \n");
    return 0;
}


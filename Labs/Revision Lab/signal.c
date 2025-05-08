#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int fd;
#define filename "Temp.txt"

// Correct signal handler signature
void Signal_Handler(int signum) {
    close(fd);
    printf("\nCaught SIGINT. Closing and Deleting file...\n");
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("Error deleting the file");
    }
    exit(0); 
}

int main() {
    struct sigaction sa;
    sa.sa_handler = Signal_Handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error initializing signal handler");
        return -1;
    }

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("File open failed");
        return -1;
    }

    printf("Writing to '%s'. Press Ctrl+C to stop and delete.\n", filename);

    while (1) {
        if (write(fd, "Hello\n", 6) == -1) {
            perror("Write error");
            break;
        }
        sleep(1);
    }

    close(fd);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_FILE "/tmp/myfifo"

int main() {
    int fd;
    char buffer[BUFSIZ];
    ssize_t num_bytes;

    mkfifo(FIFO_FILE, 0666); // Create the named pipe (FIFO)

    fd = open(FIFO_FILE, O_RDONLY); // Open the named pipe for writing (consumer)

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) { // Consumer loop
        printf("Consumer read messaged: %s",buffer);
	num_bytes = read(fd, buffer, BUFSIZ);
	
        if (num_bytes == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        if (strncmp(buffer, "exit", 4) == 0) { // Check for exit 			condition
            break;
        }
    }

    close(fd); // Close the named pipe
    unlink(FIFO_FILE); // Remove the named pipe from the file system

    return 0;
}

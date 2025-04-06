#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"

int main() {
    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    char buffer[100];

    int fd_write = open(FIFO1, O_WRONLY);
    int fd_read  = open(FIFO2, O_RDONLY);

    printf("Process A started (write to FIFO1, read from FIFO2)\n");

    while (1) {
        printf("You: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        write(fd_write, buffer, strlen(buffer) + 1);

        if (strncmp(buffer, "exit", 4) == 0)
            break;

        ssize_t bytes = read(fd_read, buffer, sizeof(buffer));
        buffer[bytes] = '\0';

        if (strncmp(buffer, "exit", 4) == 0) {
            printf("Other side ended the chat.\n");
            break;
        }

        printf("Other: %s\n", buffer);
    }

    close(fd_write);
    close(fd_read);
    unlink(FIFO1);
    unlink(FIFO2);
    return 0;
}

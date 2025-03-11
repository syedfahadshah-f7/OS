#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int fd;
    int byte_read;
    int pid;
    char wmes[] = "I am now writing in an empty file. I am done with my work";
    char rmes[500];

    pid = fork();
    if (pid < 0) {
        printf("Error in creating Child \n");
    } else if (pid == 0) { // Child Process
        printf("Reading from input file\n");
        fd = open("inputfile.txt", O_RDONLY);
        if (fd < 0) {
            printf("Error opening file for reading\n");
            exit(1);
        }
        byte_read = read(fd, rmes, sizeof(rmes) - 1);
        if (byte_read > 0) {
            rmes[byte_read] = '\0'; // Null-terminate the string
            printf("Child Read: %s\n", rmes);
        }
        close(fd);
    } else { // Parent Process
        wait(NULL);  
        printf("Writing in input file\n");
        fd = open("inputfile.txt", O_CREAT | O_WRONLY, 0666);
        if (fd < 0) {
            printf("Error opening file for writing\n");
            exit(1);
        }
        write(fd, wmes, sizeof(wmes));
        close(fd);
    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();  // Create a new process

    if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) replacing program...\n", getpid());
       
        // Replacing the current program with the 'ls' command
        execlp("ls", "-l", NULL);
       
        // If exec() fails
        printf("Exec failed!\n");
        exit(1);
    }
    else {
        // Parent process
        wait(NULL);
        printf("Parent process (PID: %d)\n", getpid());
    }

    return 0;
}



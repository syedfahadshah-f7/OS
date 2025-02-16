#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    
    printf("Parent Process Id %d\n", getpid());
    pid1 = fork(); 

    if (pid1 == 0) {
        // First child process prints its PID
        printf("Child process 1 running (PID: %d)\n", getpid());
        printf("Child process 1 terminating...\n");
        exit(0);
    } 
    
    pid2 = fork();  

    if (pid2 == 0) {
        // Second child process prints its PID
        printf("Child process 2 running (PPID: %d)\n", getpid());
        printf("Child process 2 terminating...\n");
        exit(0);
    }

    
    printf("Parent process waiting for child processes to terminate...\n");

    wait(NULL);  // Wait for one child to finish
    wait(NULL);  // Wait for the second child

    printf("All child processes finished. Parent terminating.\n");
    return 0;
}


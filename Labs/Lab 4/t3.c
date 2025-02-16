#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
void printUserID() {
    printf("User ID : %d\n", getuid());
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed. Process ID: %d\n", getpid());
    } 
    else if (pid == 0) { 
        printf("Child Process ID: %d\n", getpid());
        printf("Parent Process ID calling from Child Process: %d\n", getppid());
        printf("Printing User Id from Child Process");
        printUserID();
        exit(0);
    } 
    else { 
        wait(NULL);  // Wait for the child to complete
        printf("Parent Process ID: %d\n", getpid());
        printUserID();
    }

    return 0;
}


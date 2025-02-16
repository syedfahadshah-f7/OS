#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed. Process ID: %d\n", getpid());
        return 1;
    } 
    else if (pid == 0) { 
        printf("Child Process ID: %d\n", getpid());
    
        if (execlp("ls", "ls", NULL) == -1) {
            perror("execlp failed");
            exit(1);
        }
    } 
    else { 
        wait(NULL);  
        printf("Parent Process ID: %d\n", getpid());
    }

    return 0;
}

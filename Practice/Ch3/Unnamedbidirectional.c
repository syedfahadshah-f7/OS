#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h> 

#define rend 0
#define wend 1

int main(){
    pid_t pid;
    int fd1[2];
    int fd2[2];
   
    if(pipe(fd1) != 0 || pipe(fd2) != 0 ){
        printf("Error in creating pipes\n");
        return 1;
    }

    pid = fork();

    if(pid<0){
        printf("Error in creating child");
    } else if (pid == 0){
        char num[3];
        close(fd1[wend]);                  // Close write end of pipe1 in child
        read(fd1[rend], num, sizeof(num)); // Read from read end of pipe1
        close(fd1[rend]);

        int n = atoi(num);
        n *= 2;
        sprintf(num, "%d", n);

        int pid2 = fork();
        if(pid2 == 0){
            close(fd2[rend]);                  // Close read end of pipe2 in grandchild
            write(fd2[wend], num, strlen(num)+1); // Write updated number to pipe2
            close(fd2[wend]);
        }
        wait(NULL);
    } else {
        char num[3] = "15";
        close(fd1[rend]);                     // Close read end of pipe1 in parent
        write(fd1[wend], num, strlen(num)+1); // Send initial number to child
        close(fd1[wend]);

        wait(NULL);

        close(fd2[wend]);                     // Close write end of pipe2 in parent
        read(fd2[rend], num, sizeof(num));    // Read result from grandchild
        close(fd2[rend]);

        printf("Final: %s\n", num);
    }

    return 0;
}



#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define rend 0
#define wend 1
int main(){
    pid_t pid;
    int fd[2];
    char *w = "Hello ";
    char r[100];

    if(pipe(fd) != 0){
        printf("Error in creating pipe\n");
        return 1;
    }
    pid = fork();
    if(pid<0){
        printf("Error in creating child");
    }else if (pid == 0){
        close(fd[rend]);
        write(fd[wend],w,strlen(w)+1);
        close(fd[wend]);
    }
    close(fd[wend]);
    wait(NULL);
    read(fd[rend],r,100);
    close(fd[rend]);
    printf("Printing After reading: %s", r);
    return 0;
}



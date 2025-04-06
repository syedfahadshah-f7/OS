#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#define fifofile "/tmp/myfifo"

int main(){
    mkfifo(fifofile,0666);
    char buffer[100];
    int fd = open(fifofile,O_WRONLY);
    if(fd == -1){
        printf("File not open error\n");
    }
    printf("Writting Messages in pipe,  write exit for termination\n");
    while (1)
    {   
        fgets(buffer,100,stdin);
        ssize_t bytes = write(fd, buffer,100);
        if(bytes == -1)
            printf("Error writting in file\n");
        if(strncmp(buffer,"exit",4) == 0)
            break;
    }
    close(fd);
    unlink(fifofile);
    return 0;
}
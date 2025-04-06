#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#define fifofile "/tmp/myfifo"

int main(){
    char buffer[100];
    int fd = open(fifofile,O_RDONLY);
    if(fd == -1)
        printf("File not open error\n");
    printf("Reading Messages from pipe\n");
    while (1)
    {   

        ssize_t bytes = read(fd,buffer,100);
        if(bytes == -1)
            printf("Error reading ifrom file\n");
        if(strncmp(buffer,"exit",4) == 0){
            printf("Producer Exit The Chat\n");
            break;
        }
        printf("Producer: %s \n", buffer);
    }
    close(fd);
    return 0;
}
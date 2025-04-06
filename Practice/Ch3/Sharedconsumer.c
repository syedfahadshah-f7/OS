#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#define size 4000

int main(){
    char name[] = "Shaka";
    char *ptr;
    int fd = shm_open(name,O_CREAT |O_RDWR,0666);
    if(fd == -1)
        printf("Error in Creating Shared Object\n");
    ptr = (char *)mmap(0,size,PROT_READ |PROT_WRITE,MAP_SHARED,fd,0);
    if (ptr == MAP_FAILED)
        printf("Failed to create map\n");
    printf("Printing data from Shared memory: %s", ptr);
    if (shm_unlink(name) == -1)
        printf("Failed to unlink ");
    return 0;
}
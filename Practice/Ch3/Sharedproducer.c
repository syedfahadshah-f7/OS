#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/mman.h>
#define size 4000

int main(){
    char name[] = "Shaka";
    int fd;
    char m1[] = "Hello World";
    char *ptr;
    fd = shm_open(name,O_CREAT | O_RDWR,0666);
    if(fd == -1)
        printf("Failed to create Shared obejct \n" );
    if(ftruncate(fd,size) == -1)
        printf("Error in increasing object size \n ");

    ptr = (char *) mmap(0,size,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
    if(ptr == MAP_FAILED)
        printf("Unable to Create Map\n");
    sprintf(ptr,"%s",m1);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
  pid_t pid = fork();
  
  if(pid <0){
    printf("Child Process Failed ID: %d",getpid());
  }
  else if(pid == 0){
    printf("Child Process is running Id: %d\n", getpid());
    
    for(int i=0;i<100;i++){
      printf("I am in Child Process\n");
    }
    exit(0);
  }else{
    wait(NULL);
    printf("Parent Process is running Id: %d\n", getpid());
    
    for(int i=0;i<100;i++){
      printf("I am in Parent Process\n");
    }
  }

return 0;
}

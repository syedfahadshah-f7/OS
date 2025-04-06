 #include<stdio.h>
 #include<pthread.h>
 #include<stdlib.h>
    int main(int argc, char *argv[]) {
        pid_t pid1;
        pid1 = fork();  
        if (pid1 == 0) {  
            printf("Pid1: %d\n", getpid());
    
            int pid2 = fork();  
            if (pid2 == 0) {
                printf("Pid2: %d\n", getpid());
            }
        }
    
        int pid3 = fork();  
        if (pid3 == 0) {
            printf("Pid3: %d\n", getpid());
        }
    
        return 0;
    }
    
 

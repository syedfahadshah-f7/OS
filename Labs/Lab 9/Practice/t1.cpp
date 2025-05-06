#include<iostream>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
using namespace std;

void Signal_handler(int signum){
    cout<<"Signal Generated with Id: "<<signum<<endl;
    exit(0);
}

int main(){
    if(signal(SIGINT,Signal_handler) == SIG_ERR){
        perror("Signal Not successfully initialized");
        exit(EXIT_FAILURE);
    }
    cout<<"Press Ctrl+ Cto terminate infinte Loop"<<endl;
    while(true);
    return 0;
}
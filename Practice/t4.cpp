#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
using namespace std;

void Signal_handler(int signum){
    cout<<"Signal Generated with Id: "<<signum<<endl;
    kill(getpid(),SIGUSR1);
    kill(getpid(),SIGUSR2);
    sleep(2);
    exit(0);
}

void siguser1_handler(int signum) {
    printf("Received SIGUSER1 signal\n");
}

void siguser2_handler(int signum) {
    printf("Received SIGUSER2 signal\n");
}

int main() {
    // Registering signal handlers
    signal(SIGUSR1, siguser1_handler);
    signal(SIGUSR2, siguser2_handler);
    signal(SIGINT, Signal_handler);

    printf("My PID is: %d\n", getpid());
    printf("Send SIGUSR1 or SIGUSR2 to this process to trigger the signal handlers.\n");

    // Infinite loop to keep the program running
    while (1) {
        sleep(1);
    }

    return 0;
}
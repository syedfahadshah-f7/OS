#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler for the alarm signal
void handle_alarm(int sig) {
    printf("\nAlarm received. Program terminating.\n");
    exit(0);
}

int main() {
    // Register signal handler for SIGALRM
    signal(SIGALRM, handle_alarm);
    alarm(5);

    printf("Entering sleep loop...\n");

    while (1) {
        printf("Still running...\n");
        sleep(1);
    }

    return 0; 
}


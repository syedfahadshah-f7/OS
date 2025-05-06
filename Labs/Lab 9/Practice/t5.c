#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 4
pthread_t threads[NUM_THREADS];

void Signal_handler(int signum) {

    printf("Signal Id: %d\n",signum);
   exit(0);
}

void *runner(void *arg) {
    while (1) sleep(1);
    return NULL;
}

int main() {
    signal(SIGINT, Signal_handler); 

    for (int i = 0; i < NUM_THREADS; ++i) {
        if (pthread_create(&threads[i], NULL, runner, NULL) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

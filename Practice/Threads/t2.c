#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
void *printPrimesBelow(void * l) {
    int n =  *((int *) l);
    if (n <= 2) {
        printf("No prime numbers below %d.\n", n);
        
    }

    bool prime[n];
    for (int i = 0; i < n; i++)
        prime[i] = true;

    for (int p = 2; p * p < n; p++) {
        if (prime[p]) {
            for (int i = p * p; i < n; i += p)
                prime[i] = false;
        }
    }

    printf("Prime numbers below %d: ", n);
    for (int i = 2; i < n; i++) {
        if (prime[i])
            printf("%d ", i);
    }
    printf("\n");
}

int main(int argc, char *argv[]){
int n = atoi(argv[1]);
pthread_t id;
pthread_create(&id,NULL,printPrimesBelow, &n);
pthread_join(id,NULL);
return 0;
}

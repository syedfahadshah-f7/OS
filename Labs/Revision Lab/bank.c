#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

#define wor_t 3
#define cust 20
sem_t bank_tellers,mutex;
int amnts[cust] = {19,56,45,39,28,98,90,67,10,99,19,56,45,39,28,98,90,67,10,99};
int idx=0;
int shared_balance = 0;

void *Modify_Balance(void *arg){
    int id = *(int *)arg;
    while (1) {
        sem_wait(&bank_tellers);
        sem_wait(&mutex);
        
        if (idx >= cust) {
            sem_post(&mutex);
            sem_post(&bank_tellers);
            break;
        }
        
        shared_balance += amnts[idx];
        printf("Shared Amount: %d Add By {%d}\n", shared_balance, id);
        idx++;

        sem_post(&mutex);
        sem_post(&bank_tellers);
    }
    pthread_exit(NULL);
}



int main(){
    
    pthread_t wor_threads[wor_t];
    sem_init(&mutex,0,1);
    sem_init(&bank_tellers,0,3);
    int ids[wor_t];
    for(int i=0;i<wor_t;i++){
        ids[i] =i;
        pthread_create(&wor_threads[i],NULL,Modify_Balance,&ids[i]);
    }

    for(int i=0;i<wor_t;i++){
        pthread_join(wor_threads[i],NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&bank_tellers);
    return 0;
}
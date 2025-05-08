#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>

#define CHEFS 2
#define CUST 10

sem_t active_chefs;
pthread_mutex_t mutex;
int shared_order_data = 0;
int shared_chef_data = 0;

void *MakeDish(void *args) {
    int chef_id = *(int *)args;

    while (1) {
        sem_wait(&active_chefs);

        pthread_mutex_lock(&mutex);
        if (shared_chef_data >= CUST) {
            pthread_mutex_unlock(&mutex);
            break; // No more orders to make
        }

        shared_chef_data++;
        int order_no = shared_chef_data;
        pthread_mutex_unlock(&mutex);

        printf("Chef Number: %d Making Order Number: %d\n", chef_id, order_no);
    }

    pthread_exit(NULL);
}

void *OrderDish(void *args) {
    pthread_mutex_lock(&mutex);
    shared_order_data++;
    int order_no = shared_order_data;
    pthread_mutex_unlock(&mutex);

    printf("Ordering Order Number: %d\n", order_no);
    sem_post(&active_chefs);

    pthread_exit(NULL);
}

int main() {
    sem_init(&active_chefs, 0, 0); 
    pthread_mutex_init(&mutex, NULL);

    pthread_t chefs_thread[CHEFS];
    pthread_t cust_thread[CUST];
    int ids[CHEFS];

    for (int i = 0; i < CUST; i++) {
        pthread_create(&cust_thread[i], NULL, OrderDish, NULL);
    }

    for (int i = 0; i < CHEFS; i++) {
        ids[i] = i + 1;
        pthread_create(&chefs_thread[i], NULL, MakeDish, &ids[i]);
    }

    for (int i = 0; i < CUST; i++) {
        pthread_join(cust_thread[i], NULL);
    }

    for (int i = 0; i < CHEFS; i++) {
        sem_post(&active_chefs); // In case chefs are blocked after last order
    }

    for (int i = 0; i < CHEFS; i++) {
        pthread_join(chefs_thread[i], NULL);
    }

    sem_destroy(&active_chefs);
    pthread_mutex_destroy(&mutex);

    return 0;
}

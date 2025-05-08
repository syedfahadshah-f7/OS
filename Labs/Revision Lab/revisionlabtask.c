#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<stdlib.h>
#define n_threads 2
#define size 10
int global[size] =  {0};

    void generate_array(){
        for(int i=0;i<size;i++){
            global[i] = rand()%size;
        }
    }

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void *runner(void *arg){
    int id = *(int  *)arg;
    int start = id * (size/n_threads);
    int end = start + (size/n_threads);

    for(int i=start; i < end - 1; i++){
        for(int j=start; j < end - 1 - (i - start); j++){
            if(global[j] > global[j+1]){
                swap(&global[j], &global[j+1]);
            }
        }
    }
    pthread_exit(NULL);
}

int main(){
    generate_array();
    printf("Initial Array: ");
    for(int i=0; i<size;i++){
        printf("%d ",global[i]);
    }
    printf("\n");
    pthread_t threads[n_threads];
    int thread_id[n_threads];
    for(int i=0; i<n_threads;i++){
        thread_id[i] =i;
        pthread_create(&threads[i],NULL,runner,(void *)&thread_id[i]);
    }


    for(int i=0; i<n_threads;i++){
        pthread_join(threads[i],NULL);
    }
    int temp[size] = {0};
    int left=0,right = size/n_threads,idx=0;
    while(left < size/n_threads && right<size){
        if(global[left] < global[right]){
            temp[idx++] = global[left++];
        }
        else{
            temp[idx++] = global[right++];
        }
    }
    while(left < size/n_threads){
        temp[idx++] = global[left++];
    }
    while(right < size){
        temp[idx++] = global[right++];
    }
    for(int i=0; i<size;i++){
        global[i] = temp[i];
    }

    printf("After Apply Sort: ");
    for(int i=0; i<size;i++){
        printf("%d ",global[i]);
    }
    printf("\n");
    return 0;
}
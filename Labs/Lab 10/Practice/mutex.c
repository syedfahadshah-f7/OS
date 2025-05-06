#include<stdio.h>
#include<pthread.h>

int cnt =0;
pthread_mutex_t mutex;

void *runner(void *args){
    int t_id = (int) args;
    pthread_mutex_lock(&mutex);
    for(int i= t_id*5;i<t_id*5+5;i++){
        printf("Thread num: %d cnt = %d \n",t_id,cnt);
        cnt++;
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}
int main(){
    pthread_t threads[5];
    int t_args[5];
    pthread_mutex_init(&mutex,NULL);
    for(int i=0;i<5;++i){
        t_args[i] =i;
        pthread_create(&threads[i],NULL,runner,t_args[i]);
    }

    for(int i=0;i<5;++i){
        pthread_join(threads[i],NULL);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *MUL(void * n){
int i = *(int *)n;
for (int j=1; j<=10;j++){
printf("%d X %d = %d\n",i,j,i*j);
}
pthread_exit(NULL);
}

int main(int argc, char *argv[]){
pthread_t id1,id2,id3,id4;
int n1 = atoi(argv[1]), n2 = atoi(argv[2]),n3 = atoi(argv[3]),n4 = atoi(argv[4]);
pthread_create(&id1,NULL,MUL,&n1);
sleep(1);
pthread_create(&id2,NULL,MUL,&n2);
sleep(1);
pthread_create(&id3,NULL,MUL,&n3);
sleep(1);
pthread_create(&id4,NULL,MUL,&n4);

pthread_join(id1,NULL);
pthread_join(id2,NULL);
pthread_join(id3,NULL);
pthread_join(id4,NULL);
return 0;
}

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define tnums 10
#define size 1000000
int arr[size] ;
int brr[size] ;
int crr[size] ;

void GenerateRandomArrays(){
    for (int i=0;i<size;i++){
        arr[i] = rand() %1000;
        brr[i] = rand() % 1000;
        crr[i] = rand() % 1000;
    }
}

void PrintArray(){
    for (int i=0;i<100;i++){
        printf("%d ",crr[i]);
    }
    printf("\n");
}

void SerialCode(){
  for (int i=0;i<size;i++){
        crr[i] = arr[i] +brr[i];
    }
}

void *DoAssigneWork(void *arg){
  int id = *((int *)arg);
  int start = id * (size/tnums);
  int end = start + (size/tnums);
  
  for (int j = start;j<end;j++){
    crr[j] = arr[j] + brr[j];
  }
  pthread_exit(NULL);
}

int main(){
    GenerateRandomArrays();
    SerialCode(); //a)
    printf("Printing start 100 values of C calculated from Serial\n");
    PrintArray();

    pthread_t threads[tnums];
    int ids[tnums];  

    for (int i =0;i<tnums;i++){
        ids[i] = i;
        pthread_create(&threads[i],NULL,DoAssigneWork,(void *)&ids[i]); //b)
    }

    for (int i =0;i<tnums;i++){
        pthread_join(threads[i],NULL);
    }
    printf("Printing start 100 values of C calculated from Concurrency\n");
    PrintArray();
    pthread_exit(NULL);

    return 0;
}


#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/types.h>

using namespace std;

int main(){
int pid = fork();

if(pid == 0){
execlp("./t2","t2.c",NULL);
}else{
wait(NULL);
}
return 0;
}

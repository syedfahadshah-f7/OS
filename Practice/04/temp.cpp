#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;

int main(){
int pid = fork();

if(pid == 0){
//execlp("./t.sh","t.sh",NULL);
//execlp("./t2","t2.c",NULL);
//execlp("ls","ls",NULL);
}else{
wait(NULL);
}
return 0;
}

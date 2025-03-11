#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;

int main(){
  cout<<"10"<<"PID: "<<getpid()<<"ParentID: "<<getppid()<<endl;
  int pid = fork();
  if(pid == 0){
  cout<<"6"<<"PID: "<<getpid()<<"ParentID: "<<getppid()<<endl;
  int pid1 = fork();
  
  if(pid1 == 0){
  cout<<"4"<<"PID: "<<getpid()<<"ParentID: "<<getppid()<<endl;
  exit(0);
  }
  
  int pid2 = fork();
  if(pid2 == 0){
  cout<<"8"<<"PID: "<<getpid()<<"ParentID: "<<getppid()<<endl;
  exit(0);
  }
  wait(NULL);
  wait(NULL);
  exit(0);
  }else{
  int pid2 = fork();
  if(pid2 == 0){
  cout<<"18"<<"PID: "<<getpid()<<"ParentID: "<<getppid()<<endl;
  int pid3 = fork();
  
  if(pid3 == 0){
  cout<<"15"<<"PID: "<<getpid()<<"ParentID: "<<getppid()<<endl;
  exit(0);
  }
  
  int pid4 = fork();
  if(pid4 == 0){
  cout<<"21"<<"PID: "<<getpid()<<"ParentID: "<<getppid()<<endl;
  exit(0);
  }
  wait(NULL);
  wait(NULL);
  exit(0);
  }
  wait(NULL);
  wait(NULL);
  }
  
return 0;
}

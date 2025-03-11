#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<vector>
#include<sstream>
#include<algorithm>
#include<sys/wait.h>
using namespace std;

#define rd 0
#define wr 1

int main() {
    int fd2[2];
    int fd[2];
    vector<int> arr = {2, 4, 5, 6, 7, 1, 9};
    int pid;
    
    if (pipe(fd) == -1) {
        cout << "Error in creating Pipe 1" << endl;
        return 1;
    }
    if (pipe(fd2) == -1) {
        cout << "Error in creating Pipe 2" << endl;
        return 1;
    }
    pid = fork();
    
    if (pid < 0) {
        cout << "Error in creating Child" << endl;
        return 1;
    }
    
    if (pid == 0) { // Child process
        close(fd[wr]);
        char buffer[100];
        read(fd[rd], buffer, sizeof(buffer));
        close(fd[rd]);
        
        // Convert received string back to vector
        vector<int> brr;
        stringstream ss(buffer);
        int num, sum = 0;
        while (ss >> num) {
            brr.push_back(num);
        }
        sort(brr.begin(),brr.end());
        int median = brr[brr.size()/2];
        cout << "Child received array and calculated Median: " << median<< endl;
        string med = to_string(median);
        
        int pid = fork();
        if(pid<0){cout<<"Error in creating Chill 2"<<endl;}
        
        if(pid == 0){
        close(fd2[rd]);
        write(fd2[wr],med.c_str(),med.length()+1);
        close(fd2[wr]);
        cout<<"Done Writing Median in pipe "<<endl;
        exit(0);
        }
        wait(NULL);
        exit(0);
        
    } else { // Parent process
        close(fd[rd]);
        string msg;
        for (int num : arr) {
            msg += to_string(num) + " ";
        }
        write(fd[wr], msg.c_str(), msg.length() + 1);
        close(fd[wr]);
        wait(NULL);
        
        close(fd2[wr]);
        cout<<"Reading Median value and then calculating Factorial"<<endl;
        char med[10];
        int median;
        read(fd2[rd],med,sizeof(med));
        cout<<"Printing median from Parent:"<<med<<endl;
        stringstream ss(med);
        ss>>median;
        int factorial=1;
        while(median>0){
        factorial *= median;
        median--;
        }
        cout<<"Factorial: "<<factorial<<endl;
    }
    
    return 0;
}

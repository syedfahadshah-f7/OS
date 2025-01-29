#include<iostream>
#include<vector>
#include<cstdlib>  
using namespace std;

int main(int argc, char* argv[]) {
    if(argc<2){
      cout<<"Series having a single Value"<<endl;
      }
    vector<int> arr;
    for(int i = 1; i < argc; i++) {
        arr.push_back(atoi(argv[i]));
    }
    int d = arr[1]-arr[0];
    int temp = arr[0];
    for(int i = 1; i < arr.size(); i++) {
      temp += d;
        if(temp != arr[i]){
          cout<<"missing Value is:"<<temp<<endl;
          break;
        }
    }
    
    return 0;
}


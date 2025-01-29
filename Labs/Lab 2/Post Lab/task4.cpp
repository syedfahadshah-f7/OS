#include<iostream>
#include<vector>
#include<cstdlib>  
using namespace std;

int main(int argc, char* argv[]) {
    int sum = 0, avg = 0;
    for(int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);
    }
    
    if (argc > 1) {
        avg = sum / (argc - 1);  
    }
    cout << "Sum of Array: " << sum << endl;
    cout << "Average of Array: " << avg << endl;
    return 0;
}


#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main() {
    int pid;
    string wmes = "I am now writing in an empty file. I am done with my work";
    string rmes;

    pid = fork();
    if (pid < 0) {
        cerr << "Error in creating Child process\n";
    } else if (pid == 0) { // Child Process
        cout << "Reading from input file\n";
        ifstream inFile("inputfile.txt");
        if (!inFile) {
            cerr << "Error opening file for reading\n";
            exit(1);
        }
        while(getline(inFile, rmes)){
        cout << "Child Read: " << rmes << endl;
        }
        inFile.close();
    } else { // Parent Process
        wait(NULL); 
        cout << "Writing in input file\n";
        ofstream outFile("inputfile.txt");
        if (!outFile) {
            cerr << "Error opening file for writing\n";
            exit(1);
        }
        outFile << wmes;
        outFile.close();
    }
    return 0;
}


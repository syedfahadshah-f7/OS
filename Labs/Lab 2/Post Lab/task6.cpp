#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>  
#include <algorithm> 

using namespace std;

int findMissingElement(const vector<int>& arr) {

    int d = arr[1]-arr[0];
    int temp = arr[0];
    for(int i = 1; i < arr.size(); i++) {
      temp += d;
        if(temp != arr[i]){
          return temp;
        }
    }
    return -1; 
}

int main() {

    ifstream inputFile("temp.txt");
    if (!inputFile) {
        cout << "Error opening input file!" << endl;
        exit(1);
    }

    vector<int> series;
    int number;
    
    while (inputFile >> number) {
        series.push_back(number);
    }
    inputFile.close(); 

    if (series.size() < 2) {
        cerr << "The series is too short to find a missing element." << endl;
        exit(1);
    }

    
    sort(series.begin(), series.end());

    
    int missingElement = findMissingElement(series);
    if (missingElement == -1) {
        cerr << "Couldn't find a missing element in the series." << endl;
        exit(1);
    }

    // Open the output file
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cout << "Error opening output file!" << endl;
        exit(1);
    }

    outputFile << "The missing element in the series is: " << missingElement << endl;
    outputFile.close();  

    cout << "Missing element found: " << missingElement << endl;

    return 0;
}



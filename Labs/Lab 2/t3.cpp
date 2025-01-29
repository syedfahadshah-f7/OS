#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> 
using namespace std;
int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout<< "Usage: " << argv[0] << " <list of integers>" << endl;
        return 1;
    }

    vector<int> numbers;

  
    for (int i = 1; i < argc; i++) {
        numbers.push_back(atoi(argv[i]));
    }


    sort(numbers.begin(), numbers.end());

	cout << "Sorted integers: ";
    for (const int& num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

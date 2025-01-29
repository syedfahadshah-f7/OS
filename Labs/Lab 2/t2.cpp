#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char* argv[]) {

    if (argc != 2) {
        cout<< "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }


    ifstream file(argv[1]);

    if (!file) {
        cout<< "Error: File does not exist or could not be opened." << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();

    return 0;
}

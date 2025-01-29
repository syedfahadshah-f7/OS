#include "WordCount.h"
#include <fstream>
#include <sstream>

WordCount::WordCount() {}

int WordCount::countWords(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return -1;
    }
    
    int count = 0;
    std::string word;
    while (file >> word) {
        count++;
    }
    file.close();
    return count;
}

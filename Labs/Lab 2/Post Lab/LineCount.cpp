#include "LineCount.h"
#include <fstream>

LineCount::LineCount() {}

int LineCount::countLines(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return -1;
    }
    
    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        count++;
    }
    file.close();
    return count;
}

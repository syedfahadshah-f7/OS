#include "LetterCount.h"
#include <fstream>
#include <cctype>

LetterCount::LetterCount() {}

int LetterCount::countLetters(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return -1;
    }
    
    int count = 0;
    char ch;
    while (file.get(ch)) {
        if (std::isalpha(ch)) {
            count++;
        }
    }
    file.close();
    return count;
}

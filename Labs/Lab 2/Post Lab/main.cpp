#include <iostream>
#include "LetterCount.h"
#include "WordCount.h"
#include "LineCount.h"

int main() {
    std::string filename = "sample.txt";

    LetterCount letterCounter;
    WordCount wordCounter;
    LineCount lineCounter;

    std::cout << "Number of letters: " << letterCounter.countLetters(filename) << std::endl;
    std::cout << "Number of words: " << wordCounter.countWords(filename) << std::endl;
    std::cout << "Number of lines: " << lineCounter.countLines(filename) << std::endl;

    return 0;
}

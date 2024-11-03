#include "zipfs.h"

int main() {
    std::string fileName = "moby_dick.txt";
    auto book = Session17::readBook(fileName);
    
    auto wordFrequency = Session17::computeWordFrequency(book);
    int uniqueWordCount = Session17::countUniqueWords(book);
    
    auto sortedFrequencies = Session17::sortFrequencies(wordFrequency);
    Session17::outputFrequencies(sortedFrequencies, "output.txt");

    std::cout << "Unique word count: " << uniqueWordCount << std::endl;

    return 0;
}
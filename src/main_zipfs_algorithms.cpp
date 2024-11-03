#include "zipfs.h"

int main() {
    std::string fileName = "moby_dick.txt";
    auto book = Session19::readBook(fileName);
    
    auto wordFrequency = Session19::computeWordFrequency(book);
    int uniqueWordCount = Session19::countUniqueWords(book);
    
    auto sortedFrequencies = Session19::sortFrequencies(wordFrequency);
    Session19::outputFrequencies(sortedFrequencies, "output.txt");

    std::cout << "Unique word count: " << uniqueWordCount << std::endl;

    return 0;
}
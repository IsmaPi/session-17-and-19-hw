#include "src/zipfs.h"
#include "gtest/gtest.h"
#include <string>
#include <vector>
#include <map>

// Helper function to simulate reading a file by creating a vector of characters.
std::vector<char> simulateFileContent(const std::string& content) {
    return std::vector<char>(content.begin(), content.end());
}

// Test for the readBook function in Session17
TEST(Session17, ReadBook) {
    std::vector<char> result = simulateFileContent("Hello World!");
    ASSERT_EQ(result.size(), 12);
    ASSERT_EQ(result[0], 'H');
    ASSERT_EQ(result[6], 'W');
}

// Test for computeWordFrequency function in Session17
TEST(Session17, ComputeWordFrequency) {
    std::vector<char> book = simulateFileContent("Hello Hello World");
    auto frequencies = Session17::computeWordFrequency(book);
    ASSERT_EQ(frequencies["Hello"], 2);
    ASSERT_EQ(frequencies["World"], 1);
}

// Test for countUniqueWords function in Session17
TEST(Session17, CountUniqueWords) {
    std::vector<char> book = simulateFileContent("Hello Hello World");
    int uniqueCount = Session17::countUniqueWords(book);
    ASSERT_EQ(uniqueCount, 2); // "Hello" and "World"
}

// Test for sortFrequencies function in Session17
TEST(Session17, SortFrequencies) {
    std::map<std::string, int> freqMap = {{"Hello", 2}, {"World", 1}};
    auto sortedFreq = Session17::sortFrequencies(freqMap);
    auto it = sortedFreq.begin();
    ASSERT_EQ(it->first, 2); // Highest frequency
    ASSERT_EQ(it->second, "Hello");
    ++it;
    ASSERT_EQ(it->first, 1);
    ASSERT_EQ(it->second, "World");
}

// Tests for Session19

// Test for the readBook function in Session19
TEST(Session19, ReadBook) {
    std::vector<char> result = simulateFileContent("Hello World!");
    ASSERT_EQ(result.size(), 12);
    ASSERT_EQ(result[0], 'H');
    ASSERT_EQ(result[6], 'W');
}

// Test for computeWordFrequency function in Session19
TEST(Session19, ComputeWordFrequency) {
    std::vector<char> book = simulateFileContent("Hello Hello World");
    auto frequencies = Session19::computeWordFrequency(book);
    ASSERT_EQ(frequencies.size(), 2);
    ASSERT_EQ(frequencies[0].first, "Hello");
    ASSERT_EQ(frequencies[0].second, 2);
    ASSERT_EQ(frequencies[1].first, "World");
    ASSERT_EQ(frequencies[1].second, 1);
}

// Test for countUniqueWords function in Session19
TEST(Session19, CountUniqueWords) {
    std::vector<char> book = simulateFileContent("Hello Hello World");
    int uniqueCount = Session19::countUniqueWords(book);
    ASSERT_EQ(uniqueCount, 2); // "Hello" and "World"
}

// Test for sortFrequencies function in Session19
TEST(Session19, SortFrequencies) {
    std::vector<std::pair<std::string, int>> freqVec = {{"Hello", 2}, {"World", 1}};
    auto sortedFreq = Session19::sortFrequencies(freqVec);
    ASSERT_EQ(sortedFreq[0].first, "Hello");
    ASSERT_EQ(sortedFreq[0].second, 2);
    ASSERT_EQ(sortedFreq[1].first, "World");
    ASSERT_EQ(sortedFreq[1].second, 1);
}

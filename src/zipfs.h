#pragma once

#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <numeric>

/**
 * @brief Namespace for session 17 hw.
 */
namespace Session17 {

    /**
     * @brief Reads a file and extracts alphabetic characters.
     * @param fileName The name of the file to read.
     * @return A vector of alphabetic characters from the file.
     */
    std::vector<char> readBook(const std::string& fileName) {
        std::vector<char> characters;
        std::ifstream file(fileName);
        char ch;

        while (file.get(ch)) {
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                characters.push_back(ch);
            } else {
                characters.push_back(' ');
            }
        }

        file.close();
        return characters;
    }

    /**
     * @brief Computes the frequency of each word in the book.
     * @param book A vector of characters representing the book.
     * @return A map with words as keys and their frequencies as values.
     */
    std::map<std::string, int> computeWordFrequency(const std::vector<char>& book) {
        std::map<std::string, int> frequencies;
        std::string text(book.begin(), book.end());
        std::istringstream stream(text);
        std::string word;
        
        while (stream >> word) {
            ++frequencies[word];
        }

        return frequencies;
    }

    /**
     * @brief Counts the number of unique words in the book.
     * @param book A vector of characters representing the book.
     * @return The number of unique words in the book.
     */
    int countUniqueWords(const std::vector<char>& book) {
        std::set<std::string> uniqueWords;
        std::string text(book.begin(), book.end());
        std::istringstream stream(text);
        std::string word;

        while (stream >> word) {
            uniqueWords.insert(word);
        }

        return uniqueWords.size();
    }

    /**
     * @brief Sorts word frequencies in descending order.
     * @param frequencies A map of words and their frequencies.
     * @return A multimap of frequencies sorted in descending order.
     */
    std::multimap<int, std::string, std::greater<int>> sortFrequencies(const std::map<std::string, int>& frequencies) {
        std::multimap<int, std::string, std::greater<int>> sortedFrequencies;

        for (const auto& [word, freq] : frequencies) {
            sortedFrequencies.insert({freq, word});
        }

        return sortedFrequencies;
    }

    /**
     * @brief Outputs word frequencies to a file for plotting.
     * @param sortedFrequencies A multimap of sorted word frequencies.
     * @param fileName The name of the output file.
     */
    void outputFrequencies(const std::multimap<int, std::string, std::greater<int>>& sortedFrequencies, const std::string& fileName) {
        std::ofstream outFile(fileName);

        int rank = 1;
        for (const auto& [freq, word] : sortedFrequencies) {
            outFile << rank << " " << freq << " " << word << "\n";
            ++rank;
        }

        outFile.close();
    }
}

/**
 * @brief Namespace for session 19 hw, using algorithms and only vector as a container.
 */
namespace Session19 {

    /**
     * @brief Reads a file and extracts alphabetic characters.
     * @param fileName The name of the file to read.
     * @return A vector of alphabetic characters from the file.
     */
    std::vector<char> readBook(const std::string& fileName) {
        std::vector<char> characters;
        std::ifstream file(fileName);
        char ch;

        while (file.get(ch)) {
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                characters.push_back(ch);
            } else {
                characters.push_back(' ');
            }
        }

        file.close();
        return characters;
    }

    /**
     * @brief Computes the frequency of each word in the book.
     * @param book A vector of characters representing the book.
     * @return A vector of pairs with each unique word and its frequency.
     */
    std::vector<std::pair<std::string, int>> computeWordFrequency(const std::vector<char>& book) {
        std::vector<std::pair<std::string, int>> frequencies;
        std::string text(book.begin(), book.end());
        std::istringstream stream(text);
        std::string word;
        
        while (stream >> word) {
            auto it = std::find_if(frequencies.begin(), frequencies.end(), [&](const auto& pair) {
                return pair.first == word;
            });
            if (it != frequencies.end()) {
                it->second++;
            } else {
                frequencies.emplace_back(word, 1);
            }
        }

        return frequencies;
    }

    /**
     * @brief Counts the number of unique words in the book.
     * @param book A vector of characters representing the book.
     * @return The number of unique words in the book.
     */
    int countUniqueWords(const std::vector<char>& book) {
        std::vector<std::string> uniqueWords;
        std::string text(book.begin(), book.end());
        std::istringstream stream(text);
        std::string word;

        while (stream >> word) {
            if (std::find(uniqueWords.begin(), uniqueWords.end(), word) == uniqueWords.end()) {
                uniqueWords.push_back(word);
            }
        }

        return uniqueWords.size();
    }

    /**
     * @brief Sorts word frequencies in descending order.
     * @param frequencies A vector of pairs with each unique word and its frequency.
     * @return A sorted vector of pairs with frequencies in descending order.
     */
    std::vector<std::pair<std::string, int>> sortFrequencies(std::vector<std::pair<std::string, int>>& frequencies) {
        std::sort(frequencies.begin(), frequencies.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        return frequencies;
    }

    /**
     * @brief Outputs word frequencies to a file for plotting.
     * @param sortedFrequencies A sorted vector of pairs with word frequencies.
     * @param fileName The name of the output file.
     */
    void outputFrequencies(const std::vector<std::pair<std::string, int>>& sortedFrequencies, const std::string& fileName) {
        std::ofstream outFile(fileName);

        int rank = 1;
        for (const auto& [word, freq] : sortedFrequencies) {
            outFile << rank << " " << freq << " " << word << "\n";
            ++rank;
        }

        outFile.close();
    }
}
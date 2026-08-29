#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

void printFilteredWordFrequency(string feedback) {
    unordered_set<string> stopWords = {"the", "was", "and", "a", "is", "of", "in"};
    unordered_map<string, int> frequency;

    // Normalize: to lowercase and strip punctuation
    string cleanedText = "";
    for (char c : feedback) {
        if (c == '.' || c == ',') {
            cleanedText += " "; // Replace punctuation with space
        } else {
            cleanedText += tolower(c);
        }
    }

    // Split words by whitespace
    stringstream ss(cleanedText);
    string word;
    while (ss >> word) {
        // Skip if it's a stop word
        if (stopWords.find(word) == stopWords.end()) {
            frequency[word]++;
        }
    }

    // Move to vector for sorting
    vector<pair<string, int>> sortedFreq(frequency.begin(), frequency.end());
    
    // Sort descending by count
    sort(sortedFreq.begin(), sortedFreq.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    // Print results
    for (const auto& pair : sortedFreq) {
        cout << pair.first << ": " << pair.second << "\n";
    }
}

int main() {
    string feedback = "The mentor was great, the session was great and clear.";
    printFilteredWordFrequency(feedback);
    return 0;
}
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string reverseEachWord(string sentence) {
    stringstream ss(sentence);
    string word;
    string result = "";
    bool isFirst = true;

    // Split words by space
    while (ss >> word) {
        string reversedWord = "";
        // Reverse individual word
        for (int i = word.length() - 1; i >= 0; i--) {
            reversedWord += word[i];
        }
        
        if (!isFirst) {
            result += " ";
        }
        result += reversedWord;
        isFirst = false;
    }
    return result;
}

int main() {
    cout << reverseEachWord("hello club") << "\n";
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

char findFirstNonRepeatingChar(string text) {
    int freq[256] = {0};

    // Compute frequency of every character
    for (char c : text) {
        freq[static_cast<unsigned char>(c)]++;
    }

    // Scan string left to right to find the first character with frequency 1
    for (char c : text) {
        if (freq[static_cast<unsigned char>(c)] == 1) {
            return c;
        }
    }
    
    // Return null character if no unique character exists
    return '\0'; 
}

void testUniqueLetterHunt(string input) {
    char result = findFirstNonRepeatingChar(input);
    cout << "Input: \"" << input << "\"\n";
    if (result != '\0') {
        cout << "First Non-Repeating Character: '" << result << "'\n\n";
    } else {
        cout << "No Non-Repeating Character Found\n\n";
    }
}

int main() {
    testUniqueLetterHunt("swiss");
    testUniqueLetterHunt("aabbcc");
    return 0;
}
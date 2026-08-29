#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 1. Iterative Approach
bool isPalindromeIterative(string text) {
    int left = 0;
    int right = text.length() - 1;
    while (left < right) {
        if (text[left] != text[right]) return false;
        left++;
        right--;
    }
    return true;
}

// 2. Recursive Approach
bool isPalindromeRecursive(string text) {
    if (text.length() <= 1) return true;
    if (text[0] != text[text.length() - 1]) return false;
    // Shrink the substring each call
    return isPalindromeRecursive(text.substr(1, text.length() - 2));
}

// 3. Array Reversal Approach
bool isPalindromeArrayReversal(string text) {
    string reversedText = text;
    reverse(reversedText.begin(), reversedText.end());
    return text == reversedText;
}

void printChecks(string text) {
    cout << "Input: \"" << text << "\"\n";
    cout << "Iterative: " << (isPalindromeIterative(text) ? "Palindrome" : "Not Palindrome") << " | ";
    cout << "Recursive: " << (isPalindromeRecursive(text) ? "Palindrome" : "Not Palindrome") << " | ";
    cout << "Array Reversal: " << (isPalindromeArrayReversal(text) ? "Palindrome" : "Not Palindrome") << "\n\n";
}

int main() {
    printChecks("madam");
    printChecks("hello");
    return 0;
}
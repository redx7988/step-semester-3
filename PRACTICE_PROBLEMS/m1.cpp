#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void countVowelsAndConsonants(string text) {
    int vowels = 0;
    int consonants = 0;

    for (char c : text) {
        if (isalpha(c)) {
            char lower_c = tolower(c);
            if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || 
                lower_c == 'o' || lower_c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    cout << "Vowels: " << vowels << " | Consonants: " << consonants << "\n";
}

int main() {
    countVowelsAndConsonants("Java Programming");
    return 0;
}
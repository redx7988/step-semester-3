#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string normalizeCode(string raw) {
    // Trim leading and trailing spaces
    size_t start = raw.find_first_not_of(" ");
    size_t end = raw.find_last_not_of(" ");
    if (start == string::npos) return ""; // All spaces
    string trimmed = raw.substr(start, end - start + 1);

    // Uppercase the first 3 characters
    if (trimmed.length() >= 3) {
        for (int i = 0; i < 3; i++) {
            trimmed[i] = toupper(trimmed[i]);
        }
    }
    return trimmed;
}

string validateAndFormat(string code) {
    if (code.length() != 13) {
        return "Invalid: wrong length";
    }
    for (int i = 0; i < 3; i++) {
        if (!isalpha(code[i])) return "Invalid: publisher code must be 3 letters";
    }
    for (int i = 3; i < 13; i++) {
        if (!isdigit(code[i])) return "Invalid: non-digit body";
    }

    string pubCode = code.substr(0, 3);
    string year = code.substr(3, 4);
    string catalog = code.substr(7, 6);

    return "[" + pubCode + "] YEAR: " + year + " | CATALOG: " + catalog;
}

int main() {
    string norm1 = normalizeCode("   pen2026004251  ");
    cout << validateAndFormat(norm1) << "\n";

    string norm2 = normalizeCode("12N2026004251");
    cout << validateAndFormat(norm2) << "\n";

    return 0;
}
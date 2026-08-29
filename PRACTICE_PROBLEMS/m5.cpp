#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string normalizeReference(string raw) {
    // Trim leading and trailing spaces
    size_t start = raw.find_first_not_of(" ");
    size_t end = raw.find_last_not_of(" ");
    
    if (start == string::npos) return ""; // String is all spaces
    
    string trimmed = raw.substr(start, end - start + 1);

    // Uppercase the first 3 characters
    if (trimmed.length() >= 3) {
        for (int i = 0; i < 3; i++) {
            trimmed[i] = toupper(trimmed[i]);
        }
    }
    
    return trimmed;
}

string validateAndFormat(string reference) {
    if (reference.length() != 14) {
        return "Invalid: wrong length";
    }

    for (int i = 0; i < 3; i++) {
        if (!isalpha(reference[i])) {
            return "Invalid: bank code must be 3 letters";
        }
    }

    for (int i = 3; i < 14; i++) {
        if (!isdigit(reference[i])) {
            return "Invalid: non-digit body";
        }
    }

    string bankCode = reference.substr(0, 3);
    string dd = reference.substr(3, 2);
    string mm = reference.substr(5, 2);
    string yy = reference.substr(7, 2);
    string seq = reference.substr(9, 5);

    return "[" + bankCode + "] DATE: " + dd + "/" + mm + "/" + yy + " | SEQ: " + seq;
}

int main() {
    string norm1 = normalizeReference("   hdf03022600042  ");
    cout << validateAndFormat(norm1) << "\n";

    string norm2 = normalizeReference("12F03022600042");
    cout << validateAndFormat(norm2) << "\n";

    return 0;
}
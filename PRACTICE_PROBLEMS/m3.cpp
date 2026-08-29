#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string validateFileExtension(string filename) {
    size_t dotPos = filename.find_last_of('.');
    
    // If no dot is found or it's the last character
    if (dotPos == string::npos || dotPos == filename.length() - 1) {
        return "Rejected - invalid file type";
    }

    string extension = filename.substr(dotPos + 1);
    
    // Convert to lowercase for case-insensitive comparison
    for (char &c : extension) {
        c = tolower(c);
    }

    if (extension == "pdf" || extension == "docx" || extension == "zip") {
        return "Accepted";
    } else {
        return "Rejected - invalid file type";
    }
}

int main() {
    cout << validateFileExtension("Assignment1.PDF") << "\n";
    cout << validateFileExtension("notes.txt") << "\n";
    return 0;
}
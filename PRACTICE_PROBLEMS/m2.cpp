#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void parseStudentRecord(string csvLine) {
    stringstream ss(csvLine);
    string field;
    vector<string> fields;

    // Split by comma
    while (getline(ss, field, ',')) {
        // Trim leading spaces for clean output
        size_t start = field.find_first_not_of(" ");
        if (start != string::npos) {
            field = field.substr(start);
        }
        fields.push_back(field);
    }

    if (fields.size() != 3) {
        cout << "Invalid Record\n";
    } else {
        cout << "Name: " << fields[0] << " | Roll No: " << fields[1] << " | Dept: " << fields[2] << "\n";
    }
}

int main() {
    parseStudentRecord("Ananya Verma, RA2211003010123, CSE");
    parseStudentRecord("Ananya Verma, CSE");
    return 0;
}
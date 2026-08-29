#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void parseInventoryRecord(string csvLine) {
    stringstream ss(csvLine);
    string field;
    vector<string> fields;

    // Split by comma
    while (getline(ss, field, ',')) {
        // Trim leading spaces for a cleaner output
        size_t start = field.find_first_not_of(" ");
        if (start != string::npos) {
            field = field.substr(start);
        }
        fields.push_back(field);
    }

    // Validate exactly 3 fields are present
    if (fields.size() != 3) {
        cout << "Invalid Record\n";
    } else {
        cout << "Product: " << fields[0] << " | SKU: " << fields[1] << " | Qty: " << fields[2] << "\n";
    }
}

int main() {
    parseInventoryRecord("Wireless Mouse, WM-2201, 150");
    parseInventoryRecord("Wireless Mouse, 150");
    return 0;
}
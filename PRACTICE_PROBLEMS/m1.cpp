#include <iostream>
#include <string>
using namespace std;

class PlacementRecord {
public:
    string studentName;
    string company;
    double packageLpa;

    // Constructor to set all three fields
    PlacementRecord(string name, string comp, double packageVal) {
        studentName = name;
        company = comp;
        packageLpa = packageVal;
    }

    // Instance method to print formatted record
    void printRecord() {
        cout << studentName << " -> " << company << " @ " << packageLpa << " LPA\n";
    }
};

int main() {
    // Array of PlacementRecord objects
    PlacementRecord records[3] = {
        PlacementRecord("Ravi", "TCS", 4.5),
        PlacementRecord("Anitha", "Zoho", 6.2),
        PlacementRecord("Karthik", "Infosys", 4.0)
    };

    // Print each one in a loop
    for(int i = 0; i < 3; i++) {
        records[i].printRecord();
    }

    return 0;
}
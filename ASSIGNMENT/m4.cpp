#include <iostream>
#include <string>
using namespace std;

class IdCard {
public:
    string name;
    int booksIssued;

    IdCard(string n, int b) {
        name = n;
        booksIssued = b;
    }
};

int main() {
    // Creating object dynamically so variables hold memory references (pointers)
    IdCard* ravi = new IdCard("Ravi", 0);
    
    // duplicate points to the exact same object
    IdCard* duplicate = ravi; 
    duplicate->booksIssued = 3;

    // separate points to a completely new object with identical values
    IdCard* separate = new IdCard("Ravi", 3);

    cout << "Ravi's booksIssued (via first variable): " << ravi->booksIssued << "\n";
    
    // Comparing addresses effectively mimics Java's == operator for object identity
    cout << "duplicate == ravi: " << (duplicate == ravi ? "true" : "false") << "\n";
    cout << "separate == ravi: " << (separate == ravi ? "false" : "true") << "\n";

    // Clean up memory
    delete ravi;
    delete separate;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class BookInventory {
public:
    string title;
    string author;
    int copiesAvailable;

    // Constructor setting all three fields
    BookInventory(string t, string a, int c) {
        title = t;
        author = a;
        copiesAvailable = c;
    }

    // Instance method to print the entry
    void printEntry() {
        cout << title << " by " << author << " - " << copiesAvailable << " copies available\n";
    }
};

int main() {
    // Array of 4 BookInventory objects
    BookInventory inventory[4] = {
        BookInventory("Clean Code", "Robert C. Martin", 3),
        BookInventory("Effective Java", "Joshua Bloch", 5),
        BookInventory("Refactoring", "Martin Fowler", 0),
        BookInventory("Design Patterns", "GoF", 2)
    };

    // Print each one in a loop
    for(int i = 0; i < 4; i++) {
        inventory[i].printEntry();
    }

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class LibraryBook {
private:
    string title;
    string isbn;
    bool catalogued;

public:
    // Primary Constructor
    LibraryBook(string title, string isbn) {
        this->title = title;
        this->isbn = isbn;
        this->catalogued = true;
    }

    // Delegating Constructor (Chains via the primary constructor)
    LibraryBook(string title) : LibraryBook(title, "PENDING") {}

    void printStatus() {
        cout << title << " | " << isbn << " | Catalogued: " 
             << (catalogued ? "true" : "false") << endl;
    }
};

int main() {
    string titles[] = {"Clean Code", "Untitled Draft", "1984", "Notes"};
    string isbns[] = {"978-0132350884", "", "9780451524935", ""};

    for (int i = 0; i < 4; i++) {
        if (isbns[i] == "") {
            LibraryBook book(titles[i]);
            book.printStatus();
        } else {
            LibraryBook book(titles[i], isbns[i]);
            book.printStatus();
        }
    }
    return 0;
}
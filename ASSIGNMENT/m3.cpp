#include <iostream>
#include <string>
using namespace std;

class Course {
public:
    string code;
    string title;
    int credits;
    int labCredits;

    // Four-argument constructor
    Course(string c, string t, int cr, int lcr) {
        code = c;
        title = t;
        credits = cr;
        labCredits = lcr;
    }

    // Theory-only constructor chaining to the main constructor (requires C++11)
    Course(string c, string t, int cr) : Course(c, t, cr, 0) {}

    int totalCredits() {
        return credits + labCredits;
    }
};

int main() {
    Course c1("21CSC201J", "Data Structures", 4);
    cout << c1.code << " total credits:\n" << c1.totalCredits() << "\n\n";

    Course c2("21CSC205L", "DSA Lab", 3, 1);
    cout << c2.code << " total credits:\n" << c2.totalCredits() << "\n";

    return 0;
}
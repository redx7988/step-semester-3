#include <iostream>
#include <string>
using namespace std;

class HallTicket {
public:
    string studentName;
    int seatNumber;

    HallTicket(string name, int seat) {
        studentName = name;
        seatNumber = seat;
    }
};

int main() {
    // Creating object dynamically to hold a memory reference
    HallTicket* priya = new HallTicket("Priya", 0);
    
    // copy points to the exact same object
    HallTicket* copy = priya; 
    copy->seatNumber = 45;

    cout << "Priya's seatNumber (via first variable): " << priya->seatNumber << "\n";
    
    // Memory address comparison acts identically to Java's reference ==
    cout << "copy == priya: " << (copy == priya ? "true" : "false") << "\n";
    
    // separate points to a new object with identical content
    HallTicket* separate = new HallTicket("Priya", 45);
    cout << "separate == priya: " << (separate == priya ? "false" : "true") << "\n";

    delete priya;
    delete separate;
    return 0;
}
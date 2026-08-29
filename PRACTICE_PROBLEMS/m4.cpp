#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string maskPhoneNumber(string phone) {
    if (phone.length() != 10) {
        return "Invalid phone number";
    }

    for (char c : phone) {
        if (!isdigit(c)) {
            return "Invalid phone number";
        }
    }

    // Mask first 6 digits and append the last 4
    return "XXXXXX-" + phone.substr(6, 4);
}

int main() {
    cout << maskPhoneNumber("9876543210") << "\n";
    cout << maskPhoneNumber("98765") << "\n";
    return 0;
}
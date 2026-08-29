#include <iostream>
#include <string>
using namespace std;

void checkPinLength(string pin) {
    if (pin.length() == 4) {
        cout << "PIN length OK.\n";
    } else {
        cout << "Invalid PIN must be exactly 4 digits.\n";
    }
}

int main() {
    checkPinLength("482");
    checkPinLength("4820");
    return 0;
}
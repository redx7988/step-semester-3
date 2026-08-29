#include <iostream>
#include <string>
using namespace std;

string reverseCustomerName(string customerName) {
    string reversedName = "";
    // Reconstruct string in reverse order
    for (int i = customerName.length() - 1; i >= 0; i--) {
        reversedName += customerName[i];
    }
    return reversedName;
}

int main() {
    string name = "Sunil";
    string reversed = reverseCustomerName(name);

    cout << "Original Name: " << name << "\n";
    cout << "Reversed Name: " << reversed << "\n";

    return 0;
}
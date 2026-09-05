#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item {
private:
    string itemName;
    int stock;

public:
    Item(string itemName, int stock) {
        this->itemName = itemName;
        this->stock = stock;
    }

    void restock(int stock) {
        this->stock += stock;
    }

    void printItem() const {
        cout << itemName << " | Final Stock: " << stock << "\n";
    }
};

int main() {
    vector<Item> items = {
        Item("Samosa", 15),
        Item("Tea Powder", 40),
        Item("Bread", 8),
        Item("Biscuit Packs", 25)
    };

    for (Item& item : items) {
        item.restock(20);
        item.printItem();
    }
    return 0;
}
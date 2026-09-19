#include <iostream>
#include <string>
#include <vector>

// Interface definition in C++
class Printable {
public:
    virtual ~Printable() = default;
    virtual std::string printLabel() const = 0;
};

class PackageBox : public Printable {
private:
    std::string trackingId;

public:
    PackageBox(std::string trackingId) : trackingId(trackingId) {}

    std::string printLabel() const override {
        return "Package label: " + trackingId;
    }
};

class Invoice : public Printable {
private:
    std::string invoiceNumber;

public:
    Invoice(std::string invoiceNumber) : invoiceNumber(invoiceNumber) {}

    std::string printLabel() const override {
        return "Invoice label: " + invoiceNumber;
    }
};

// Static method simulation
void printAll(const std::vector<Printable*>& items) {
    for (const Printable* item : items) {
        if (item) {
            std::cout << item->printLabel() << "\n";
        }
    }
}

int main() {
    PackageBox p("TRK-88");
    std::cout << p.printLabel() << "\n";

    Invoice i("INV-42");
    std::cout << i.printLabel() << "\n";

    std::cout << "\n--- Batch Print ---\n";
    std::vector<Printable*> items = {&p, &i};
    printAll(items);

    return 0;
}
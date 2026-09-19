#include <iostream>
#include <string>
#include <vector>

class DeliveryNote {
protected:
    std::string trackingId;

public:
    DeliveryNote(std::string trackingId) : trackingId(trackingId) {}
    virtual ~DeliveryNote() = default;

    // Abstract method
    virtual std::string confirmDelivery() const = 0;

    // Overloaded method using compile-time polymorphism that calls the abstract method internally
    std::string confirmDelivery(const std::string& signature) const {
        return confirmDelivery() + ", signed by " + signature;
    }
};

class ParcelNote : public DeliveryNote {
public:
    ParcelNote(std::string trackingId) : DeliveryNote(trackingId) {}

    std::string confirmDelivery() const override {
        return "Parcel " + trackingId + " delivered";
    }
};

class LetterNote : public DeliveryNote {
public:
    LetterNote(std::string trackingId) : DeliveryNote(trackingId) {}

    std::string confirmDelivery() const override {
        return "Letter " + trackingId + " delivered";
    }
};

// Static method simulation to log a mixed array
void logAll(const std::vector<DeliveryNote*>& notes) {
    for (const DeliveryNote* note : notes) {
        if (note) {
            std::cout << note->confirmDelivery() << "\n";
        }
    }
}

int main() {
    ParcelNote p("TRK-1");
    std::cout << p.confirmDelivery() << "\n";
    std::cout << p.confirmDelivery("J. Smith") << "\n";

    std::cout << "\n--- Batch Log ---\n";
    DeliveryNote* ref = &p;
    LetterNote l("TRK-2");
    
    std::vector<DeliveryNote*> notes = {ref, &l};
    logAll(notes);

    return 0;
}
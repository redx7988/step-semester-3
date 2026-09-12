#include <iostream>
#include <string>
#include <vector>

using namespace std;

// C++ note: While the prompt asks for a 'final' class, Java does not permit a 'final' class 
// to be extended by 'ReferenceOnlyLoanReceipt'. We keep fields strictly const (final equivalent) to ensure immutability[cite: 1].
class LoanReceipt {
protected:
    const string memberId;
    const vector<string> bookIds; // C++ vector copy assignments handle defensive array copying

public:
    // Defensively copies the bookIds array on the way in[cite: 1]
    LoanReceipt(const string& memberId, const vector<string>& ids)
        : memberId(memberId), bookIds(ids) {} 
        
    virtual ~LoanReceipt() = default;

    // Defensively copies on the way out (returning vector by value creates a distinct copy)[cite: 1]
    vector<string> getBookIds() const {
        return bookIds;
    }

    string getMemberId() const {
        return memberId;
    }

    // Wither pattern returns a brand-new object leaving the original untouched[cite: 1]
    LoanReceipt* withCorrectedBookId(int index, const string& newId) const {
        vector<string> newIds = bookIds;
        if (index >= 0 && index < newIds.size()) {
            newIds[index] = newId;
        }
        return new LoanReceipt(memberId, newIds);
    }
};

// Extends LoanReceipt for reference-only items[cite: 1]
class ReferenceOnlyLoanReceipt : public LoanReceipt {
private:
    const string roomNumber;

public:
    ReferenceOnlyLoanReceipt(const string& memberId, const vector<string>& bookIds, const string& roomNumber)
        : LoanReceipt(memberId, bookIds), roomNumber(roomNumber) {}
};

class CirculationLedger {
public:
    static string processNightlyCirculation(const vector<LoanReceipt*>& receipts) {
        int total = 0, nullSkipped = 0, referenceOnly = 0, regular = 0;

        for (const auto* receipt : receipts) {
            total++;
            // Never throws an exception because of a null entry[cite: 1]
            if (receipt == nullptr) {
                nullSkipped++;
                continue;
            }

            // Uses dynamic_cast (C++ equivalent of Java's instanceof) to settle distinct types[cite: 1]
            if (dynamic_cast<const ReferenceOnlyLoanReceipt*>(receipt) != nullptr) {
                referenceOnly++;
            } else {
                regular++;
            }
        }

        return to_string(total) + " processed | " + 
               to_string(nullSkipped) + " null skipped | " + 
               to_string(referenceOnly) + " reference-only | " + 
               to_string(regular) + " regular";
    }
};
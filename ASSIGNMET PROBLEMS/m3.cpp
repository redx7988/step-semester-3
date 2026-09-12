class BookInventory {
private:
    int copiesTotal;      // Both must be private[cite: 1]
    int copiesAvailable;

public:
    BookInventory(int copiesTotal) {
        this->copiesTotal = (copiesTotal > 0) ? copiesTotal : 0;
        this->copiesAvailable = this->copiesTotal;
    }

    void checkOut() {
        // Silently reject if no copies are available[cite: 1]
        if (copiesAvailable > 0) {
            copiesAvailable--;
        }
    }

    void checkIn() {
        // Silently reject if inventory is already at full capacity[cite: 1]
        if (copiesAvailable < copiesTotal) {
            copiesAvailable++;
        }
    }

    int getCopiesAvailable() const {
        return copiesAvailable;
    }
};
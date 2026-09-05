#include <string>
#include <vector>

using namespace std;

class BookingReceipt {
protected:
    const string bookingId;
    const vector<string> seatNumbers;

public:
    BookingReceipt(string id, const vector<string>& seats) 
        : bookingId(id), seatNumbers(seats) {}

    virtual ~BookingReceipt() = default; 

    vector<string> getSeatNumbers() const {
        return seatNumbers; 
    }

    string getBookingId() const {
        return bookingId;
    }

    BookingReceipt withUpdatedSeat(int index, const string& newSeat) const {
        vector<string> newSeats = seatNumbers;
        if (index >= 0 && index < newSeats.size()) {
            newSeats[index] = newSeat;
        }
        return BookingReceipt(bookingId, newSeats);
    }
};

class GroupBookingReceipt : public BookingReceipt {
private:
    const int groupSize;

public:
    GroupBookingReceipt(string id, const vector<string>& seats, int size)
        : BookingReceipt(id, seats), groupSize(size) {}
    
    int getGroupSize() const { 
        return groupSize; 
    }
};

class SettlementProcessor {
public:
    static string processNightlySettlement(const vector<BookingReceipt*>& receipts) {
        int processed = 0, nullSkipped = 0, groupCount = 0, individualCount = 0;

        for (BookingReceipt* receipt : receipts) {
            if (receipt == nullptr) {
                nullSkipped++;
                continue;
            }
            processed++;
            
            if (dynamic_cast<GroupBookingReceipt*>(receipt) != nullptr) {
                groupCount++;
            } else {
                individualCount++;
            }
        }

        return to_string(processed) + " processed | " + to_string(nullSkipped) + " null skipped\n" +
               to_string(groupCount) + " group | " + to_string(individualCount) + " individual";
    }
};
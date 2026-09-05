#include <stdexcept>

class CineScreen {
private:
    int seatsTotal;
    int seatsAvailable;

public:
    CineScreen(int seatsTotal) {
        if (seatsTotal <= 0) {
            throw std::invalid_argument("construction rejected");
        }
        this->seatsTotal = seatsTotal;
        this->seatsAvailable = seatsTotal;
    }

    void bookSeat() {
        if (seatsAvailable > 0) {
            seatsAvailable--;
        }
    }

    void cancelBooking() {
        if (seatsAvailable < seatsTotal) {
            seatsAvailable++;
        }
    }

    int getSeatsAvailable() const {
        return seatsAvailable;
    }
};
#include <string>

using namespace std;

class MovieBookingProfile {
private:
    string name;
    bool confirmed;
    string otp;

public:
    MovieBookingProfile() : name(""), confirmed(false), otp("") {}

    MovieBookingProfile(string name) : MovieBookingProfile() {
        this->name = name;
    }

    string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    bool isConfirmed() const {
        return confirmed;
    }

    void setConfirmed(bool confirmed) {
        this->confirmed = confirmed;
    }

    void setOtp(string otp) {
        this->otp = otp;
    }
};
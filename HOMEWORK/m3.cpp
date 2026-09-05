#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ParkingTicket {
private:
    string vehicleNo;
    double ratePerMinute;

public:
    ParkingTicket(string vNo, double rate) : vehicleNo(vNo), ratePerMinute(rate) {}

    // virtual and final used to mimic Java's final method restriction
    virtual double calculateFine(int overstayMinutes) final {
        return overstayMinutes * ratePerMinute;
    }

    virtual void printReceipt(int overstayMinutes) final {
        cout << vehicleNo << " - Fine: Rs " << calculateFine(overstayMinutes) << "\n";
    }
};

int main() {
    vector<string> vehicleNos = {"TN09AB1234", "TN22CD5678", "TN09EF9012", "TN10GH3456"};
    vector<double> rates = {2.0, 2.0, 3.0, 2.0};
    vector<int> overstayMinutes = {15, 0, -5, 8};

    for (size_t i = 0; i < vehicleNos.size(); i++) {
        if (overstayMinutes[i] > 0) {
            ParkingTicket pt(vehicleNos[i], rates[i]);
            pt.printReceipt(overstayMinutes[i]);
        } else {
            cout << vehicleNos[i] << " - No fine, within allotted time\n";
        }
    }
    return 0;
}
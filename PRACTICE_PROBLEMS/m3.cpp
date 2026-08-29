#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

string getBmiStatus(double bmi) {
    if (bmi < 18.5) return "Underweight";
    if (bmi >= 18.5 && bmi <= 24.9) return "Normal";
    if (bmi >= 25.0 && bmi <= 29.9) return "Overweight";
    return "Obese";
}

void printWellnessReport(const vector<double>& heights, const vector<double>& weights) {
    cout << left << setw(10) << "Person" << setw(15) << "Height (m)" 
         << setw(15) << "Weight (kg)" << setw(10) << "BMI" << "Status\n";
    cout << string(60, '-') << "\n";

    for (size_t i = 0; i < heights.size(); i++) {
        double bmi = weights[i] / (heights[i] * heights[i]);
        string status = getBmiStatus(bmi);

        cout << left << setw(10) << ("Person " + to_string(i + 1))
             << setw(15) << fixed << setprecision(2) << heights[i]
             << setw(15) << weights[i]
             << setw(10) << bmi
             << status << "\n";
    }
}

int main() {
    // Random demo data for 10 people
    vector<double> heights = {1.75, 1.60, 1.82, 1.65, 1.90, 1.55, 1.70, 1.80, 1.68, 1.72};
    vector<double> weights = {70.0, 90.0, 75.0, 50.0, 115.0, 45.0, 68.0, 95.0, 72.0, 60.0};

    printWellnessReport(heights, weights);
    return 0;
}
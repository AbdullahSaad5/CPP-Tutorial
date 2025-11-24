#include <iostream>
using namespace std;

int main() {
    cout << "=== AND Operator (&&) ===" << endl;
    int age = 25;
    bool hasLicense = true;

    if (age >= 18 && hasLicense) {
        cout << "You can drive!" << endl;
    } else {
        cout << "You cannot drive." << endl;
    }

    cout << "\n=== OR Operator (||) ===" << endl;
    bool isWeekend = true;
    bool isHoliday = false;

    if (isWeekend || isHoliday) {
        cout << "No work today!" << endl;
    } else {
        cout << "Work day." << endl;
    }

    cout << "\n=== NOT Operator (!) ===" << endl;
    bool isRaining = false;

    if (!isRaining) {
        cout << "Good weather, go outside!" << endl;
    } else {
        cout << "Stay inside, it's raining." << endl;
    }

    cout << "\n=== Combined Logical Operators ===" << endl;
    int score = 85;
    int attendance = 90;
    bool completedProject = true;

    if ((score >= 80 && attendance >= 85) || completedProject) {
        cout << "You passed the course!" << endl;
    } else {
        cout << "You did not pass." << endl;
    }

    cout << "\n=== Multiple Conditions ===" << endl;
    int hour = 14;

    if (hour >= 6 && hour < 12) {
        cout << "Good morning!" << endl;
    } else if (hour >= 12 && hour < 18) {
        cout << "Good afternoon!" << endl;
    } else if (hour >= 18 && hour < 22) {
        cout << "Good evening!" << endl;
    } else {
        cout << "Good night!" << endl;
    }

    cout << "\n=== Range Checking ===" << endl;
    int value = 50;

    if (value >= 1 && value <= 100) {
        cout << value << " is within range [1-100]" << endl;
    } else {
        cout << value << " is out of range" << endl;
    }

    return 0;
}

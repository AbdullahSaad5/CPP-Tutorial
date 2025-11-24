#include <iostream>
using namespace std;

enum Day {
    MONDAY,      // 0
    TUESDAY,     // 1
    WEDNESDAY,   // 2
    THURSDAY,    // 3
    FRIDAY,      // 4
    SATURDAY,    // 5
    SUNDAY       // 6
};

enum Color {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    BLACK,
    WHITE
};

enum Season {
    SPRING = 1,  // You can assign specific values
    SUMMER = 2,
    FALL = 3,
    WINTER = 4
};

int main() {
    cout << "=== Day Enumeration ===" << endl;

    Day today = MONDAY;
    Day tomorrow = TUESDAY;

    cout << "Today (numeric value): " << today << endl;
    cout << "Tomorrow (numeric value): " << tomorrow << endl;

    if (today == MONDAY) {
        cout << "It's Monday!" << endl;
    }

    cout << "\n=== Switch with Enum ===" << endl;
    Day day = FRIDAY;

    switch (day) {
        case MONDAY:
            cout << "Start of work week" << endl;
            break;
        case TUESDAY:
        case WEDNESDAY:
        case THURSDAY:
            cout << "Middle of work week" << endl;
            break;
        case FRIDAY:
            cout << "End of work week" << endl;
            break;
        case SATURDAY:
        case SUNDAY:
            cout << "Weekend!" << endl;
            break;
    }

    cout << "\n=== Color Enumeration ===" << endl;
    Color favoriteColor = BLUE;

    cout << "Favorite color value: " << favoriteColor << endl;

    if (favoriteColor == BLUE) {
        cout << "You like blue!" << endl;
    }

    cout << "\n=== Season Enumeration ===" << endl;
    Season currentSeason = WINTER;

    cout << "Current season value: " << currentSeason << endl;

    return 0;
}

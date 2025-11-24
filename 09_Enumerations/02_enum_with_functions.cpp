#include <iostream>
using namespace std;

enum Month {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

Month getNextMonth(Month current) {
    if (current == DECEMBER) {
        return JANUARY;
    } else {
        return static_cast<Month>(current + 1);
    }
}

string getMonthName(Month m) {
    switch (m) {
        case JANUARY: return "January";
        case FEBRUARY: return "February";
        case MARCH: return "March";
        case APRIL: return "April";
        case MAY: return "May";
        case JUNE: return "June";
        case JULY: return "July";
        case AUGUST: return "August";
        case SEPTEMBER: return "September";
        case OCTOBER: return "October";
        case NOVEMBER: return "November";
        case DECEMBER: return "December";
        default: return "Unknown";
    }
}

int getDaysInMonth(Month m) {
    switch (m) {
        case JANUARY:
        case MARCH:
        case MAY:
        case JULY:
        case AUGUST:
        case OCTOBER:
        case DECEMBER:
            return 31;
        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            return 30;
        case FEBRUARY:
            return 28;  // Ignoring leap years
        default:
            return 0;
    }
}

enum Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

Direction getOppositeDirection(Direction dir) {
    switch (dir) {
        case NORTH: return SOUTH;
        case SOUTH: return NORTH;
        case EAST: return WEST;
        case WEST: return EAST;
    }
    return NORTH;  // Default
}

string getDirectionName(Direction dir) {
    switch (dir) {
        case NORTH: return "North";
        case SOUTH: return "South";
        case EAST: return "East";
        case WEST: return "West";
    }
    return "Unknown";
}

int main() {
    cout << "=== Month Functions ===" << endl;

    Month current = MARCH;
    cout << "Current month: " << getMonthName(current) << endl;
    cout << "Days in month: " << getDaysInMonth(current) << endl;

    Month next = getNextMonth(current);
    cout << "Next month: " << getMonthName(next) << endl;

    cout << "\n=== All Months ===" << endl;
    for (int i = JANUARY; i <= DECEMBER; i++) {
        Month m = static_cast<Month>(i);
        cout << getMonthName(m) << " has " << getDaysInMonth(m) << " days" << endl;
    }

    cout << "\n=== Direction Functions ===" << endl;
    Direction dir = NORTH;

    cout << "Facing: " << getDirectionName(dir) << endl;
    cout << "Opposite: " << getDirectionName(getOppositeDirection(dir)) << endl;

    dir = EAST;
    cout << "\nFacing: " << getDirectionName(dir) << endl;
    cout << "Opposite: " << getDirectionName(getOppositeDirection(dir)) << endl;

    return 0;
}

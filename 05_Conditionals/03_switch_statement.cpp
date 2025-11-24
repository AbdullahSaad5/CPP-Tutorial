#include <iostream>
using namespace std;

int main() {
    cout << "=== Basic Switch ===" << endl;
    int day = 3;

    switch (day) {
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
        case 7:
            cout << "Sunday" << endl;
            break;
        default:
            cout << "Invalid day" << endl;
    }

    cout << "\n=== Menu System ===" << endl;
    int choice = 2;

    cout << "Menu:" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. Settings" << endl;
    cout << "4. Exit" << endl;
    cout << "\nYou selected: " << choice << endl;

    switch (choice) {
        case 1:
            cout << "Starting new game..." << endl;
            break;
        case 2:
            cout << "Loading saved game..." << endl;
            break;
        case 3:
            cout << "Opening settings..." << endl;
            break;
        case 4:
            cout << "Exiting game..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    cout << "\n=== Character Switch ===" << endl;
    char operation = '+';
    int a = 10, b = 5;

    switch (operation) {
        case '+':
            cout << a << " + " << b << " = " << (a + b) << endl;
            break;
        case '-':
            cout << a << " - " << b << " = " << (a - b) << endl;
            break;
        case '*':
            cout << a << " * " << b << " = " << (a * b) << endl;
            break;
        case '/':
            cout << a << " / " << b << " = " << (a / b) << endl;
            break;
        default:
            cout << "Invalid operation!" << endl;
    }

    cout << "\n=== Grouped Cases ===" << endl;
    int month = 4;

    switch (month) {
        case 12:
        case 1:
        case 2:
            cout << "Winter" << endl;
            break;
        case 3:
        case 4:
        case 5:
            cout << "Spring" << endl;
            break;
        case 6:
        case 7:
        case 8:
            cout << "Summer" << endl;
            break;
        case 9:
        case 10:
        case 11:
            cout << "Fall" << endl;
            break;
        default:
            cout << "Invalid month" << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    cout << "=== Login System ===" << endl;
    string username = "admin";
    string password = "pass123";

    string inputUser = "admin";
    string inputPass = "pass123";

    if (inputUser == username && inputPass == password) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid username or password!" << endl;
    }

    cout << "\n=== Move Validation ===" << endl;
    int row = 1, col = 1;
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', 'X', ' '},
        {' ', ' ', ' '}
    };

    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        if (board[row][col] == ' ') {
            cout << "Valid move! Position is empty." << endl;
            board[row][col] = 'O';
        } else {
            cout << "Invalid move! Position already occupied." << endl;
        }
    } else {
        cout << "Invalid move! Out of bounds." << endl;
    }

    cout << "\n=== Win Condition Check ===" << endl;
    char testBoard[3][3] = {
        {'X', 'X', 'X'},
        {'O', 'O', ' '},
        {' ', ' ', ' '}
    };

    if (testBoard[0][0] == 'X' && testBoard[0][1] == 'X' && testBoard[0][2] == 'X') {
        cout << "Player X wins on top row!" << endl;
    }

    cout << "\n=== Temperature Warning ===" << endl;
    int temp = 35;

    if (temp < 0) {
        cout << "WARNING: Freezing temperature!" << endl;
    } else if (temp >= 0 && temp < 10) {
        cout << "Cold - Wear a jacket" << endl;
    } else if (temp >= 10 && temp < 20) {
        cout << "Cool - Comfortable weather" << endl;
    } else if (temp >= 20 && temp < 30) {
        cout << "Warm - Nice weather" << endl;
    } else {
        cout << "WARNING: Very hot temperature!" << endl;
    }

    cout << "\n=== Leap Year Checker ===" << endl;
    int year = 2024;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " is a leap year" << endl;
    } else {
        cout << year << " is not a leap year" << endl;
    }

    cout << "\n=== Triangle Validity ===" << endl;
    int side1 = 3, side2 = 4, side3 = 5;

    if (side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2) {
        cout << "Valid triangle!" << endl;

        if (side1 == side2 && side2 == side3) {
            cout << "Equilateral triangle" << endl;
        } else if (side1 == side2 || side2 == side3 || side1 == side3) {
            cout << "Isosceles triangle" << endl;
        } else {
            cout << "Scalene triangle" << endl;
        }
    } else {
        cout << "Invalid triangle!" << endl;
    }

    return 0;
}

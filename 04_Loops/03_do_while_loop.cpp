#include <iostream>
using namespace std;

int main() {
    cout << "Do-while loop (1 to 5):" << endl;
    int i = 1;
    do {
        cout << i << " ";
        i++;
    } while (i <= 5);
    cout << endl;

    int choice;
    do {
        cout << "\n=== Menu ===" << endl;
        cout << "1. Option 1" << endl;
        cout << "2. Option 2" << endl;
        cout << "3. Option 3" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "You selected Option 1" << endl;
                break;
            case 2:
                cout << "You selected Option 2" << endl;
                break;
            case 3:
                cout << "You selected Option 3" << endl;
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);

    int secretNumber = 7;
    int guess;

    cout << "\n=== Number Guessing Game ===" << endl;
    cout << "I'm thinking of a number between 1 and 10" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Correct! You win!" << endl;
        }
    } while (guess != secretNumber);

    return 0;
}

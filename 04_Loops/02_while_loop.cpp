#include <iostream>
using namespace std;

int main() {
    cout << "Counting with while loop:" << endl;
    int i = 1;
    while (i <= 5) {
        cout << i << " ";
        i++;
    }
    cout << endl;

    cout << "\nSum of numbers from 1 to 10:" << endl;
    int sum = 0;
    int n = 1;
    while (n <= 10) {
        sum += n;
        n++;
    }
    cout << "Sum = " << sum << endl;

    int number;
    cout << "\nEnter a positive number: ";
    cin >> number;

    while (number <= 0) {
        cout << "Invalid! Please enter a positive number: ";
        cin >> number;
    }
    cout << "You entered: " << number << endl;

    int factorial = 1;
    int num = 5;
    int temp = num;

    cout << "\nFactorial of " << num << ":" << endl;
    while (temp > 0) {
        factorial *= temp;
        temp--;
    }
    cout << num << "! = " << factorial << endl;

    cout << "\nCountdown:" << endl;
    int countdown = 5;
    while (countdown > 0) {
        cout << countdown << "..." << endl;
        countdown--;
    }
    cout << "Blast off!" << endl;

    return 0;
}

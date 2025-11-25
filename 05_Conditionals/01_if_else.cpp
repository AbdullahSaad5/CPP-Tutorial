#include <iostream>
using namespace std;

int main() {
    int age = 16;

    cout << "=== Simple If ===" << endl;
    if (age >= 18) {
        cout << "You are an adult." << endl;
    }

    cout << "\n=== If-Else ===" << endl;
    int number = 7;

    if (number % 2 == 0) {
        cout << number << " is even." << endl;
    } else {
        cout << number << " is odd." << endl;
    }

    cout << "\n=== If-Else-If ===" << endl;
    int score = 85;

    if (score >= 90) {
        cout << "Grade: A" << endl;
    } else if (score >= 80) {
        cout << "Grade: B" << endl;
    } else if (score >= 70) {
        cout << "Grade: C" << endl;
    } else if (score >= 60) {
        cout << "Grade: D" << endl;
    } else {
        cout << "Grade: F" << endl;
    }

    cout << "\n=== Nested If ===" << endl;
    int temperature = 25;
    bool isSunny = true;

    if (temperature > 20) {
        if (isSunny) {
            cout << "Perfect weather for outdoor activities!" << endl;
        } else {
            cout << "Warm but cloudy." << endl;
        }
    } else {
        cout << "Too cold for outdoor activities." << endl;
    }

    cout << "\n=== Comparison Operators ===" << endl;
    int a = 10, b = 20;

    cout << "a = " << a << ", b = " << b << endl;
    cout << "a == b: " << (a == b) << endl;  // Equal to
    cout << "a != b: " << (a != b) << endl;  // Not equal to
    cout << "a < b: " << (a < b) << endl;    // Less than
    cout << "a > b: " << (a > b) << endl;    // Greater than
    cout << "a <= b: " << (a <= b) << endl;  // Less than or equal
    cout << "a >= b: " << (a >= b) << endl;  // Greater than or equal

    return 0;
}

#include <iostream>
using namespace std;

void incrementByValue(int x) {
    x = x + 1;
    cout << "Inside function: " << x << endl;
}

void incrementByReference(int &x) {
    x = x + 1;
    cout << "Inside function: " << x << endl;
}

int calculate(int a, int b, char operation) {
    switch (operation) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

void printMessage(string message = "Hello", int times = 1) {
    for (int i = 0; i < times; i++) {
        cout << message << endl;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== Pass by Value ===" << endl;
    int num1 = 10;
    cout << "Before: " << num1 << endl;
    incrementByValue(num1);
    cout << "After: " << num1 << endl;  // Still 10

    cout << "\n=== Pass by Reference ===" << endl;
    int num2 = 10;
    cout << "Before: " << num2 << endl;
    incrementByReference(num2);
    cout << "After: " << num2 << endl;  // Now 11

    cout << "\n=== Calculator ===" << endl;
    cout << "10 + 5 = " << calculate(10, 5, '+') << endl;
    cout << "10 - 5 = " << calculate(10, 5, '-') << endl;
    cout << "10 * 5 = " << calculate(10, 5, '*') << endl;

    cout << "\n=== Default Parameters ===" << endl;
    printMessage();                      // Uses defaults
    printMessage("Hi");                  // Custom message
    printMessage("Welcome", 3);          // Custom message and times

    cout << "\n=== Array Parameter ===" << endl;
    int numbers[] = {1, 2, 3, 4, 5};
    printArray(numbers, 5);

    return 0;
}

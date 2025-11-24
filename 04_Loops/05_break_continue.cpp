#include <iostream>
using namespace std;

int main() {
    cout << "=== Break Example ===" << endl;
    cout << "Counting until we hit 5:" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            cout << "Found 5! Breaking out of loop." << endl;
            break;
        }
        cout << i << " ";
    }
    cout << endl;

    int numbers[] = {10, 20, 30, -5, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "\n=== Finding First Negative ===" << endl;
    for (int i = 0; i < size; i++) {
        if (numbers[i] < 0) {
            cout << "First negative number: " << numbers[i] << endl;
            cout << "Found at index: " << i << endl;
            break;
        }
    }

    cout << "\n=== Continue Example ===" << endl;
    cout << "Printing only odd numbers from 1 to 10:" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // Skip even numbers
        }
        cout << i << " ";
    }
    cout << endl;

    cout << "\n=== Skipping Multiples of 3 ===" << endl;
    cout << "Numbers 1-20, skipping multiples of 3:" << endl;
    for (int i = 1; i <= 20; i++) {
        if (i % 3 == 0) {
            continue;  // Skip multiples of 3
        }
        cout << i << " ";
    }
    cout << endl;

    int values[] = {5, -3, 8, -1, 12, -7, 4};
    int arraySize = sizeof(values) / sizeof(values[0]);
    int sum = 0;

    cout << "\n=== Sum of Positive Numbers Only ===" << endl;
    for (int i = 0; i < arraySize; i++) {
        if (values[i] < 0) {
            continue;  // Skip negative numbers
        }
        sum += values[i];
    }
    cout << "Sum of positive numbers: " << sum << endl;

    cout << "\n=== Break in While Loop ===" << endl;
    int counter = 0;
    while (true) {  // Infinite loop
        counter++;
        cout << counter << " ";
        if (counter == 5) {
            cout << "\nReached 5, breaking!" << endl;
            break;
        }
    }

    return 0;
}

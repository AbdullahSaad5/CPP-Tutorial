#include <iostream>
using namespace std;

int main() {
    cout << "Counting from 1 to 5:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    cout << "\nCountdown from 5 to 1:" << endl;
    for (int i = 5; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;

    cout << "\nEven numbers from 0 to 10:" << endl;
    for (int i = 0; i <= 10; i += 2) {
        cout << i << " ";
    }
    cout << endl;

    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "\nArray elements:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << ": " << numbers[i] << endl;
    }

    int num = 5;
    cout << "\nMultiplication table for " << num << ":" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << num << " x " << i << " = " << (num * i) << endl;
    }

    return 0;
}

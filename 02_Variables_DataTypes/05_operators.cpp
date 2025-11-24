#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 3;

    cout << "=== Arithmetic Operators ===" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "Addition: a + b = " << (a + b) << endl;
    cout << "Subtraction: a - b = " << (a - b) << endl;
    cout << "Multiplication: a * b = " << (a * b) << endl;
    cout << "Division: a / b = " << (a / b) << endl;
    cout << "Modulus: a % b = " << (a % b) << endl;

    cout << "\n=== Increment/Decrement ===" << endl;
    int x = 5;
    cout << "x = " << x << endl;
    cout << "x++ = " << x++ << " (x is now " << x << ")" << endl;
    cout << "++x = " << ++x << " (x is now " << x << ")" << endl;
    cout << "x-- = " << x-- << " (x is now " << x << ")" << endl;
    cout << "--x = " << --x << " (x is now " << x << ")" << endl;

    cout << "\n=== Compound Assignment ===" << endl;
    int num = 10;
    cout << "Starting value: " << num << endl;
    num += 5;
    cout << "After += 5: " << num << endl;
    num -= 3;
    cout << "After -= 3: " << num << endl;
    num *= 2;
    cout << "After *= 2: " << num << endl;
    num /= 4;
    cout << "After /= 4: " << num << endl;
    num %= 3;
    cout << "After %= 3: " << num << endl;

    return 0;
}

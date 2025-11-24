#include <iostream>
using namespace std;

int main() {
    cout << "=== Understanding Pointers ===" << endl;

    int number = 42;
    cout << "Value of number: " << number << endl;
    cout << "Address of number: " << &number << endl;

    int* ptr = &number;  // ptr points to number

    cout << "\n=== Pointer Basics ===" << endl;
    cout << "Value of ptr (address): " << ptr << endl;
    cout << "Value at address (*ptr): " << *ptr << endl;

    *ptr = 100;
    cout << "\nAfter *ptr = 100:" << endl;
    cout << "number is now: " << number << endl;

    cout << "\n=== Multiple Variables ===" << endl;
    int a = 10;
    int b = 20;

    int* p1 = &a;
    int* p2 = &b;

    cout << "a = " << *p1 << ", b = " << *p2 << endl;

    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << "After swap: a = " << a << ", b = " << b << endl;

    cout << "\n=== Null Pointer ===" << endl;
    int* nullPtr = nullptr;  // Modern C++ way

    if (nullPtr == nullptr) {
        cout << "Pointer is null (doesn't point to anything)" << endl;
    }

    return 0;
}

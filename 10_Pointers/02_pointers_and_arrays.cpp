#include <iostream>
using namespace std;

int main() {
    cout << "=== Pointers and Arrays ===" << endl;

    int numbers[] = {10, 20, 30, 40, 50};

    cout << "Array name (address): " << numbers << endl;
    cout << "First element: " << *numbers << endl;
    cout << "Address of first element: " << &numbers[0] << endl;

    int* ptr = numbers;

    cout << "\n=== Accessing Array Elements via Pointer ===" << endl;
    cout << "ptr[0] = " << ptr[0] << endl;
    cout << "ptr[1] = " << ptr[1] << endl;
    cout << "ptr[2] = " << ptr[2] << endl;

    cout << "\n=== Pointer Arithmetic ===" << endl;
    cout << "*ptr = " << *ptr << endl;         // First element
    cout << "*(ptr + 1) = " << *(ptr + 1) << endl;  // Second element
    cout << "*(ptr + 2) = " << *(ptr + 2) << endl;  // Third element

    cout << "\n=== Traversing Array ===" << endl;
    cout << "Using pointer arithmetic:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << ": " << *(ptr + i) << endl;
    }

    cout << "\n=== Incrementing Pointer ===" << endl;
    int* p = numbers;
    cout << "First element: " << *p << endl;
    p++;  // Move to next element
    cout << "Second element: " << *p << endl;
    p++;  // Move to next element
    cout << "Third element: " << *p << endl;

    cout << "\n=== Array Traversal with Pointer ===" << endl;
    int* arrayPtr = numbers;
    for (int i = 0; i < 5; i++) {
        cout << *arrayPtr << " ";
        arrayPtr++;
    }
    cout << endl;

    return 0;
}

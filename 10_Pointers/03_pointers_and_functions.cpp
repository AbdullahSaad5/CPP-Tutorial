#include <iostream>
using namespace std;

void incrementByValue(int x) {
    x = x + 1;
    cout << "Inside function (value): " << x << endl;
}

void incrementByPointer(int* x) {
    *x = *x + 1;
    cout << "Inside function (pointer): " << *x << endl;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void findMinMax(int arr[], int size, int* min, int* max) {
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

void doubleArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

int* getArrayElement(int arr[], int index) {
    return &arr[index];
}

int main() {
    cout << "=== Pass by Value vs Pass by Pointer ===" << endl;

    int num1 = 10;
    cout << "Before: " << num1 << endl;
    incrementByValue(num1);
    cout << "After: " << num1 << endl;  // Still 10

    cout << "\n";

    int num2 = 10;
    cout << "Before: " << num2 << endl;
    incrementByPointer(&num2);
    cout << "After: " << num2 << endl;  // Now 11

    cout << "\n=== Swap Function ===" << endl;
    int a = 5, b = 10;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swap(&a, &b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    cout << "\n=== Find Min and Max ===" << endl;
    int numbers[] = {5, 2, 8, 1, 9, 3, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int min, max;

    findMinMax(numbers, size, &min, &max);
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    cout << "Min: " << min << ", Max: " << max << endl;

    cout << "\n=== Double Array Values ===" << endl;
    int values[] = {1, 2, 3, 4, 5};
    int valSize = sizeof(values) / sizeof(values[0]);

    cout << "Before: ";
    for (int i = 0; i < valSize; i++) {
        cout << values[i] << " ";
    }
    cout << endl;

    doubleArray(values, valSize);

    cout << "After: ";
    for (int i = 0; i < valSize; i++) {
        cout << values[i] << " ";
    }
    cout << endl;

    cout << "\n=== Get Array Element ===" << endl;
    int* elementPtr = getArrayElement(values, 2);
    cout << "Element at index 2: " << *elementPtr << endl;

    return 0;
}

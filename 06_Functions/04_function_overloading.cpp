#include <iostream>
using namespace std;


int add(int a, int b) {
    cout << "Adding two integers" << endl;
    return a + b;
}

int add(int a, int b, int c) {
    cout << "Adding three integers" << endl;
    return a + b + c;
}

double add(double a, double b) {
    cout << "Adding two doubles" << endl;
    return a + b;
}

void print(int num) {
    cout << "Integer: " << num << endl;
}

void print(double num) {
    cout << "Double: " << num << endl;
}

void print(string text) {
    cout << "String: " << text << endl;
}

void print(char ch) {
    cout << "Character: " << ch << endl;
}

double area(double side) {
    return side * side;
}

double area(double length, double width) {
    return length * width;
}

double area(double base, double height, bool isTriangle) {
    return 0.5 * base * height;
}

int main() {
    cout << "=== Function Overloading - Add ===" << endl;
    cout << add(5, 3) << endl;
    cout << add(5, 3, 2) << endl;
    cout << add(5.5, 3.2) << endl;

    cout << "\n=== Function Overloading - Print ===" << endl;
    print(42);
    print(3.14);
    print("Hello");
    print('A');

    cout << "\n=== Function Overloading - Area ===" << endl;
    cout << "Square (side 5): " << area(5.0) << endl;
    cout << "Rectangle (5x3): " << area(5.0, 3.0) << endl;
    cout << "Triangle (base 4, height 3): " << area(4.0, 3.0, true) << endl;

    return 0;
}

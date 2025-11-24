#include <iostream>
using namespace std;

class Rectangle {
public:  // Public members can be accessed from outside
    int width;
    int height;

    int calculateArea() {
        return width * height;
    }

    int calculatePerimeter() {
        return 2 * (width + height);
    }

    void display() {
        cout << "Rectangle: " << width << " x " << height << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
    }
};

class Circle {
public:
    double radius;

    double calculateArea() {
        const double PI = 3.14159;
        return PI * radius * radius;
    }

    double calculateCircumference() {
        const double PI = 3.14159;
        return 2 * PI * radius;
    }

    void display() {
        cout << "Circle with radius: " << radius << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Circumference: " << calculateCircumference() << endl;
    }
};

int main() {
    cout << "=== Rectangle Class ===" << endl;

    Rectangle rect1;
    rect1.width = 10;
    rect1.height = 5;

    rect1.display();

    cout << "\n=== Another Rectangle ===" << endl;
    Rectangle rect2;
    rect2.width = 7;
    rect2.height = 3;

    cout << "Area: " << rect2.calculateArea() << endl;
    cout << "Perimeter: " << rect2.calculatePerimeter() << endl;

    cout << "\n=== Circle Class ===" << endl;
    Circle circle1;
    circle1.radius = 5.0;

    circle1.display();

    return 0;
}

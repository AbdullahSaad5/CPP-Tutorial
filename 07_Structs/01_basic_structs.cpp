#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
    int rollNumber;
    float gpa;
};

struct Point {
    int x;
    int y;
};

struct Rectangle {
    int width;
    int height;
};

int main() {
    cout << "=== Student Structure ===" << endl;

    Student student1;
    student1.name = "Alice";
    student1.age = 20;
    student1.rollNumber = 101;
    student1.gpa = 3.8;

    cout << "Student Information:" << endl;
    cout << "Name: " << student1.name << endl;
    cout << "Age: " << student1.age << endl;
    cout << "Roll Number: " << student1.rollNumber << endl;
    cout << "GPA: " << student1.gpa << endl;

    Student student2 = {"Bob", 21, 102, 3.6};

    cout << "\nStudent 2: " << student2.name << endl;
    cout << "GPA: " << student2.gpa << endl;

    cout << "\n=== Point Structure ===" << endl;
    Point p1 = {10, 20};
    Point p2 = {30, 40};

    cout << "Point 1: (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "Point 2: (" << p2.x << ", " << p2.y << ")" << endl;

    cout << "\n=== Rectangle Structure ===" << endl;
    Rectangle rect = {50, 30};

    cout << "Rectangle dimensions: " << rect.width << " x " << rect.height << endl;
    cout << "Area: " << (rect.width * rect.height) << endl;

    return 0;
}

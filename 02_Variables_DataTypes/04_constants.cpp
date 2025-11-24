#include <iostream>
using namespace std;

const double PI = 3.14159;

int main() {
    const int MAX_STUDENTS = 30;
    const string SCHOOL_NAME = "ABC University";
    const char GRADE_A = 'A';

    double radius = 5.0;
    double area = PI * radius * radius;
    double circumference = 2 * PI * radius;

    cout << "Circle with radius " << radius << ":" << endl;
    cout << "Area: " << area << endl;
    cout << "Circumference: " << circumference << endl;

    cout << "\nSchool Information:" << endl;
    cout << "Name: " << SCHOOL_NAME << endl;
    cout << "Maximum students per class: " << MAX_STUDENTS << endl;
    cout << "Top grade: " << GRADE_A << endl;

    return 0;
}

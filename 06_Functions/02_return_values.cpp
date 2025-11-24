#include <iostream>
using namespace std;

int square(int num) {
    return num * num;
}

double calculateCircleArea(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;
}

bool isEven(int num) {
    return num % 2 == 0;
}

int findMax(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

string getGrade(int score) {
    if (score >= 90) return "A";
    else if (score >= 80) return "B";
    else if (score >= 70) return "C";
    else if (score >= 60) return "D";
    else return "F";
}

int main() {
    cout << "=== Square Function ===" << endl;
    cout << "Square of 5: " << square(5) << endl;
    cout << "Square of 10: " << square(10) << endl;

    cout << "\n=== Circle Area ===" << endl;
    cout << "Area of circle (radius 5): " << calculateCircleArea(5.0) << endl;

    cout << "\n=== Even Number Checker ===" << endl;
    cout << "Is 10 even? " << (isEven(10) ? "Yes" : "No") << endl;
    cout << "Is 7 even? " << (isEven(7) ? "Yes" : "No") << endl;

    cout << "\n=== Maximum Finder ===" << endl;
    cout << "Max of 15 and 25: " << findMax(15, 25) << endl;

    cout << "\n=== Grade Calculator ===" << endl;
    cout << "Score 85 gets grade: " << getGrade(85) << endl;
    cout << "Score 72 gets grade: " << getGrade(72) << endl;

    return 0;
}

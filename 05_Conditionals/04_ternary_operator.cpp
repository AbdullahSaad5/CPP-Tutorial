#include <iostream>
using namespace std;

int main() {

    cout << "=== Basic Ternary ===" << endl;
    int age = 20;
    string status = (age >= 18) ? "Adult" : "Minor";
    cout << "Age: " << age << " -> Status: " << status << endl;

    string status2;
    if (age >= 18) {
        status2 = "Adult";
    } else {
        status2 = "Minor";
    }
    cout << "Same result with if-else: " << status2 << endl;

    cout << "\n=== Finding Maximum ===" << endl;
    int a = 15, b = 25;
    int max = (a > b) ? a : b;
    cout << "Max of " << a << " and " << b << " is: " << max << endl;

    int min = (a < b) ? a : b;
    cout << "Min of " << a << " and " << b << " is: " << min << endl;

    cout << "\n=== Even or Odd ===" << endl;
    int number = 7;
    string parity = (number % 2 == 0) ? "Even" : "Odd";
    cout << number << " is " << parity << endl;

    cout << "\n=== Nested Ternary ===" << endl;
    int score = 85;
    string grade = (score >= 90) ? "A" :
                   (score >= 80) ? "B" :
                   (score >= 70) ? "C" :
                   (score >= 60) ? "D" : "F";
    cout << "Score: " << score << " -> Grade: " << grade << endl;

    cout << "\n=== Ternary in Output ===" << endl;
    int temperature = 30;
    cout << "Temperature: " << temperature << " - ";
    cout << ((temperature > 25) ? "Hot" : "Cold") << endl;

    cout << "\n=== Absolute Value ===" << endl;
    int value = -42;
    int absolute = (value < 0) ? -value : value;
    cout << "Absolute value of " << value << " is " << absolute << endl;

    cout << "\n=== Plural Form ===" << endl;
    int apples = 1;
    cout << "You have " << apples << " apple" << ((apples != 1) ? "s" : "") << endl;

    apples = 5;
    cout << "You have " << apples << " apple" << ((apples != 1) ? "s" : "") << endl;

    return 0;
}

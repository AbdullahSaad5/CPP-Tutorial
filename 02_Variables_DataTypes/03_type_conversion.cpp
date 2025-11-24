#include <iostream>
using namespace std;

int main() {
    int intNum = 10;
    double doubleNum = intNum;
    cout << "Int to Double: " << doubleNum << endl;

    double pi = 3.14159;
    int truncatedPi = (int)pi;
    cout << "Double to Int (truncated): " << truncatedPi << endl;

    double price = 99.99;
    int dollars = static_cast<int>(price);
    cout << "Price: $" << price << " -> Dollars: $" << dollars << endl;

    char letter = 'A';
    int asciiValue = (int)letter;
    cout << "Character '" << letter << "' has ASCII value: " << asciiValue << endl;

    int number = 66;
    char character = (char)number;
    cout << "ASCII " << number << " is character: '" << character << "'" << endl;

    int a = 7;
    int b = 2;
    cout << "\nInteger division: " << a << " / " << b << " = " << (a / b) << endl;

    double c = 7.0;
    double d = 2.0;
    cout << "Floating division: " << c << " / " << d << " = " << (c / d) << endl;
    cout << "Mixed division: " << a << " / " << d << " = " << (a / d) << endl;

    return 0;
}

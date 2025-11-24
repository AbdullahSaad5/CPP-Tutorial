#include <iostream>
using namespace std;

int main() {
    short shortNum = 32000;
    int intNum = 2147483647;
    long longNum = 2147483647;
    long long bigNum = 9223372036854775807;
    unsigned int positiveOnly = 4294967295;

    cout << "=== Data Type Sizes ===" << endl;
    cout << "Size of short: " << sizeof(shortNum) << " bytes" << endl;
    cout << "Size of int: " << sizeof(intNum) << " bytes" << endl;
    cout << "Size of long: " << sizeof(longNum) << " bytes" << endl;
    cout << "Size of long long: " << sizeof(bigNum) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " bytes" << endl;
    cout << "Size of bool: " << sizeof(bool) << " bytes" << endl;

    cout << "\n=== Values ===" << endl;
    cout << "Short: " << shortNum << endl;
    cout << "Int: " << intNum << endl;
    cout << "Long: " << longNum << endl;
    cout << "Long Long: " << bigNum << endl;
    cout << "Unsigned Int: " << positiveOnly << endl;

    return 0;
}

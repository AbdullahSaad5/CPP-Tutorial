#include <iostream>
using namespace std;

void greet();
void greetPerson(string name);
int add(int a, int b);

int main() {
    cout << "=== Calling Functions ===" << endl;

    greet();
    greetPerson("Alice");
    greetPerson("Bob");

    int result = add(5, 3);
    cout << "5 + 3 = " << result << endl;

    int sum = add(10, 20);
    cout << "10 + 20 = " << sum << endl;

    return 0;
}

void greet() {
    cout << "Hello, World!" << endl;
}

void greetPerson(string name) {
    cout << "Hello, " << name << "!" << endl;
}

int add(int a, int b) {
    return a + b;
}

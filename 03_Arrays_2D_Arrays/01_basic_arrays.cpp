#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};

    cout << "First element: " << numbers[0] << endl;
    cout << "Second element: " << numbers[1] << endl;
    cout << "Last element: " << numbers[4] << endl;

    numbers[2] = 100;
    cout << "Modified third element: " << numbers[2] << endl;

    int scores[5] = {90, 85};  // Rest will be 0
    cout << "\nScores array:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Score[" << i << "] = " << scores[i] << endl;
    }

    string fruits[] = {"Apple", "Banana", "Orange", "Mango"};
    cout << "\nFruits:" << endl;
    cout << fruits[0] << endl;
    cout << fruits[1] << endl;
    cout << fruits[2] << endl;
    cout << fruits[3] << endl;

    int arraySize = sizeof(numbers) / sizeof(numbers[0]);
    cout << "\nArray size: " << arraySize << endl;

    return 0;
}

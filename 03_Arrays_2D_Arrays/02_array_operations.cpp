#include <iostream>
using namespace std;

int main() {
    int numbers[] = {5, 2, 8, 1, 9, 3, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    cout << "Maximum: " << max << endl;

    int min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    cout << "Minimum: " << min << endl;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    cout << "Sum: " << sum << endl;

    double average = (double)sum / size;
    cout << "Average: " << average << endl;

    int target = 8;
    bool found = false;
    int position = -1;

    for (int i = 0; i < size; i++) {
        if (numbers[i] == target) {
            found = true;
            position = i;
            break;
        }
    }

    if (found) {
        cout << "\nElement " << target << " found at index " << position << endl;
    } else {
        cout << "\nElement " << target << " not found" << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << "=== 2D Array (Matrix) ===" << endl;
    cout << "3 rows x 4 columns" << endl << endl;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cout << matrix[row][col] << "\t";
        }
        cout << endl;
    }

    cout << "\nElement at [0][0]: " << matrix[0][0] << endl;
    cout << "Element at [1][2]: " << matrix[1][2] << endl;
    cout << "Element at [2][3]: " << matrix[2][3] << endl;

    matrix[1][1] = 99;
    cout << "\nAfter modifying [1][1] to 99:" << endl;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cout << matrix[row][col] << "\t";
        }
        cout << endl;
    }

    return 0;
}

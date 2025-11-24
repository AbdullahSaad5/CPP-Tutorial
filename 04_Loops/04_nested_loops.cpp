#include <iostream>
using namespace std;

int main() {

    cout << "Rectangle (3x5):" << endl;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 5; col++) {
            cout << "* ";
        }
        cout << endl;
    }

    cout << "\nRight Triangle:" << endl;
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= row; col++) {
            cout << "* ";
        }
        cout << endl;
    }

    cout << "\nNumber Pattern:" << endl;
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= row; col++) {
            cout << col << " ";
        }
        cout << endl;
    }

    cout << "\nMultiplication Table (1-5):" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cout << (i * j) << "\t";
        }
        cout << endl;
    }

    cout << "\n2D Array Iteration:" << endl;
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

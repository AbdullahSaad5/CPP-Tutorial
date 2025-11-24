#include <iostream>
using namespace std;

int main() {
    const int ROWS = 3;
    const int COLS = 3;

    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int total = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            total += matrix[i][j];
        }
    }
    cout << "\nSum of all elements: " << total << endl;

    cout << "\nSum of each row:" << endl;
    for (int i = 0; i < ROWS; i++) {
        int rowSum = 0;
        for (int j = 0; j < COLS; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Row " << i << ": " << rowSum << endl;
    }

    cout << "\nSum of each column:" << endl;
    for (int j = 0; j < COLS; j++) {
        int colSum = 0;
        for (int i = 0; i < ROWS; i++) {
            colSum += matrix[i][j];
        }
        cout << "Column " << j << ": " << colSum << endl;
    }

    int diagonalSum = 0;
    for (int i = 0; i < ROWS; i++) {
        diagonalSum += matrix[i][i];
    }
    cout << "\nMain diagonal sum: " << diagonalSum << endl;

    int transpose[COLS][ROWS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:" << endl;
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

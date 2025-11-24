#include <iostream>
using namespace std;


int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    cout << "=== Tic-Tac-Toe Board Example ===" << endl;
    cout << "Empty board:" << endl;

    for (int row = 0; row < 3; row++) {
        cout << " ";
        for (int col = 0; col < 3; col++) {
            cout << board[row][col];
            if (col < 2) cout << " | ";
        }
        cout << endl;
        if (row < 2) cout << "---|---|---" << endl;
    }

    board[0][0] = 'X';  // X moves to top-left
    board[1][1] = 'O';  // O moves to center
    board[0][2] = 'X';  // X moves to top-right
    board[2][0] = 'O';  // O moves to bottom-left
    board[0][1] = 'X';  // X moves to top-center (X wins!)

    cout << "\n\nAfter some moves:" << endl;
    for (int row = 0; row < 3; row++) {
        cout << " ";
        for (int col = 0; col < 3; col++) {
            cout << board[row][col];
            if (col < 2) cout << " | ";
        }
        cout << endl;
        if (row < 2) cout << "---|---|---" << endl;
    }

    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') {
        cout << "\nX wins on the top row!" << endl;
    }

    return 0;
}

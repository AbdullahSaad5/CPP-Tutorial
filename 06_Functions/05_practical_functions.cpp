#include <iostream>
using namespace std;


void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---|---|---" << endl;
    }
    cout << endl;
}

bool isValidMove(char board[3][3], int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return false;  // Out of bounds
    }
    return board[row][col] == ' ';  // Empty position
}

void placeMove(char board[3][3], int row, int col, char player) {
    board[row][col] = player;
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

int factorial(int n) {
    if (n <= 1) return 1;
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    cout << "=== Tic-Tac-Toe Functions Demo ===" << endl;

    char board[3][3];
    initializeBoard(board);

    cout << "Initial board:";
    displayBoard(board);

    placeMove(board, 0, 0, 'X');
    placeMove(board, 1, 1, 'O');
    placeMove(board, 0, 2, 'X');

    cout << "After some moves:";
    displayBoard(board);

    cout << "Is position (0,1) valid? " << (isValidMove(board, 0, 1) ? "Yes" : "No") << endl;
    cout << "Is position (0,0) valid? " << (isValidMove(board, 0, 0) ? "Yes" : "No") << endl;

    cout << "Is board full? " << (isBoardFull(board) ? "Yes" : "No") << endl;

    char player = 'X';
    cout << "Current player: " << player << endl;
    player = switchPlayer(player);
    cout << "Next player: " << player << endl;

    cout << "\n=== Other Useful Functions ===" << endl;
    cout << "Factorial of 5: " << factorial(5) << endl;
    cout << "Is 17 prime? " << (isPrime(17) ? "Yes" : "No") << endl;
    cout << "Is 18 prime? " << (isPrime(18) ? "Yes" : "No") << endl;

    return 0;
}

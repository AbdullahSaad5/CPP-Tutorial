#include <iostream>
using namespace std;


enum GameResult {
    IN_PROGRESS,
    PLAYER_X_WINS,
    PLAYER_O_WINS,
    DRAW
};

enum CellState {
    EMPTY,
    X,
    O
};

enum MoveValidation {
    VALID,
    OUT_OF_BOUNDS,
    ALREADY_OCCUPIED
};

char cellStateToChar(CellState state) {
    switch (state) {
        case EMPTY: return ' ';
        case X: return 'X';
        case O: return 'O';
    }
    return ' ';
}

CellState charToCellState(char c) {
    switch (c) {
        case 'X': return X;
        case 'O': return O;
        default: return EMPTY;
    }
}

string getGameResultMessage(GameResult result) {
    switch (result) {
        case IN_PROGRESS: return "Game is still in progress";
        case PLAYER_X_WINS: return "Player X wins!";
        case PLAYER_O_WINS: return "Player O wins!";
        case DRAW: return "It's a draw!";
    }
    return "Unknown";
}

string getMoveValidationMessage(MoveValidation validation) {
    switch (validation) {
        case VALID: return "Move is valid";
        case OUT_OF_BOUNDS: return "Move out of bounds!";
        case ALREADY_OCCUPIED: return "Position already occupied!";
    }
    return "Unknown";
}

MoveValidation validateMove(CellState board[3][3], int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return OUT_OF_BOUNDS;
    }
    if (board[row][col] != EMPTY) {
        return ALREADY_OCCUPIED;
    }
    return VALID;
}

void displayBoard(CellState board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << cellStateToChar(board[i][j]);
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---|---|---" << endl;
    }
    cout << endl;
}

GameResult checkGameResult(CellState board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != EMPTY &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            return (board[i][0] == X) ? PLAYER_X_WINS : PLAYER_O_WINS;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] != EMPTY &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j]) {
            return (board[0][j] == X) ? PLAYER_X_WINS : PLAYER_O_WINS;
        }
    }

    if (board[0][0] != EMPTY &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return (board[0][0] == X) ? PLAYER_X_WINS : PLAYER_O_WINS;
    }
    if (board[0][2] != EMPTY &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return (board[0][2] == X) ? PLAYER_X_WINS : PLAYER_O_WINS;
    }

    bool isFull = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                isFull = false;
                break;
            }
        }
    }

    return isFull ? DRAW : IN_PROGRESS;
}

int main() {
    cout << "=== Tic-Tac-Toe with Enumerations ===" << endl;

    CellState board[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = EMPTY;
        }
    }

    cout << "Initial board:";
    displayBoard(board);

    cout << "=== Simulating Game ===" << endl;

    MoveValidation validation = validateMove(board, 0, 0);
    cout << "\nPlayer X attempts move at (0,0): " << getMoveValidationMessage(validation) << endl;
    if (validation == VALID) {
        board[0][0] = X;
    }

    validation = validateMove(board, 1, 1);
    cout << "Player O attempts move at (1,1): " << getMoveValidationMessage(validation) << endl;
    if (validation == VALID) {
        board[1][1] = O;
    }

    validation = validateMove(board, 0, 1);
    cout << "Player X attempts move at (0,1): " << getMoveValidationMessage(validation) << endl;
    if (validation == VALID) {
        board[0][1] = X;
    }

    validation = validateMove(board, 2, 0);
    cout << "Player O attempts move at (2,0): " << getMoveValidationMessage(validation) << endl;
    if (validation == VALID) {
        board[2][0] = O;
    }

    validation = validateMove(board, 0, 2);
    cout << "Player X attempts move at (0,2): " << getMoveValidationMessage(validation) << endl;
    if (validation == VALID) {
        board[0][2] = X;
    }

    cout << "\nCurrent board:";
    displayBoard(board);

    GameResult result = checkGameResult(board);
    cout << "Game Status: " << getGameResultMessage(result) << endl;

    cout << "\n=== Testing Invalid Move ===" << endl;
    validation = validateMove(board, 0, 0);  // Already occupied
    cout << "Attempting move at (0,0): " << getMoveValidationMessage(validation) << endl;

    validation = validateMove(board, 5, 5);  // Out of bounds
    cout << "Attempting move at (5,5): " << getMoveValidationMessage(validation) << endl;

    return 0;
}

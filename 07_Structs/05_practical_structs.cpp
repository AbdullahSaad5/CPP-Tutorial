#include <iostream>
using namespace std;


struct Position {
    int row;
    int col;
};

struct Move {
    Position position;
    char player;
    bool isValid;
};

struct Player {
    char symbol;      // 'X' or 'O'
    string name;
    int wins;
    int losses;
    int draws;
};

struct GameBoard {
    char grid[3][3];
    int emptyCells;
};

void initBoard(GameBoard &board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board.grid[i][j] = ' ';
        }
    }
    board.emptyCells = 9;
}

void displayBoard(GameBoard board) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board.grid[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---|---|---" << endl;
    }
    cout << endl;
}

Move makeMove(GameBoard &board, Position pos, char player) {
    Move move;
    move.position = pos;
    move.player = player;

    if (pos.row >= 0 && pos.row < 3 && pos.col >= 0 && pos.col < 3) {
        if (board.grid[pos.row][pos.col] == ' ') {
            board.grid[pos.row][pos.col] = player;
            board.emptyCells--;
            move.isValid = true;
        } else {
            move.isValid = false;
        }
    } else {
        move.isValid = false;
    }

    return move;
}

void displayPlayerStats(Player p) {
    cout << "\n=== " << p.name << " (Player " << p.symbol << ") ===" << endl;
    cout << "Wins: " << p.wins << endl;
    cout << "Losses: " << p.losses << endl;
    cout << "Draws: " << p.draws << endl;
    int totalGames = p.wins + p.losses + p.draws;
    if (totalGames > 0) {
        float winRate = (float)p.wins / totalGames * 100;
        cout << "Win Rate: " << winRate << "%" << endl;
    }
}

int main() {
    cout << "=== Tic-Tac-Toe with Structs ===" << endl;

    Player player1 = {'X', "Alice", 5, 2, 1};
    Player player2 = {'O', "Bob", 3, 4, 1};

    displayPlayerStats(player1);
    displayPlayerStats(player2);

    GameBoard board;
    initBoard(board);

    cout << "\n=== Starting New Game ===" << endl;
    cout << "Initial board:";
    displayBoard(board);

    Position pos1 = {0, 0};
    Move move1 = makeMove(board, pos1, player1.symbol);

    if (move1.isValid) {
        cout << player1.name << " placed " << move1.player
             << " at (" << move1.position.row << ", "
             << move1.position.col << ")" << endl;
    }

    Position pos2 = {1, 1};
    Move move2 = makeMove(board, pos2, player2.symbol);

    if (move2.isValid) {
        cout << player2.name << " placed " << move2.player
             << " at (" << move2.position.row << ", "
             << move2.position.col << ")" << endl;
    }

    Position pos3 = {0, 2};
    Move move3 = makeMove(board, pos3, player1.symbol);

    if (move3.isValid) {
        cout << player1.name << " placed " << move3.player
             << " at (" << move3.position.row << ", "
             << move3.position.col << ")" << endl;
    }

    cout << "\nCurrent board:";
    displayBoard(board);

    cout << "Empty cells remaining: " << board.emptyCells << endl;

    cout << "\n=== Testing Invalid Move ===" << endl;
    Position invalidPos = {0, 0};  // Already occupied
    Move invalidMove = makeMove(board, invalidPos, player2.symbol);

    if (!invalidMove.isValid) {
        cout << "Invalid move! Position already occupied." << endl;
    }

    return 0;
}

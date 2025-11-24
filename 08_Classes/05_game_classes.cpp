#include <iostream>
using namespace std;


class Player {
private:
    string name;
    char symbol;
    int score;

public:
    Player() {
        name = "Player";
        symbol = 'X';
        score = 0;
    }

    Player(string n, char s) {
        name = n;
        symbol = s;
        score = 0;
    }

    string getName() {
        return name;
    }

    char getSymbol() {
        return symbol;
    }

    int getScore() {
        return score;
    }

    void incrementScore() {
        score++;
    }

    void displayInfo() {
        cout << name << " (Player " << symbol << ") - Score: " << score << endl;
    }
};

class Board {
private:
    char grid[3][3];
    int moveCount;

public:
    Board() {
        initializeBoard();
    }

    void initializeBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = ' ';
            }
        }
        moveCount = 0;
    }

    void display() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << " ";
            for (int j = 0; j < 3; j++) {
                cout << grid[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "---|---|---" << endl;
        }
        cout << endl;
    }

    bool isValidMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            return false;
        }
        return grid[row][col] == ' ';
    }

    void placeMove(int row, int col, char symbol) {
        if (isValidMove(row, col)) {
            grid[row][col] = symbol;
            moveCount++;
        }
    }

    bool isFull() {
        return moveCount >= 9;
    }

    char checkWinner() {
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] != ' ' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
                return grid[i][0];
            }
        }

        for (int j = 0; j < 3; j++) {
            if (grid[0][j] != ' ' && grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]) {
                return grid[0][j];
            }
        }

        if (grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
            return grid[0][0];
        }
        if (grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
            return grid[0][2];
        }

        return ' ';  // No winner
    }

    int getMoveCount() {
        return moveCount;
    }
};

class Game {
private:
    Board board;
    Player player1;
    Player player2;
    Player* currentPlayer;

public:
    Game(string name1, string name2) : player1(name1, 'X'), player2(name2, 'O') {
        currentPlayer = &player1;
    }

    void displayStatus() {
        cout << "\n=== Game Status ===" << endl;
        player1.displayInfo();
        player2.displayInfo();
        board.display();
        cout << "Current turn: " << currentPlayer->getName() << endl;
    }

    void switchPlayer() {
        if (currentPlayer == &player1) {
            currentPlayer = &player2;
        } else {
            currentPlayer = &player1;
        }
    }

    bool makeMove(int row, int col) {
        if (board.isValidMove(row, col)) {
            board.placeMove(row, col, currentPlayer->getSymbol());
            return true;
        }
        return false;
    }

    char checkGameStatus() {
        return board.checkWinner();
    }

    bool isBoardFull() {
        return board.isFull();
    }

    void resetBoard() {
        board.initializeBoard();
        currentPlayer = &player1;
    }

    string getCurrentPlayerName() {
        return currentPlayer->getName();
    }

    void incrementCurrentPlayerScore() {
        currentPlayer->incrementScore();
    }
};

int main() {
    cout << "=== Tic-Tac-Toe Game Classes Demo ===" << endl;

    Game game("Alice", "Bob");

    game.displayStatus();

    cout << "\n=== Making Moves ===" << endl;

    game.makeMove(0, 0);
    cout << "Alice placed X at (0,0)" << endl;
    game.switchPlayer();

    game.makeMove(1, 1);
    cout << "Bob placed O at (1,1)" << endl;
    game.switchPlayer();

    game.makeMove(0, 1);
    cout << "Alice placed X at (0,1)" << endl;
    game.switchPlayer();

    game.makeMove(2, 0);
    cout << "Bob placed O at (2,0)" << endl;
    game.switchPlayer();

    game.makeMove(0, 2);
    cout << "Alice placed X at (0,2)" << endl;

    game.displayStatus();

    char winner = game.checkGameStatus();
    if (winner != ' ') {
        cout << "\nPlayer " << winner << " wins!" << endl;
        game.incrementCurrentPlayerScore();
    } else if (game.isBoardFull()) {
        cout << "\nIt's a draw!" << endl;
    }

    return 0;
}

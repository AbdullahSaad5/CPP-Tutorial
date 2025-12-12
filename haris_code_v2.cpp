#include <iostream>
using namespace std;
void clearBoard(char board[10][10])
 {
    for (int r = 0; r < 10; r++)
	 {
        for (int c = 0; c < 10; c++)
		 {
            board[r][c] = '~';
        }
    }
}

void printBoard(char board[10][10], bool hideShips) {
    cout << "   ";
    for (int c = 0; c < 10; c++) cout << c << " ";
    cout << endl;

    for (int r = 0; r < 10; r++)
	 {
        cout << r << "  ";
        for (int c = 0; c < 10; c++) {
            if (hideShips && board[r][c] == 'S')
                cout << "~ ";
            else
                cout << board[r][c] << " ";
        }
        cout << endl;
    }
}

bool canPlaceShip(char board[10][10], int row, int col, int size, char dir) {
    if (dir == 'H') {
        if (col + size > 10) return false;
        for (int i = 0; i < size; i++) {
            if (board[row][col + i] == 'S') return false;
        }
    } 
    else if (dir == 'V') {
        if (row + size > 10) return false;
        for (int i = 0; i < size; i++) {
            if (board[row + i][col] == 'S') return false;
        }
    }
    return true;
}

void placeShipsManually(char board[10][10]) {
    int shipSizes[5] = {5, 4, 3, 3, 2};

    cout << "\nPlace your ships on the grid.\n";
    cout << "(H for Horizontal, V for Vertical)\n\n";

    for (int i = 0; i < 5; i++) {
        int size = shipSizes[i];
        int row, col;
        char direction;

        while (true) {
            cout << "\nShip size " << size << endl;
            cout << "Enter row: ";
            cin >> row;
            cout << "Enter col: ";
            cin >> col;
            cout << "Direction (H/V): ";
            cin >> direction;

            if (direction != 'H' && direction != 'V')
			 {
                cout << "Invalid direction! Try again.\n";
                continue;
            }

            if (row < 0 || row > 9 || col < 0 || col > 9)
			 {
                cout << "Invalid location! Try again.\n";
                continue;
            }

            if (canPlaceShip(board, row, col, size, direction))
			 {
                if (direction == 'H') {
                    for (int j = 0; j < size; j++)
                        board[row][col + j] = 'S';
                } else {
                    for (int j = 0; j < size; j++)
                        board[row + j][col] = 'S';
                }
                break;
            } else {
                cout << "Cannot place ship here. Try another location.\n";
            }
        }

        printBoard(board, false);
    }
}

void updateScore(int &score) 
{
    score += 10;
}

void playerAttack(char opponentBoard[10][10], int &playerScore) {
    int r, c;

    while (true) {
        cout << "\nEnter attack row: ";
        cin >> r;
        cout << "Enter attack col: ";
        cin >> c;

        if (r < 0 || r > 9 || c < 0 || c > 9)
		 {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        if (opponentBoard[r][c] == 'X' || opponentBoard[r][c] == 'O') {
            cout << "You already attacked here! Try again.\n";
            continue;
        }

        if (opponentBoard[r][c] == 'S') {
            cout << "Hit!\n";
            opponentBoard[r][c] = 'X';
            updateScore(playerScore);
        } else {
            cout << "Miss.\n";
            opponentBoard[r][c] = 'O';
            playerScore -= 1;
        }
        break;
    }
}

void displayResult(int s1, int s2)
 {
    cout << "\n----- FINAL RESULT -----\n";
    cout << "Player 1 Score: " << s1 << endl;
    cout << "Player 2 Score: " << s2 << endl;

    if (s1 > s2) cout << "Player 1 Wins!\n";
    else if (s2 > s1) cout << "Player 2 Wins!\n";
    else cout << "It's a Draw!\n";
}

void vsPlayer(char board1[10][10], char board2[10][10]) {
    int p1Score = 0, p2Score = 0;

    cout << "\n--- PLAYER 1 SET SHIPS ---\n";
    placeShipsManually(board1);

    cout << "\n--- PLAYER 2 SET SHIPS ---\n";
    placeShipsManually(board2);

    cout << "\n--- GAME START ---\n";

    while (true) {
        cout << "\n--- Player 1 Turn ---\n";
        playerAttack(board2, p1Score);

        cout << "\n--- Player 2 Turn ---\n";
        playerAttack(board1, p2Score);
        bool p1Done = true, p2Done = true;

        for (int r = 0; r < 10; r++)
            for (int c = 0; c < 10; c++) {
                if (board1[r][c] == 'S') p1Done = false;
                if (board2[r][c] == 'S') p2Done = false;
            }

        if (p1Done || p2Done) break;
    }

    displayResult(p1Score, p2Score);
}

void showGameMenu() {
    char b1[10][10], b2[10][10];
    clearBoard(b1);
    clearBoard(b2);

    int choice;

    while (true) {
        cout << "\n===== BATTLESHIP MENU =====\n";
        cout << "1. Player vs Player\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            vsPlayer(b1, b2);
        } 
        else if (choice == 2) {
            cout << "Goodbye!\n";
            break;
        } 
        else {
            cout << "Invalid option!\n";
        }
    }
}

int main() {
    showGameMenu();
    return 0;
}


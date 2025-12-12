#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int BOARD_SIZE = 10;
const int SHIP_COUNT = 5;

int shipSizes[SHIP_COUNT] = {2, 3, 3, 4, 5};
char shipSymbols[SHIP_COUNT] = {'P', 'S', 'D', 'B', 'A'};
string shipNames[SHIP_COUNT] = {
    "Patrol Boat", "Submarine", "Destroyer", "Battleship", "Aircraft Carrier"
};

vector<pair<string, int>> leaderboard;

void clearScreen() {
    system("cls");
}

void showMainMenu() {
    cout << "\nBATTLESHIP MAIN MENU\n";
    cout << "1. Practice Ship Placement\n";
    cout << "2. Player vs Player Game\n";
    cout << "3. Game Instructions\n";
    cout << "4. View Leaderboard\n";
    cout << "5. Exit Game\n";
}

void showInstructions() {
    clearScreen();
    cout << "BATTLESHIP INSTRUCTIONS\n\n";

    cout << "OBJECTIVE: Destroy all enemy ships\n\n";

    cout << "SHIP PLACEMENT:\n";
    cout << "- Place 5 ships on 10x10 grid\n";
    cout << "- Ships can be H or V\n";
    cout << "- No overlap, stay inside grid\n\n";

    cout << "SHIPS AVAILABLE:\n";
    for (int i = 0; i < SHIP_COUNT; i++) {
        cout << i+1 << ". " << shipNames[i] << " (Size " << shipSizes[i] << ")\n";
    }
    cout << "\n";

    cout << "GAMEPLAY:\n";
    cout << "- Take turns attacking\n";
    cout << "- Enter like 'A5' or 'H10'\n";
    cout << "- X = Hit, O = Miss\n\n";

    cout << "SCORING:\n";
    cout << "+10 points for Hit\n";
    cout << "-1 point for Miss\n";
}

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '~';
        }
    }
}

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE], bool showShips = true) {
    cout << "   ";
    for (int j = 0; j < BOARD_SIZE; j++) {
        cout << setw(2) << j+1 << " ";
    }
    cout << "\n";

    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << char('A' + i) << "  ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            char cell = board[i][j];

            if (!showShips && cell >= 'A' && cell <= 'Z' && cell != 'X' && cell != 'O') {
                cout << "~  ";
            } else {
                cout << cell << "  ";
            }
        }
        cout << "\n";
    }
}

bool isValidPlacement(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, int shipSize, char orientation) {
    if (orientation == 'H') {
        if (col + shipSize > BOARD_SIZE) return false;
        for (int i = 0; i < shipSize; i++) {
            if (board[row][col + i] != '~') return false;
        }
    } else {
        if (row + shipSize > BOARD_SIZE) return false;
        for (int i = 0; i < shipSize; i++) {
            if (board[row + i][col] != '~') return false;
        }
    }
    return true;
}

void markShipOnBoard(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, int shipSize, char orientation, char symbol) {
    if (orientation == 'H') {
        for (int i = 0; i < shipSize; i++) {
            board[row][col + i] = symbol;
        }
    } else {
        for (int i = 0; i < shipSize; i++) {
            board[row + i][col] = symbol;
        }
    }
}

bool placeSingleShip(char board[BOARD_SIZE][BOARD_SIZE], int shipIndex, string playerName) {
    char orientation;
    char rowLetter;
    int colNumber;

    cout << "\nPlacing: " << shipNames[shipIndex] << " (Size: " << shipSizes[shipIndex] << ")\n";

    cout << "Enter starting row (A-J): ";
    cin >> rowLetter;
    rowLetter = toupper(rowLetter);

    cout << "Enter starting column (1-10): ";
    cin >> colNumber;

    int row = rowLetter - 'A';
    int col = colNumber - 1;

    if (row < 0 || row >= BOARD_SIZE) {
        cout << "ERROR: Row must be A-J\n";
        return false;
    }

    if (col < 0 || col >= BOARD_SIZE) {
        cout << "ERROR: Column must be 1-10\n";
        return false;
    }

    cout << "Place horizontally (H) or vertically (V)? ";
    cin >> orientation;
    orientation = toupper(orientation);

    if (orientation != 'H' && orientation != 'V') {
        cout << "ERROR: Enter H or V\n";
        return false;
    }

    if (!isValidPlacement(board, row, col, shipSizes[shipIndex], orientation)) {
        cout << "ERROR: Invalid placement\n";
        return false;
    }

    markShipOnBoard(board, row, col, shipSizes[shipIndex], orientation, shipSymbols[shipIndex]);

    cout << "\n" << shipNames[shipIndex] << " placed!\n";
    cout << "\nUpdated Board:\n";
    displayBoard(board);

    return true;
}

bool placeAllShips(char board[BOARD_SIZE][BOARD_SIZE], string playerName) {
    bool shipsPlaced[SHIP_COUNT] = {false};
    int placedCount = 0;

    cout << "\n" << playerName << ", place " << SHIP_COUNT << " ships.\n";

    while (placedCount < SHIP_COUNT) {
        clearScreen();
        cout << "SHIP PLACEMENT - " << playerName << "\n\n";

        cout << "Current Board:\n";
        displayBoard(board);

        cout << "\nAVAILABLE SHIPS:\n";
        for (int i = 0; i < SHIP_COUNT; i++) {
            if (!shipsPlaced[i]) {
                cout << i+1 << ". " << shipNames[i] << " (Size: " << shipSizes[i] << ")\n";
            }
        }

        int shipChoice;
        cout << "\nSelect ship number (1-" << SHIP_COUNT << "): ";
        cin >> shipChoice;

        if (shipChoice < 1 || shipChoice > SHIP_COUNT) {
            cout << "Invalid choice\n";
            continue;
        }

        int shipIndex = shipChoice - 1;

        if (shipsPlaced[shipIndex]) {
            cout << "Ship already placed\n";
            continue;
        }

        if (placeSingleShip(board, shipIndex, playerName)) {
            shipsPlaced[shipIndex] = true;
            placedCount++;
        }

        if (placedCount < SHIP_COUNT) {
            cout << "\nPress Enter for next ship...";
            cin.ignore();
            cin.get();
        }
    }

    return true;
}

void runSinglePlayerShipPlacement() {
    clearScreen();
    cout << "SINGLE PLAYER SHIP PLACEMENT\n\n";

    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    string playerName;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, playerName);

    if (placeAllShips(board, playerName)) {
        cout << "\nALL SHIPS PLACED!\n\n";
        cout << "Final board:\n";
        displayBoard(board);
    }
}

void loadLeaderboard() {
    ifstream file("battleship_scores.txt");
    if (file.is_open()) {
        string name;
        int score;
        while (file >> name >> score) {
            leaderboard.push_back(make_pair(name, score));
        }
        file.close();

        sort(leaderboard.begin(), leaderboard.end(),
            [](pair<string, int> a, pair<string, int> b) {
                return a.second > b.second;
            });
    }
}

void showLeaderboard() {
    clearScreen();
    cout << "TOP 10 SCORES\n\n";

    if (leaderboard.empty()) {
        cout << "No scores yet\n";
        return;
    }

    cout << "Rank  Player            Score\n";
    cout << "----  ------------      -----\n";

    int displayCount = min(10, (int)leaderboard.size());
    for (int i = 0; i < displayCount; i++) {
        cout << setw(4) << i+1 << ". "
             << setw(16) << left << leaderboard[i].first
             << setw(8) << right << leaderboard[i].second << "\n";
    }
}

bool isValidAttack(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return false;
    }
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }
    return true;
}

void processAttack(char board[BOARD_SIZE][BOARD_SIZE], string attackerName, int &score) {
    char rowLetter;
    int colNumber;
    bool validAttack = false;

    while (!validAttack) {
        cout << "\n" << attackerName << ", enter attack (e.g., B5): ";
        cin >> rowLetter >> colNumber;

        int row = toupper(rowLetter) - 'A';
        int col = colNumber - 1;

        if (isValidAttack(board, row, col)) {
            validAttack = true;

            if (board[row][col] != '~') {
                cout << "HIT! +10 points\n";
                board[row][col] = 'X';
                score += 10;
            } else {
                cout << "MISS! -1 point\n";
                board[row][col] = 'O';
                score -= 1;
            }
        } else {
            cout << "Invalid attack\n";
        }
    }
}

void runGameplay(char player1Board[BOARD_SIZE][BOARD_SIZE], char player2Board[BOARD_SIZE][BOARD_SIZE],
                 string player1Name, string player2Name) {
    clearScreen();
    cout << "BATTLE BEGINS!\n\n";

    int player1Score = 0;
    int player2Score = 0;
    bool player1Turn = true;

    char player1View[BOARD_SIZE][BOARD_SIZE];
    char player2View[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(player1View);
    initializeBoard(player2View);

    while (true) {
        clearScreen();
        cout << player1Name << " Score: " << player1Score << " | "
             << player2Name << " Score: " << player2Score << "\n\n";

        if (player1Turn) {
            cout << player1Name << "'s Turn\n";
            cout << "View of " << player2Name << "'s board:\n";
            displayBoard(player2View, false);

            processAttack(player2Board, player1Name, player1Score);

            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (player2Board[i][j] == 'X' || player2Board[i][j] == 'O') {
                        player2View[i][j] = player2Board[i][j];
                    }
                }
            }

            player1Turn = false;
        } else {
            cout << player2Name << "'s Turn\n";
            cout << "View of " << player1Name << "'s board:\n";
            displayBoard(player1View, false);

            processAttack(player1Board, player2Name, player2Score);

            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (player1Board[i][j] == 'X' || player1Board[i][j] == 'O') {
                        player1View[i][j] = player1Board[i][j];
                    }
                }
            }

            player1Turn = true;
        }

        bool p1HasShips = false;
        bool p2HasShips = false;

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (player1Board[i][j] >= 'A' && player1Board[i][j] <= 'Z') p1HasShips = true;
                if (player2Board[i][j] >= 'A' && player2Board[i][j] <= 'Z') p2HasShips = true;
            }
        }

        if (!p1HasShips || !p2HasShips) break;

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

    clearScreen();
    cout << "GAME OVER!\n\n";
    cout << "FINAL SCORES:\n";
    cout << player1Name << ": " << player1Score << "\n";
    cout << player2Name << ": " << player2Score << "\n\n";

    ofstream file("battleship_scores.txt", ios::app);
    if (file.is_open()) {
        file << player1Name << " " << player1Score << endl;
        file << player2Name << " " << player2Score << endl;
        file.close();
    }

    if (player1Score > player2Score) {
        cout << "WINNER: " << player1Name << "!\n";
    } else if (player2Score > player1Score) {
        cout << "WINNER: " << player2Name << "!\n";
    } else {
        cout << "IT'S A TIE!\n";
    }
}

void runPlayerVsPlayerGame() {
    clearScreen();
    cout << "PLAYER VS PLAYER GAME\n\n";

    char player1Board[BOARD_SIZE][BOARD_SIZE];
    char player2Board[BOARD_SIZE][BOARD_SIZE];
    string player1Name, player2Name;

    cout << "Enter Player 1 name: ";
    cin.ignore();
    getline(cin, player1Name);

    cout << "Enter Player 2 name: ";
    getline(cin, player2Name);

    clearScreen();
    cout << player1Name << ", place your ships\n";
    initializeBoard(player1Board);
    placeAllShips(player1Board, player1Name);

    clearScreen();
    cout << player2Name << ", place your ships\n";
    initializeBoard(player2Board);
    placeAllShips(player2Board, player2Name);

    runGameplay(player1Board, player2Board, player1Name, player2Name);
}

int main() {
    clearScreen();

    cout << "BATTLESHIP GAME\n\n";

    loadLeaderboard();

    int choice;
    bool exitGame = false;

    srand(time(0));

    do {
        showMainMenu();
        cout << "\nEnter choice (1-5): ";
        cin >> choice;

        switch(choice) {
            case 1:
                runSinglePlayerShipPlacement();
                break;
            case 2:
                runPlayerVsPlayerGame();
                break;
            case 3:
                showInstructions();
                break;
            case 4:
                showLeaderboard();
                break;
            case 5:
                exitGame = true;
                cout << "\nThanks for playing!\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

        if (!exitGame) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            clearScreen();
        }

    } while (!exitGame);

    return 0;
}

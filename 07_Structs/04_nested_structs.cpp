#include <iostream>
using namespace std;


struct Date {
    int day;
    int month;
    int year;
};

struct Address {
    string street;
    string city;
    string state;
    int zipCode;
};

struct Person {
    string name;
    int age;
    Date birthDate;    // Nested struct
    Address address;   // Nested struct
};

struct GameMove {
    int row;
    int col;
    char player;
};

struct GameState {
    char board[3][3];
    char currentPlayer;
    int moveCount;
    GameMove lastMove;  // Nested struct
};

int main() {
    cout << "=== Person with Nested Structs ===" << endl;

    Person person1;
    person1.name = "John Doe";
    person1.age = 25;

    person1.birthDate.day = 15;
    person1.birthDate.month = 6;
    person1.birthDate.year = 1998;

    person1.address.street = "123 Main St";
    person1.address.city = "Springfield";
    person1.address.state = "IL";
    person1.address.zipCode = 62701;

    cout << "Name: " << person1.name << endl;
    cout << "Age: " << person1.age << endl;
    cout << "Birth Date: " << person1.birthDate.day << "/"
         << person1.birthDate.month << "/"
         << person1.birthDate.year << endl;
    cout << "Address: " << person1.address.street << ", "
         << person1.address.city << ", "
         << person1.address.state << " "
         << person1.address.zipCode << endl;

    Person person2 = {
        "Jane Smith",
        30,
        {20, 3, 1993},  // Birth date
        {"456 Oak Ave", "Portland", "OR", 97201}  // Address
    };

    cout << "\nPerson 2: " << person2.name << endl;
    cout << "City: " << person2.address.city << endl;

    cout << "\n=== Game State Structure ===" << endl;

    GameState game;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game.board[i][j] = ' ';
        }
    }

    game.currentPlayer = 'X';
    game.moveCount = 0;

    game.board[0][0] = 'X';
    game.lastMove.row = 0;
    game.lastMove.col = 0;
    game.lastMove.player = 'X';
    game.moveCount = 1;

    cout << "Current Player: " << game.currentPlayer << endl;
    cout << "Move Count: " << game.moveCount << endl;
    cout << "Last Move: Player " << game.lastMove.player
         << " at position (" << game.lastMove.row << ", "
         << game.lastMove.col << ")" << endl;

    return 0;
}

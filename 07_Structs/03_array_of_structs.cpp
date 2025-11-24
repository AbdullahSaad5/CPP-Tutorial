#include <iostream>
using namespace std;

struct Player {
    string name;
    int score;
    int level;
};

struct Product {
    int id;
    string name;
    float price;
    int quantity;
};

int main() {
    cout << "=== Array of Players ===" << endl;

    Player players[3] = {
        {"Alice", 1500, 10},
        {"Bob", 1200, 8},
        {"Charlie", 1800, 12}
    };

    cout << "Player Leaderboard:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << (i + 1) << ". " << players[i].name;
        cout << " - Score: " << players[i].score;
        cout << " - Level: " << players[i].level << endl;
    }

    int highestScore = players[0].score;
    string topPlayer = players[0].name;

    for (int i = 1; i < 3; i++) {
        if (players[i].score > highestScore) {
            highestScore = players[i].score;
            topPlayer = players[i].name;
        }
    }

    cout << "\nTop player: " << topPlayer << " with " << highestScore << " points" << endl;

    cout << "\n=== Product Inventory ===" << endl;

    Product inventory[4] = {
        {1, "Laptop", 999.99, 5},
        {2, "Mouse", 25.99, 20},
        {3, "Keyboard", 79.99, 15},
        {4, "Monitor", 299.99, 8}
    };

    cout << "Current Inventory:" << endl;
    cout << "ID\tName\t\tPrice\t\tQuantity" << endl;
    cout << "--------------------------------------------" << endl;

    for (int i = 0; i < 4; i++) {
        cout << inventory[i].id << "\t";
        cout << inventory[i].name << "\t\t";
        cout << "$" << inventory[i].price << "\t\t";
        cout << inventory[i].quantity << endl;
    }

    float totalValue = 0;
    for (int i = 0; i < 4; i++) {
        totalValue += inventory[i].price * inventory[i].quantity;
    }

    cout << "\nTotal Inventory Value: $" << totalValue << endl;

    int searchId = 2;
    cout << "\n=== Searching for Product ID " << searchId << " ===" << endl;

    for (int i = 0; i < 4; i++) {
        if (inventory[i].id == searchId) {
            cout << "Found: " << inventory[i].name << endl;
            cout << "Price: $" << inventory[i].price << endl;
            cout << "In stock: " << inventory[i].quantity << endl;
            break;
        }
    }

    return 0;
}

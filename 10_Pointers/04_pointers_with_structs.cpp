#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

struct Player {
    string name;
    int score;
    int level;
};

void displayPoint(Point* p) {
    cout << "Point: (" << p->x << ", " << p->y << ")" << endl;
}

void movePoint(Point* p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

void resetPlayer(Player* p) {
    p->score = 0;
    p->level = 1;
}

void awardPoints(Player* p, int points) {
    p->score += points;

    if (p->score >= p->level * 1000) {
        p->level++;
        cout << p->name << " leveled up to level " << p->level << "!" << endl;
    }
}

int main() {
    cout << "=== Pointers with Structs ===" << endl;

    Point p1 = {10, 20};

    Point* ptr = &p1;

    cout << "Using pointer:" << endl;
    cout << "x = " << ptr->x << endl;  // Arrow operator
    cout << "y = " << ptr->y << endl;

    cout << "\nAlternative notation:" << endl;
    cout << "x = " << (*ptr).x << endl;
    cout << "y = " << (*ptr).y << endl;

    cout << "\n=== Display Function ===" << endl;
    displayPoint(ptr);

    cout << "\n=== Moving Point ===" << endl;
    cout << "Before: ";
    displayPoint(ptr);

    movePoint(ptr, 5, -3);

    cout << "After moving by (5, -3): ";
    displayPoint(ptr);

    cout << "\n=== Player Management ===" << endl;
    Player player1 = {"Alice", 0, 1};

    cout << "Player: " << player1.name << endl;
    cout << "Score: " << player1.score << endl;
    cout << "Level: " << player1.level << endl;

    cout << "\n=== Awarding Points ===" << endl;
    awardPoints(&player1, 500);
    cout << "After 500 points: Score = " << player1.score
         << ", Level = " << player1.level << endl;

    awardPoints(&player1, 600);
    cout << "After 600 more points: Score = " << player1.score
         << ", Level = " << player1.level << endl;

    awardPoints(&player1, 1000);
    cout << "After 1000 more points: Score = " << player1.score
         << ", Level = " << player1.level << endl;

    cout << "\n=== Reset Player ===" << endl;
    resetPlayer(&player1);
    cout << "After reset: Score = " << player1.score
         << ", Level = " << player1.level << endl;

    cout << "\n=== Array of Structs with Pointers ===" << endl;
    Point points[] = {{1, 2}, {3, 4}, {5, 6}};

    Point* arrayPtr = points;
    for (int i = 0; i < 3; i++) {
        cout << "Point " << i << ": (" << arrayPtr->x << ", " << arrayPtr->y << ")" << endl;
        arrayPtr++;
    }

    return 0;
}

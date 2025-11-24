#include <iostream>
using namespace std;


enum GameState {
    MENU,
    PLAYING,
    PAUSED,
    GAME_OVER,
    QUIT
};

enum PlayerStatus {
    ALIVE,
    INJURED,
    DEAD
};

enum DifficultyLevel {
    EASY = 1,
    MEDIUM = 2,
    HARD = 3,
    EXPERT = 4
};

enum WeaponType {
    SWORD,
    BOW,
    STAFF,
    DAGGER
};

string getGameStateName(GameState state) {
    switch (state) {
        case MENU: return "Main Menu";
        case PLAYING: return "Playing";
        case PAUSED: return "Paused";
        case GAME_OVER: return "Game Over";
        case QUIT: return "Quit";
    }
    return "Unknown";
}

string getPlayerStatusName(PlayerStatus status) {
    switch (status) {
        case ALIVE: return "Alive";
        case INJURED: return "Injured";
        case DEAD: return "Dead";
    }
    return "Unknown";
}

void displayDifficultyInfo(DifficultyLevel level) {
    cout << "Difficulty: ";
    switch (level) {
        case EASY:
            cout << "Easy (Enemies: Weak, Rewards: Low)" << endl;
            break;
        case MEDIUM:
            cout << "Medium (Enemies: Normal, Rewards: Normal)" << endl;
            break;
        case HARD:
            cout << "Hard (Enemies: Strong, Rewards: High)" << endl;
            break;
        case EXPERT:
            cout << "Expert (Enemies: Very Strong, Rewards: Very High)" << endl;
            break;
    }
}

int getWeaponDamage(WeaponType weapon) {
    switch (weapon) {
        case SWORD: return 50;
        case BOW: return 40;
        case STAFF: return 60;
        case DAGGER: return 35;
    }
    return 0;
}

string getWeaponName(WeaponType weapon) {
    switch (weapon) {
        case SWORD: return "Sword";
        case BOW: return "Bow";
        case STAFF: return "Staff";
        case DAGGER: return "Dagger";
    }
    return "Unknown";
}

int main() {
    cout << "=== Game State Management ===" << endl;

    GameState currentState = MENU;
    cout << "Current state: " << getGameStateName(currentState) << endl;

    currentState = PLAYING;
    cout << "State changed to: " << getGameStateName(currentState) << endl;

    currentState = PAUSED;
    cout << "State changed to: " << getGameStateName(currentState) << endl;

    currentState = PLAYING;
    cout << "Resumed: " << getGameStateName(currentState) << endl;

    currentState = GAME_OVER;
    cout << "Final state: " << getGameStateName(currentState) << endl;

    cout << "\n=== Player Status ===" << endl;
    PlayerStatus playerHealth = ALIVE;

    cout << "Player status: " << getPlayerStatusName(playerHealth) << endl;

    playerHealth = INJURED;
    cout << "Player took damage! Status: " << getPlayerStatusName(playerHealth) << endl;

    playerHealth = ALIVE;
    cout << "Player healed! Status: " << getPlayerStatusName(playerHealth) << endl;

    cout << "\n=== Difficulty Selection ===" << endl;
    displayDifficultyInfo(EASY);
    displayDifficultyInfo(MEDIUM);
    displayDifficultyInfo(HARD);
    displayDifficultyInfo(EXPERT);

    DifficultyLevel selectedDifficulty = MEDIUM;
    cout << "\nPlayer selected difficulty level: " << selectedDifficulty << endl;

    cout << "\n=== Weapon System ===" << endl;
    WeaponType currentWeapon = SWORD;

    cout << "Equipped: " << getWeaponName(currentWeapon) << endl;
    cout << "Damage: " << getWeaponDamage(currentWeapon) << endl;

    cout << "\n=== All Weapons ===" << endl;
    for (int i = SWORD; i <= DAGGER; i++) {
        WeaponType weapon = static_cast<WeaponType>(i);
        cout << getWeaponName(weapon) << " - Damage: " << getWeaponDamage(weapon) << endl;
    }

    return 0;
}

#include <iostream>
#include <cstdlib>
using namespace std;
int main(){


    const int SIZE = 10;
    char board[SIZE][SIZE];


    for(int i = 0; i< SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            // if(i == 3 && j >= 3 && j <= 7){
            //     board[i][j] = 'S';
            // }
            // else{
                board[i][j] = '~';
            // }

        }
    }


    for(int i = 0; i< SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Which ship do you want to place: \n";
    cout << "1. Aircraft Carrier - 5 blocks \n";
    cout << "2. Battleship - 4 blocks \n";
    cout << "3. Destroyer - 3 blocks \n";
    cout << "4. Submarine - 3 blocks \n";
    cout << "5. Patrol Boat - 2 blocks \n";
    cout << "Choose any option 1-5: ";

    int shipSelection;
    do{
    cin >> shipSelection;
    if( shipSelection != 1 && shipSelection != 2 && shipSelection != 3 && shipSelection != 4 && shipSelection != 5){
        cout << "Please enter a valid option again 1-5: ";
    }
    } while( shipSelection != 1 && shipSelection != 2 && shipSelection != 3 && shipSelection != 4 && shipSelection != 5);


    int blocks;
    switch (shipSelection)
    {
    case 1:
        blocks = 5;
        break;
    case 2:
        blocks = 4;
        break;
    case 3:
    case 4:
        blocks = 3;
        break;
    case 5:
        blocks =  2;
        break;
    default:
        blocks = 5;
        break;
    }

    int row, col;
    bool occupied = false;
    do{
    occupied = false;
    cout << "Select Row: ";
    cin >> row;
    cout << "\n Select Col:";
    cin >> col;
    if(row < 0 || row >= SIZE || col < 0 || col >= SIZE || col + blocks > SIZE){
        cout << "Please enter a valid row and column again: ";
    }
    for (int i = col; i < col + blocks; i++){
        if(board[row][i] != '~'){
            occupied = true;
            break;
        }
    }
    if(occupied){
        cout << "Some of these blocks are already occupied. Please enter a valid row and column again: ";
    }
    } while(row < 0 || row >= SIZE || col < 0 || col >= SIZE || col + blocks > SIZE || occupied);

    cout << "Row: " << row << "& Col: " << col << "& Blocks: " << blocks << endl;

// col = 3
// blocks = 3;
    for (int i = col; i < col + blocks; i++){
        board[row][i] = 'S';
    }

    for(int i = 0; i< SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }


    // Row = 3
    // Col = 4
    // Blocks = 3




    return 0;
}
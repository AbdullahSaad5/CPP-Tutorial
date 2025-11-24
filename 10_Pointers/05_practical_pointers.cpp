#include <iostream>
using namespace std;

void dynamicArrayExample() {
    cout << "=== Dynamic Array Allocation ===" << endl;

    int size;
    cout << "Enter array size: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter " << size << " numbers:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "You entered: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "Sum: " << sum << endl;

    delete[] arr;
    cout << "Memory freed" << endl;
}

struct Node {
    int data;
    Node* next;
};

class SimpleList {
private:
    Node* head;

public:
    SimpleList() {
        head = nullptr;
    }

    void addFront(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;
        cout << "List: ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    int count() {
        int cnt = 0;
        Node* current = head;
        while (current != nullptr) {
            cnt++;
            current = current->next;
        }
        return cnt;
    }

    ~SimpleList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

struct GameBoard {
    char grid[3][3];

    void initialize() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = ' ';
            }
        }
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

    char* getCellPointer(int row, int col) {
        return &grid[row][col];
    }
};

void modifyCell(char* cell, char value) {
    *cell = value;
}

int main() {
    cout << "=== Practical Pointer Examples ===" << endl;


    cout << "\n=== Simple Linked List ===" << endl;
    SimpleList list;

    list.addFront(30);
    list.addFront(20);
    list.addFront(10);

    list.display();
    cout << "Number of elements: " << list.count() << endl;

    cout << "\n=== Game Board with Pointers ===" << endl;
    GameBoard board;
    board.initialize();

    cout << "Initial board:";
    board.display();

    char* cell = board.getCellPointer(0, 0);
    modifyCell(cell, 'X');

    cell = board.getCellPointer(1, 1);
    modifyCell(cell, 'O');

    cell = board.getCellPointer(0, 2);
    modifyCell(cell, 'X');

    cout << "After modifications:";
    board.display();

    cout << "\n=== Pointer to Pointer ===" << endl;
    int value = 100;
    int* ptr1 = &value;
    int** ptr2 = &ptr1;  // Pointer to pointer

    cout << "Value: " << value << endl;
    cout << "Via ptr1: " << *ptr1 << endl;
    cout << "Via ptr2: " << **ptr2 << endl;

    **ptr2 = 200;
    cout << "After modification: " << value << endl;

    cout << "\n=== Function Pointers ===" << endl;

    int (*operation)(int, int);

    auto add = [](int a, int b) { return a + b; };
    auto multiply = [](int a, int b) { return a * b; };

    cout << "5 + 3 = " << add(5, 3) << endl;
    cout << "5 * 3 = " << multiply(5, 3) << endl;

    return 0;
}

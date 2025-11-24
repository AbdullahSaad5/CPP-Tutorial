#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;
    int rollNumber;

    Student() {
        name = "Unknown";
        age = 0;
        rollNumber = 0;
        cout << "Default constructor called" << endl;
    }

    Student(string n, int a, int r) {
        name = n;
        age = a;
        rollNumber = r;
        cout << "Parameterized constructor called for " << name << endl;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll Number: " << rollNumber << endl;
    }
};

class Book {
public:
    string title;
    string author;
    float price;

    Book(string t = "Untitled", string a = "Unknown", float p = 0.0) {
        title = t;
        author = a;
        price = p;
    }

    void display() {
        cout << "\"" << title << "\" by " << author << " - $" << price << endl;
    }
};

class Counter {
public:
    int count;

    Counter() {
        count = 0;
    }

    Counter(int initialValue) {
        count = initialValue;
    }

    void increment() {
        count++;
    }

    void decrement() {
        count--;
    }

    void display() {
        cout << "Count: " << count << endl;
    }
};

int main() {
    cout << "=== Default Constructor ===" << endl;
    Student student1;
    student1.display();

    cout << "\n=== Parameterized Constructor ===" << endl;
    Student student2("Alice", 20, 101);
    student2.display();

    cout << "\n=== Book with Constructor ===" << endl;
    Book book1("1984", "George Orwell", 15.99);
    book1.display();

    Book book2("The Great Gatsby", "F. Scott Fitzgerald");
    book2.display();

    Book book3;  // Uses all default values
    book3.display();

    cout << "\n=== Counter Class ===" << endl;
    Counter counter1;
    counter1.display();

    counter1.increment();
    counter1.increment();
    counter1.increment();
    counter1.display();

    Counter counter2(100);
    counter2.display();
    counter2.decrement();
    counter2.display();

    return 0;
}

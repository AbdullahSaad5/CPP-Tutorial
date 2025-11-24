#include <iostream>
using namespace std;

struct Book {
    string title;
    string author;
    int pages;
    float price;
};

void displayBook(Book b) {
    cout << "Title: " << b.title << endl;
    cout << "Author: " << b.author << endl;
    cout << "Pages: " << b.pages << endl;
    cout << "Price: $" << b.price << endl;
}

Book createBook(string title, string author, int pages, float price) {
    Book b;
    b.title = title;
    b.author = author;
    b.pages = pages;
    b.price = price;
    return b;
}

void applyDiscount(Book &b, float discountPercent) {
    b.price = b.price * (1 - discountPercent / 100);
}

struct Circle {
    double radius;
};

double calculateArea(Circle c) {
    const double PI = 3.14159;
    return PI * c.radius * c.radius;
}

double calculateCircumference(Circle c) {
    const double PI = 3.14159;
    return 2 * PI * c.radius;
}

int main() {
    cout << "=== Struct with Functions ===" << endl;

    Book book1 = {"1984", "George Orwell", 328, 15.99};

    cout << "Book 1 Information:" << endl;
    displayBook(book1);

    cout << "\n=== Creating Book with Function ===" << endl;
    Book book2 = createBook("To Kill a Mockingbird", "Harper Lee", 336, 18.99);
    displayBook(book2);

    cout << "\n=== Applying Discount ===" << endl;
    cout << "Original price: $" << book1.price << endl;
    applyDiscount(book1, 20);  // 20% discount
    cout << "After 20% discount: $" << book1.price << endl;

    cout << "\n=== Circle Operations ===" << endl;
    Circle myCircle = {5.0};

    cout << "Circle with radius: " << myCircle.radius << endl;
    cout << "Area: " << calculateArea(myCircle) << endl;
    cout << "Circumference: " << calculateCircumference(myCircle) << endl;

    return 0;
}

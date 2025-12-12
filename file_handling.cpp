#include <iostream>
#include <fstream>

using namespace std;

double sum(double num1, double num2);
double square(double num1);
double sumOfTwoAndTwo();

int main() {


    string name;
    // // opening a text file for writing
    // ofstream haris("results.txt");


    // // !true = false
    // if (haris.fail()) { // haris == undefined
    //     cout << "File couldn't open properly" << endl;
    //     return 1;
    // }

    // // close the file
    // haris.close();

    // return 0;

    // ifstream my_file("results.txt");

    // if(!my_file) {
    //     cout << "Error: Unable to open the file." << endl;
    //     return 1;
    // }

    // string line;

    // while (!my_file.eof()) {

    //     // store the current line of the file
    //     // in the "line" variable
    //     getline(my_file, line);

    //     // print the line variable
    //     cout << line << endl;
    // }


    // cout << "The file has ended" << endl;
    // // close the file
    // my_file.close(); // Memory Leaks

    // return 0;

    // ofstream my_file("new_results.txt", ios::app);

    // // check the file for errors
    // if(!my_file) {
    //     cout << "Error: Unable to open the file." << endl;
    //     return 1;
    // }

    // my_file << "Line 1" << endl;
    // my_file << "Line 2" << endl;
    // my_file << "Line 3" << endl;
    // my_file << "Line 4" << endl;

    // my_file.close();


    // string name;
    // int age;


    // cout << "What is your name?: ";
    // cin >> name; // Haris

    // cout << "What is your age?: ";
    // cin >> age;

    // ofstream my_file(name + ".txt");


    // if(!my_file) {
    //     cout << "Error: Unable to open the file." << endl;
    //     return 1;
    // }

    // my_file << "Hi, " << name << "!" << endl;
    // my_file << "Your age is " << age << endl;


    // my_file.close();

    // return 0;

    // sum()



    double answer = square(4);
    cout << "Your answer is " << answer << endl;
    return 0;



}

// "1.111111"
// "3.124124"
// 1.1111113.124124


double sum(double num1, double num2){
    return num1 + num2;
}

double square(double num1){
    return pow(num1, 2);
}

double sumOfTwoAndTwo(){
    int num1 = 2;
    int num2 = 2;
    return num1 + num2;
}


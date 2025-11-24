#include <iostream>
using namespace std;


class BankAccount {
private:  // Private members - can only be accessed within the class
    string accountNumber;
    double balance;

public:  // Public members - can be accessed from outside
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }

    string getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
            return true;
        } else {
            cout << "Invalid withdrawal or insufficient funds!" << endl;
            return false;
        }
    }

    void displayInfo() {
        cout << "Account: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class Password {
private:
    string password;
    int attempts;
    const int MAX_ATTEMPTS = 3;

public:
    Password(string pass) {
        password = pass;
        attempts = 0;
    }

    bool verify(string inputPassword) {
        if (attempts >= MAX_ATTEMPTS) {
            cout << "Account locked! Too many attempts." << endl;
            return false;
        }

        if (inputPassword == password) {
            cout << "Password correct!" << endl;
            attempts = 0;  // Reset attempts
            return true;
        } else {
            attempts++;
            cout << "Wrong password! Attempts remaining: "
                 << (MAX_ATTEMPTS - attempts) << endl;
            return false;
        }
    }

    void changePassword(string oldPass, string newPass) {
        if (oldPass == password) {
            password = newPass;
            cout << "Password changed successfully!" << endl;
        } else {
            cout << "Current password incorrect!" << endl;
        }
    }
};

class Temperature {
private:
    double celsius;

public:
    Temperature(double c = 0.0) {
        celsius = c;
    }

    double getCelsius() {
        return celsius;
    }

    void setCelsius(double c) {
        if (c >= -273.15) {  // Absolute zero check
            celsius = c;
        } else {
            cout << "Invalid temperature (below absolute zero)!" << endl;
        }
    }

    double toFahrenheit() {
        return (celsius * 9.0 / 5.0) + 32;
    }

    double toKelvin() {
        return celsius + 273.15;
    }
};

int main() {
    cout << "=== Bank Account (Encapsulation) ===" << endl;

    BankAccount account("123456789", 1000.0);
    account.displayInfo();

    cout << "\n";
    account.deposit(500);
    account.displayInfo();

    cout << "\n";
    account.withdraw(200);
    account.displayInfo();

    cout << "\n";
    account.withdraw(2000);  // Insufficient funds


    cout << "\n=== Password System ===" << endl;
    Password myPass("secret123");

    myPass.verify("wrong");
    myPass.verify("wrong");
    myPass.verify("secret123");

    myPass.changePassword("secret123", "newSecret456");

    cout << "\n=== Temperature Class ===" << endl;
    Temperature temp(25.0);

    cout << "Celsius: " << temp.getCelsius() << "°C" << endl;
    cout << "Fahrenheit: " << temp.toFahrenheit() << "°F" << endl;
    cout << "Kelvin: " << temp.toKelvin() << "K" << endl;

    temp.setCelsius(-300);  // Invalid
    temp.setCelsius(100);   // Valid
    cout << "New temperature: " << temp.getCelsius() << "°C" << endl;

    return 0;
}

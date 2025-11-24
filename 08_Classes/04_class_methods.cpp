#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }

    int multiply(int a, int b) {
        return a * b;
    }

    double divide(int a, int b) {
        if (b != 0) {
            return (double)a / b;
        } else {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }

    int power(int base, int exponent) {
        int result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        return result;
    }
};

class StringHelper {
public:
    int countVowels(string str) {
        int count = 0;
        for (char c : str) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count++;
            }
        }
        return count;
    }

    string reverse(string str) {
        string reversed = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            reversed += str[i];
        }
        return reversed;
    }

    bool isPalindrome(string str) {
        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (tolower(str[left]) != tolower(str[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    string toUpper(string str) {
        for (int i = 0; i < str.length(); i++) {
            str[i] = toupper(str[i]);
        }
        return str;
    }
};

class ArrayHelper {
public:
    int findMax(int arr[], int size) {
        int max = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    int findMin(int arr[], int size) {
        int min = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

    double calculateAverage(int arr[], int size) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return (double)sum / size;
    }

    void printArray(int arr[], int size) {
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << arr[i];
            if (i < size - 1) cout << ", ";
        }
        cout << " ]" << endl;
    }
};

int main() {
    cout << "=== Calculator Class ===" << endl;
    Calculator calc;

    cout << "10 + 5 = " << calc.add(10, 5) << endl;
    cout << "10 - 5 = " << calc.subtract(10, 5) << endl;
    cout << "10 * 5 = " << calc.multiply(10, 5) << endl;
    cout << "10 / 5 = " << calc.divide(10, 5) << endl;
    cout << "2^8 = " << calc.power(2, 8) << endl;

    cout << "\n=== String Helper Class ===" << endl;
    StringHelper strHelper;

    string text = "Hello World";
    cout << "Text: " << text << endl;
    cout << "Vowels: " << strHelper.countVowels(text) << endl;
    cout << "Reversed: " << strHelper.reverse(text) << endl;
    cout << "Uppercase: " << strHelper.toUpper(text) << endl;

    string palindrome = "racecar";
    cout << "\n\"" << palindrome << "\" is palindrome? "
         << (strHelper.isPalindrome(palindrome) ? "Yes" : "No") << endl;

    cout << "\n=== Array Helper Class ===" << endl;
    ArrayHelper arrHelper;

    int numbers[] = {5, 2, 8, 1, 9, 3, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Array: ";
    arrHelper.printArray(numbers, size);

    cout << "Maximum: " << arrHelper.findMax(numbers, size) << endl;
    cout << "Minimum: " << arrHelper.findMin(numbers, size) << endl;
    cout << "Average: " << arrHelper.calculateAverage(numbers, size) << endl;

    return 0;
}

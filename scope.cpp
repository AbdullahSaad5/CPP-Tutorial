#include <iostream>
using namespace std;


// 0 + 1 = 1
// 1 + 2 = 3
// 3 + 3 = 6
// 6 + 4 = 10
// 10 + 5 = 15
// 15 + 6 = 21
// 21 + 7 = 28
// 28 + 8 = 36
// 36 + 9 = 45
// 45 + 10 = 55


void divide (int a, int b ){
    if(b == 0){
        cout << "Error: Division by zero" << endl;
        return;
    }

    cout << "The result of " << a << " divided by " << b << " is " << a / b << endl;
}




int main() {
    int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sizeOfArray1 = sizeof(array1);
    int sizeOfElement = sizeof(array1[0]);
    int lengthOfArray = sizeOfArray1 / sizeOfElement;
    for (int i = 0; i < lengthOfArray; i++) {
        cout << array1[i] << endl;
    }
    // cout << "Size of array1: " << sizeOfArray1 << endl;
    // cout << "Size of element: " << sizeOfElement << endl;
    // cout << "Length of array: " << lengthOfArray << endl;
    return 0;
}




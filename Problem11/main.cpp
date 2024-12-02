#include <iostream>
using namespace std;

/* ---- Prototype Section ---- */
int readPositiveNumber();
int reverseNumber(int number);
void printValueOfNumber(int number);
/* ---- End Of Prototype Section ---- */

int main() {
    printValueOfNumber(readPositiveNumber());

    return 0;
}

int readPositiveNumber() {
    int number;
    while (true) {
        cout << "Enter a number : ";
        cin >> number;
        if (number > 0)
            break;
        else
            cout << "Invalid Number, Enter a positive number : ";
    }
    return number;
}

int reverseNumber(int number) {
    int remainder = 0, number2 = 0;
    while (number > 0) {
        remainder = number % 10;
        number = number / 10;
        number2 = number2 * 10 + remainder;
    }
    return number2;
}

bool isPalindromeNumber(int number) { return number == reverseNumber(number); }

void printValueOfNumber(int number) {
    if (isPalindromeNumber(number) == true) {
        cout << "Number " << number << " is a PalindromeNumber.";
    } else {
        cout << "Number " << number << " is not a PalindromeNumber.";
    }
}
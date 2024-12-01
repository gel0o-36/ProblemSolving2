#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

/* ---- Prototype Section ---- */
int readNumber();
int reverseNumber(int number);
void printNumber(int number);
/* ---- End Of Prototype Section ---- */

int main() {
    printNumber(reverseNumber(readNumber()));

    cout << "\n";
    system("pause");
    return 0;
}

int readNumber() {
    int number;
    cout << "Enter a number : ";
    cin >> number;
    return number;
}

int reverseNumber(int number) {
    int newNumber, num2 = 0;
    while (number > 0) {
        newNumber = number % 10;
        number = number / 10;

        num2 = num2 * 10 + newNumber;
    }
    return num2;
}

void printNumber(int number) { cout << "The reversed number will be : " << number; }
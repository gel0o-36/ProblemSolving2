#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

/* ---- Prototype Section ---- */
int readNumber();
void reverseNumber(int number);
/* ---- End Of Prototype Section ---- */

int main() {
    reverseNumber(readNumber());

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

void reverseNumber(int number) {
    int newNumber;
    while (number > 0) {
        newNumber = number % 10;
        number = number / 10;
        cout << newNumber;
    }
}
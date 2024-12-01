#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

/* ---- Prototype Section ---- */
int readNumber(string text);
int checkNumber(int num, int which);
void PrintHowManyDigit(int num, int digit);
/* ---- End Of Prototype Section ---- */

int main() {
    int num = readNumber("Enter Array Of Numbers : ");
    short digit = readNumber("Which Digit : ");

    // this code has an error i have no idea how to solve it if i used the 2 functions inside
    // PrintHowManyDigit(readNumber("Enter Array Of Numbers : "), readNumber("Which Digit : "));

    PrintHowManyDigit(num, digit);

    cout << "\n";
    system("pause");
    return 0;
}

int readNumber(string text) {
    int num;
    cout << text;
    while (true) {
        cin >> num;
        if (num > 0)
            break;
        else
            cout << "Invalid number, try a positive number : ";
    }
    return num;
}

int checkNumber(int num, int which) {
    int num2 = 0, counter = 0;
    while (num > 0) {
        num2 = num % 10;
        num = num / 10;
        if (num2 == which) {
            counter++;
        }
    }
    return counter;
}

void PrintHowManyDigit(int num, int digit) {
    cout << "Number " << digit << " was repeated " << checkNumber(num, digit) << " times." << endl;
}

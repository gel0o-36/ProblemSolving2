#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

/* ---- Prototype Section ---- */
int readNumber(string text);
int checkNumber(int num, int which);
void PrintHowManyDigit(int num);
/* ---- End Of Prototype Section ---- */

int main() {
    PrintHowManyDigit(readNumber("Enter Array Of Numbers : "));

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
        if (num2 == which) {
            counter++;
        }
        num = num / 10;
    }
    return counter;
}

void PrintHowManyDigit(int num) {
    int counter = 0;
    for (int i = 0; i < 10; i++) {
        short counter = checkNumber(num, i);
        if (counter > 0) {
            cout << "Number " << i << " was repeated " << checkNumber(num, i) << " times." << endl;
        }
    }
}

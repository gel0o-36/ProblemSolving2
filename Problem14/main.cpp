#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

/* ---- Prototype Section ---- */
int readPositiveNumber();
void printSequnce(int number);
/* ---- End Of Prototype Section ---- */

int main() {
    printSequnce(readPositiveNumber());

    cout << "\n";
    system("pause");
    return 0;
}

int readPositiveNumber() {
    int number;
    cout << "Enter a positive number : ";
    while (true) {
        cin >> number;

        if (number > 0)
            break;
        else
            cout << "Invalid input, Enter a positive number : ";
    }
    return number;
}

void printSequnce(int number) {
    for (int i = number + 64; i > 64; i--)
    {
        for (int j = i; j > 64; j--)
        {
            cout << char(i) ;
        }
        cout << endl;
    }
    
}
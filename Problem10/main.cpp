#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int readPositiveNumber(string Message);
int reverseNumber(int number);
void printNumber(int number);

int main(){

    printNumber(reverseNumber(readPositiveNumber("Enter a positive number : ")));


    cout << "\n";
    system ("pause");
    return 0;
}

int readPositiveNumber(string Message)
{
    int number;
    while (true)
    {
        cout << Message;
        cin >> number;

        if (number >= 0)
            break;
        else
            cout << "Enter a positive number.\n";
    }
    return number;
}

int reverseNumber(int number)
{
    int remainder = 0, number2 = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        number2 = number2 * 10 + remainder;
    }
    return number2;
}

void printNumber(int number)
{
    int remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        cout << remainder << endl;
    }
}
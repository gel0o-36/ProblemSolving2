#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

enum enNum{Prime = 1, notPrime = 2};

int readNum();
void printNum(int num);

int main(){

printNum(readNum());


    cout << "\n";
    system ("pause");
    return 0;
}

int readNum(){
    int num;
    while (true)
    {
        cout << "Enter the number : ";
        cin >> num;

        if (num > 0)
            break;
        else
            cout << "Enter a positive number.\n";
        }

    return num;
}
enNum checkNum(int num){
    int m = round(num / 2);
    for (int i = 2; i <= m; i++)
    {
        if (num % i == 0)
            return enNum::notPrime;
    }
    return enNum::Prime;
    
}
void printNum(int num){

    cout << "All prime number in " << num  << " are : ";    
    cout << 1 << " ";
    for (int i = 2; i <= num; i++)
    {
        if(checkNum(i) == enNum::Prime){
        cout << i << " ";
    }

    }

}

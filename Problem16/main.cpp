#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

/* ---- Prototype Section ---- */
void printAllLetters();
/* ---- End Of Prototype Section ---- */

int main() {
    printAllLetters();
    cout << "\n";
    system("pause");
    return 0;
}
void printAllLetters() {
    string word = "";

    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            for (int k = 65; k <= 90; k++) {
                word += char(i);
                word += char(j);
                word += char(k);
                cout << word << endl;
                word = "";
            }
        }
    }
}
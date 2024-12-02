#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

/* ---- Prototype Section ---- */
string readString(string text);
bool printAllLetters(string pass);
/* ---- End Of Prototype Section ---- */

int main() {
    printAllLetters(readString("Enter : "));

    cout << "\n";
    system("pause");
    return 0;
}

string readString(string text) {
    string pass;
    cout << text;
    cin >> pass;
    return pass;
}

bool printAllLetters(string pass) {
    string word = "";
    int counter = 0;

    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            for (int k = 65; k <= 90; k++) {
                word += char(i);
                word += char(j);
                word += char(k);
                counter++;
                cout << "[Trial : " << counter << "] ";
                cout << word << endl;

                if (word == pass) {
                    cout << word << " is your password found after " << counter << "trial/s";
                    return true;
                }

                word = "";
            }
        }
    }
    return false;
}

void printValue(string pass) { cout << pass; }
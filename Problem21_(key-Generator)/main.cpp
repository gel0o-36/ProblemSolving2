#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

/* ---- Global Variables ---- */
short columnDigit = 5, keyDigit = 4;

/* ---- Prototype Section ---- */
int randomNumber(int from, int to);
void setKeyParameters();
int readPositiveNumber();
string generateKeyDigit(char caseOption);
string generateFullKey(char caseOption);
void printAllKeys(int number, char caseOption);
void saveKeysToFile(int number, char caseOption);
/* ---- End Of Prototype Section ---- */

int main() {
    srand((unsigned)time(NULL));

    setKeyParameters();  // Let the user set key parameters

    char caseOption;
    cout << "Choose key case (U for uppercase, L for lowercase, M for mixed): ";
    cin >> caseOption;

    int numKeys = readPositiveNumber();

    printAllKeys(numKeys, caseOption);  // Print keys to the console
    saveKeysToFile(numKeys, caseOption);  // Save keys to a file

    cout << "Keys have been saved to 'Keys.txt'." << endl;

    cout << "\n";
    system("pause");
    return 0;
}

int randomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void setKeyParameters() {
    cout << "Enter the number of characters per segment (columnDigit): ";
    cin >> columnDigit;
    cout << "Enter the number of segments per key (keyDigit): ";
    cin >> keyDigit;
}

int readPositiveNumber() {
    int number;
    cout << "How Many Keys : ";
    while (true) {
        cin >> number;
        if (number > 0)
            break;
        else
            cout << "Enter a Positive Number : ";
    }
    return number;
}

string generateKeyDigit(char caseOption) {
    string key = "";
    for (int i = 0; i < columnDigit; i++) {
        if (caseOption == 'U' || caseOption == 'u') {
            key += char(randomNumber(65, 90)); // Uppercase A-Z
        } else if (caseOption == 'L' || caseOption == 'l') {
            key += char(randomNumber(97, 122)); // Lowercase a-z
        } else if (caseOption == 'M' || caseOption == 'm') {
            int type = randomNumber(1, 2); // Randomly choose case
            key += char(type == 1 ? randomNumber(65, 90) : randomNumber(97, 122));
        }
    }
    return key;
}

string generateFullKey(char caseOption) {
    string key = "";
    for (int i = 0; i < keyDigit; i++) {
        key += generateKeyDigit(caseOption); // Generate a key digit
        if (i < keyDigit - 1) {
            key += "-"; // Add separator
        }
    }
    return key;
}

void printAllKeys(int number, char caseOption) {
    for (int i = 1; i <= number; i++) {
        cout << "[Key " << i << "] : " << generateFullKey(caseOption) << endl;
    }
}

void saveKeysToFile(int number, char caseOption) {
    ofstream file("Keys.txt");
    for (int i = 1; i <= number; i++) {
        file << "[Key " << i << "] : " << generateFullKey(caseOption) << endl;
    }
    file.close();
}

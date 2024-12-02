#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <set>
#include <string>


using namespace std;

/* ---- Global Variables ---- */
short segment = 5, keyDigit = 4;
set<string> generatedKeys;  // To ensure unique keys

/* ---- Prototype Section ---- */
int randomNumber(int from, int to);
void setKeyParameters();
char readcaseOption();
int readPositiveNumber();
string generateKeyDigit(char caseOption);
string generateFullKey(char caseOption);
void printAllKeys(int number, char caseOption);
void saveKeysToFile(int number, char caseOption);
/* ---- End Of Prototype Section ---- */

int main() {
    srand((unsigned)time(NULL));

    setKeyParameters();  // Let the user set key parameters

    char caseOption = readcaseOption();
    int numKeys = readPositiveNumber();

    printAllKeys(numKeys, caseOption);    // Print keys to the console
    saveKeysToFile(numKeys, caseOption);  // Save keys to a file

    cout << "\nKeys have been saved to 'Keys.txt'." << endl;

    cout << "\n";
    system("pause");
    return 0;
}

int randomNumber(int from, int to) { return rand() % (to - from + 1) + from; }

void setKeyParameters() {
    cout << "Enter the number of characters per segment: ";
    cin >> segment;
    cout << "Enter the number of segments per key: ";
    cin >> keyDigit;
}

char readcaseOption() {
    char caseOption;
    cout << "Choose key case (U for uppercase, L for lowercase, M for mixed): ";
    cin >> caseOption;
    return caseOption;
}

int readPositiveNumber() {
    int number;
    cout << "How Many Keys: ";
    while (true) {
        cin >> number;
        if (number > 0)
            break;
        else
            cout << "Enter a Positive Number: ";
    }
    return number;
}

string generateKeyDigit(char caseOption) {
    string key = "";
    for (int i = 0; i < segment; i++) {
        if (caseOption == 'U' || caseOption == 'u') {
            key += char(randomNumber(65, 90));  // Uppercase A-Z
        } else if (caseOption == 'L' || caseOption == 'l') {
            key += char(randomNumber(97, 122));  // Lowercase a-z
        } else if (caseOption == 'M' || caseOption == 'm') {
            int type = randomNumber(1, 2);  // Randomly choose case
            key += char(type == 1 ? randomNumber(65, 90) : randomNumber(97, 122));
        }
    }
    return key;
}

string generateFullKey(char caseOption) {
    string key = "";
    do {
        key = "";  // Reset key
        for (int i = 0; i < keyDigit; i++) {
            key += generateKeyDigit(caseOption);  // Generate a key digit
            if (i < keyDigit - 1) {
                key += "-";  // Add separator
            }
        }
    } while (generatedKeys.find(key) != generatedKeys.end());  // Ensure uniqueness

    generatedKeys.insert(key);  // Add to set of generated keys
    return key;
}

void printAllKeys(int number, char caseOption) {
    for (int i = 1; i <= number; i++) {
        if (i <= 9) {
            cout << "[Key " << i << "]   : " << generateFullKey(caseOption) << endl;
        } else if (i <= 99) {
            cout << "[Key " << i << "]  : " << generateFullKey(caseOption) << endl;
        } else {
            cout << "[Key " << i << "] : " << generateFullKey(caseOption) << endl;
        }
    }
}

void saveKeysToFile(int number, char caseOption) {
    ofstream file("Keys.txt");
    for (int i = 1; i <= number; i++) {
        file << "[Key " << i << "] : " << generateFullKey(caseOption) << endl;
    }
    file.close();
}

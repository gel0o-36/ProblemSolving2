#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

/* ---- Prototype Section ---- */
string readNameBeforeEncryption(string text);
string encryptName(string name, short key);
void printInfo(string name);
/* ---- End Of Prototype Section ---- */

int main() {
    printInfo(readNameBeforeEncryption("Enter Your Name : "));

    cout << "\n";
    system("pause");
    return 0;
}

string readNameBeforeEncryption(string text) {
    string name;
    cout << text;
    getline(cin, name);
    return name;
}

string encryptName(string name, short key) {
    string encryptedName = "";
    for (int i = 0; i < name.length(); i++) {
        encryptedName += char((int(name[i]) + key));
    }
    return encryptedName;
}

string decryptName(string name, short key) {
    string encryptedName = "";
    for (int i = 0; i < name.length(); i++) {
        encryptedName += char((int(name[i]) - key));
    }
    return encryptedName;
}

void printInfo(string name) {
    short key = 100;
    string encryption = encryptName(name, key), decryption = decryptName(encryption, key);

    cout << "Name After Encryption : " << encryption << endl;
    cout << "Name After Dencryption : " << decryption;
}
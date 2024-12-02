#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

enum enRand { uppercase = 1, lowercase = 2, specialchar = 3, number = 4 };

/* ---- Prototype Section ---- */
int readRandomNumber(int from, int to);
char checkNumber(enRand randNumber);
/* ---- End Of Prototype Section ---- */

int main() {
    srand((unsigned)time(NULL));

    cout << checkNumber(enRand::uppercase) << endl;
    cout << checkNumber(enRand::lowercase) << endl;
    cout << checkNumber(enRand::specialchar) << endl;
    cout << checkNumber(enRand::number) << endl;

    system("pause");
    return 0;
}

int readRandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

char checkNumber(enRand randNumber) {
    switch (randNumber) {
        case enRand::uppercase:
            return char(readRandomNumber(65, 90));

        case enRand::lowercase:
            return char(readRandomNumber(97, 122));

        case enRand::specialchar:
            return char(readRandomNumber(33, 47));

        case enRand::number:
            return char(readRandomNumber(48, 57));

        default:
            return '0';
    }
}

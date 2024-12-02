#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>


using namespace std;

/* ---- Prototype Section ---- */
int readRandomeNumber(int from, int to);
/* ---- End Of Prototype Section ---- */

int main() {
    srand((unsigned)time(NULL));

    cout << readRandomeNumber(1, 10) << endl;
    cout << readRandomeNumber(1, 10) << endl;
    cout << readRandomeNumber(1, 10) << endl;
    cout << readRandomeNumber(1, 10) << endl;
    cout << readRandomeNumber(1, 10) << endl;
    cout << readRandomeNumber(1, 10) ;

    cout << "\n";
    system("pause");
    return 0;
}

int readRandomeNumber(int from, int to) { return rand() % (to - from + 1) + from; }
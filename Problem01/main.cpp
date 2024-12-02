#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
void tableBody();
int main(){

tableBody();



    cout << "\n";
    system ("pause");
    return 0;
}

void tableHeader(){
    cout << "\n \t \tMultiplication Table\t\n\n";
    cout << "\t";

    for (int i = 1; i <= 12; i++){
        cout << i << " ";
        cout << "\t";
    }
    cout << "\n\n -----------------------------------------------------------------------------------------------------\n";
}

string tableSpace(int i){
        if (i < 10)
            return  "   |\t";
        else
            return "  |\t";
}


void tableBody(){
    tableHeader();

    for(int i = 1; i <= 12; i++){
        cout << " " << i << tableSpace(i) ;
        for (int j = 1; j <= 12; j++)
        {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}
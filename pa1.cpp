//Name: Samantha Garcia
//Section: 1133

#include <iostream>
#include <array>

#include "pa1.h"

using namespace std;

int main()
{
    int squareSize = 0;

    cout << "Enter the size of a magic square: \n";
    cin >> squareSize;

    //Will check if the input is good
    while (!cin.good() || squareSize > 15 || squareSize < 0 || (squareSize % 2 == 0)) {

        cin >> squareSize;

    }

    cout << endl;

    cout << "Magic Square #1 is: \n\n";
    //The rest of the program is done in the header file
    calculateMatrix(squareSize);

    return 0;
}





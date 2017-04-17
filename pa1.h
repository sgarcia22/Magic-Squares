//Samantha Garcia
//Section 1133

#include <iostream>
#include <array>
#include <iomanip>
#ifndef PA1_H
#define PA1_H

using namespace std;

//Functions
void calculateMatrix(int matrixSize);
void printMatrix(int** arr, int matrixSize);
int** rotate90(int** arr, int matrixSize);
void magicConstant(int** arr, int matrixSize);

//Calculates the first magic square algorithm and initializes the computation for the others
void calculateMatrix(int matrixSize) {

    //Initialize array
    int** arr = new int*[matrixSize];
    for (int i = 0; i < matrixSize; ++i) {

        arr[i] = new int[matrixSize];

    }

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize;  ++j) {

            arr[i][j] = 0;

        }


    }

    //This is the position of 1, the starting number
    int posX = (matrixSize) / 2;
    int posY = (matrixSize) - 1;

    for (int i = 1; i <= (matrixSize*matrixSize); ) {

        //If the position is completely off the grid, then it is sent back to
        //the first row and sent downwards two columns
        if (posX == -1 && posY == matrixSize) {

            posX = 0;
            posY = matrixSize - 2;


        }

        else {
            //This warps the value to the other side of the
            //matrix if it exceeds the number of rows
            if (posX < 0)
                posX = matrixSize - 1;
            //This warps the value to the other side of the
            //matrix if it exceeds the number of columns
            if (posY == matrixSize)
                posY = 0;

        }

        //If the spot is full then the value is moved up a row and down
        //two columns; the loop is restarted to make sure it doesn't
        //go in another full position or off the matrix indices
        if (arr[posX][posY] != 0) {

           posX += 1;
           posY -= 2;
           continue;

        }
        else {
            //If the spot is clear, then the value is inserted and i is
            //incremented to account for the value.
            arr[posX][posY] = i++;

        }

        //After the value is inputed the new value will be placed
        //one row down and one column to the left
        //This is placed down here because of the continue statement above;
        //If the continue statement is executed then the for loop's increments
        //will take place even if not desired.
        --posX;
        ++posY;

    }


    printMatrix(arr, matrixSize);

    //This will be used to sum up the columns/rows/diagonals
    magicConstant(arr, matrixSize);
    cout << endl;

    int count = 2;

    //This while loop is to print the remaining Magic Squares.
    while (count <= 4) {

        cout << "Magic Square #" << count << " is: \n\n";

        arr = rotate90(arr, matrixSize);
        printMatrix(arr, matrixSize);
        magicConstant(arr, matrixSize);

        count++;
        cout << endl;

    }

    //Must delete the new keywords mentioned above for purposes of the system
    for (int i = 0; i < matrixSize; ++i) {

        delete[]arr[i];

    }

        delete[]arr;
}

void printMatrix(int** arr, int matrixSize) {

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {

            //Will print matrix with a set width between each number
            cout << setw(7) << arr[i][j];

        }

        cout << endl;
    }

}

//This function will rotate the matrix by 90 degrees.
int** rotate90(int** arr, int matrixSize) {

    for (int i = 0; i < matrixSize / 2; ++i) {
        for (int j = i; j < matrixSize - i - 1; ++j) {
            //Store current value temporarily to later place it in the rotated array
            int temp = arr[i][j];
            //Values on the righter-most side will be switched to the top
            arr[i][j] = arr[j][matrixSize - 1 - i];
            //Values on the bottom of the matrix will be moved to the right
            arr[j][matrixSize - 1 - i] = arr[matrixSize - 1 - i][matrixSize - 1 - j];
            //Values on the left will be moved to the bottom of the matrix
            arr[matrixSize - 1 - i][matrixSize - 1 - j] = arr[matrixSize - 1 - j][i];
            //Put that temporary value in the new rotated index
            arr[matrixSize - 1 - j][i] = temp;

        }


    }

    return arr;

}

//This is the sum where all the rows, columns, and diagonals will add up to
void magicConstant(int** arr, int matrixSize) {

    cout << endl;
    cout << "Checking the sums of every row: \t";
    int count = 0;
    for (int i = 0; i < matrixSize; ++i){
        for (int j = 0; j < matrixSize; ++j) {
        //Adds all the values per row and later displays them
        count += arr[i][j];

        }

        cout << count << " ";
        count = 0;

    }
    cout << endl;

    cout << "Checking the sums of every column: \t";
    count = 0;
    for (int i = 0; i < matrixSize; ++i){
        for (int j = 0; j < matrixSize; ++j) {
        //Adds all the values per column and later displays them
        count += arr[j][i];

        }

        cout << count << " ";
        count = 0;

    }
    cout << endl;


    cout << "Checking the sums of every diagonal: \t";
    count = 0;
    for (int i = 0; i < matrixSize; ++i){
        for (int j = 0; j < matrixSize; ++j) {
        //Sums up the first diagonal by going through the matrix from left to right
        if (i == j)
            count += arr[i][j];

        }

    }
    cout << count << " ";
    count = 0;
    for (int i = matrixSize - 1; i >= 0; --i){
        for (int j = matrixSize - 1; j >= 0; --j) {
        //Sums up the first diagonal by going through the matrix from right to left
        if (i == j)
            count += arr[i][j];

        }

    }

    cout << count << endl;

}

#endif // PA1_H

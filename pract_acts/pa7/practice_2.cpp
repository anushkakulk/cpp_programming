// Program to read integers into a 3X3 matrix and display them
// Todo: Fix bugs and makesure program works as intended.
// for each bug fix, add a comments specifying what you fixed.

// Number of errors/bugs = 10
#include <iostream>

using namespace std;

#include <iostream>
using namespace std;

 void display(int * Matrix, int size) ; 

int main(void) {
    int size = 3;
    int Matrix[size][size]; 
    cout << "Enter 9 elements of the matrix:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> Matrix[i][j]; 
        };
    };
    display((int*)Matrix, size); 
    return 0;
}

void display(int * Matrix, int size) { 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) { 
            cout << *(Matrix+i*size+j) << ", ";
        }
        cout << " " << endl; 
    }
}


/* FIXES:
- mat is of type int, not double
- must cout the "enter 9 elems of the matrix"
- cin >> [i][j], not [j],[i] to keep in order
- int i for loop needs semicolons in statement
- int j for loop should increment j not i
- mat should be of size [size][size] not [size+1][size+1]
- display should take in int * Matrix, and calling display is display((int*)Matrix, size)
- we access the elements using *(Matrix + i *size + j)

*/
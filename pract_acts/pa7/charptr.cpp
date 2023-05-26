//This program should read any string (including spaces) from the user and print it using a character pointer
//The program is setup to use pointer offset notation to get each character of the string

//Number of bugs/errors : 8

#include <iostream>
#include <string>

using namespace std;

int main() {
    char s[20];
    char* cPtr;  
    cout << "enter a string to be copied by a pointer: " << endl;
    cin >> s;  

    cPtr = s;
    while (*cPtr != '\0') {  
        cout << *cPtr;  
        cPtr++;
    }

    cout << "\n";
    return 0;
}

/*FIXES
- include iostream
- changed cptr from char to char*
- condition changed from cPtr-- == '\0' to *cPtr != '\0'to check that its not 0
- instead of cout << cPtr++ in the while loop, first cout *cPtr, then increment cPtr (pointer offset notation)
*/
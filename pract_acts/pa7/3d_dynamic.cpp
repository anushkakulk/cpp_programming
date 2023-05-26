//This program allocated memory for an NxM integer array dynamicaly 
//The program then prints the 2D array in a matrix form using a combination of * and [] operators
//Note: You can't use ** or [][] for printing the values (use a combination of * and [] only.

//Number of bugs/errors : 6

#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;


int main() {
	int N = 3, M = 5;
	int i, j;
	int** d_array = (int**) malloc(N * sizeof(int*));  // Corrected memory allocation for 2D array (N rows)
	for (i = 0; i < N; i++)
		d_array[i] = (int*) malloc(M * sizeof(int));  // Corrected memory allocation for each row with M columns

	// Initializing 2D array using [ ][ ] notation
	printf("Initializing array values!\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			d_array[i][j] = i + j;  // Corrected assignment of values to each element
		}
	}

	// Accessing 2D array using a combination of * and [] notation
	printf("\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cout << *(*(d_array + i) + j);  
		}
		cout << "\n";
	}

	// Deallocating 2D array
	for (i = 0; i < N; i++)
		free(d_array[i]);
	free(d_array);
	return 0;
}
/* FIXES:
- added semicolon in forloop statements
- included stdio.h for printf use
- changed  *(d_array+i+j) to d_array[i][j] in initialization
- added semicolon after the d_array[i][j] = i+j line
- d_array should have memory allocation of (N * size(int*))
	while d_array[i] has memory allocation of (M * size(int))
- to iterate through an access, changed to *(*(d_array + i) + j);  
*/
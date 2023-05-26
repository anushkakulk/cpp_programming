// Program to read 3-dimensional matrix and display the elements as 1xSIZE^3 matrix
// TODO
// initize matrix using update_3d method (see comments below)
// display method must not be able to modify array elements (update the code as needed)
// display method must use a single loop/iterator to print the entire array with addresses
// display cannot use nested loops
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int SIZE;

void update_3d(int*** Matrix_3d, int size);
void display_1d(int*** Matrix_3d, int size);

int main(void)
{
	
	std::cout << "Enter a matrix size: " << std::endl;
	std::cin >> SIZE;
	
	// this should correctly create the matrix
	int*** Matrix_3d = new int**[SIZE];
    for (int i = 0; i < SIZE; i++) {
        Matrix_3d[i] = new int*[SIZE];
        for (int j = 0; j < SIZE; j++) {
            Matrix_3d[i][j] = new int[SIZE];
        }
    }

	// initialize the array to non-zero values (use scanf or random numbers generator)
	update_3d(Matrix_3d, SIZE);

	// display the values
	display_1d(Matrix_3d, SIZE);
}

void update_3d(int*** matrix, int size)
{
	srand(time(0));
	cout << "Entering " << size << "^3 elements of the matrix:" << endl;
	
	for (int i = 0; i < size; i++)
	{
		
		for (int j = 0; j < size; j++)
		{
			
			for (int k = 0; k < size; k++)
			{
				matrix[i][j][k] = rand();
			}
		}
	}
}

// update as needed. 1 'for' loop only with 1 iterator to print all values with addresses
// must not be able to update the array.
// Share any observations.
void display_1d(int*** matrix, int size) {
	
	 for (int i = 0; i < size * size * size; i++) {
        int z = i / (size * size);  
        int y = (i % (size * size)) / size; 
        int x = (i % (size * size)) % size;  

        cout << "Element (" << x << ", " << y << ", " << z << "): " << "Address: " << &(matrix[z][y][x]) << "| Value: "  << (matrix[z][y][x])<< endl;
    }
}

/*
FIXES:
- cannot make a 3d matrix wiht mat[][][], needs to properly be created with loops
- moved int i = 0, int j = 0, and int k = 0 inside respective forloop statements
- filled in matrix with rand() in update_3d
- main is void, so removed return val
- using a pointer to print out matrix with one loop
- edited display loop to calculate positions using size and prints out adress and val
-
*/
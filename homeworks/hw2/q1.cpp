// Anushka Kulkarni
// 5/20/2023
// c++ program that simulates dice rolls and neatly outputs the
// number of times each dice combination occured, the tally of sums, 
// and the tally of sums as a percentage

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>


void rollDice(int mat[][6], int tallies[], int num_rolls) {
    srand(time(0));

    for (int i = 0; i < num_rolls; i++) {
        int d1 = rand() % 6 + 1;
        int d2 = rand() % 6 + 1;
        int sum = d1 + d2;
        mat[d1 - 1][d2 - 1]++; // increments the correct combo in 6x6 arr
        tallies[sum - 2]++;    // increments the tally arr
    }
}

void printDiceArrays(const int mat[][6], const int tallies[], int num_rolls) {
    int mat_rows = 6;
    int mat_cols = 6;

    // Print and format the 6x6 array
    std::cout << "------- Simulating "<< num_rolls << " dice rolls -------" << std::endl;
    std::cout << std::setw(5) << " ";
    for (int j = 0; j < 6; j++) {
        std::cout << std::setw(5) << j + 1 << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < mat_rows; i++) {
        std::cout << std::setw(5) << i + 1 << " ";
        for (int j = 0; j < mat_cols; j++) {
            std::cout << std::setw(5) << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Print and format the sums array
    std::cout << "---------- Sum Tallies ----------" << std::endl;
    std::cout << "sum: ";
    for (int k = 2; k < 13; k++) {
        std::cout << std::setw(5) << k << " ";
    }
    std::cout << std::endl;
    std::cout << "tally:";
    for (int j = 0; j < 11; j++) {
        std::cout << std::setw(5) << tallies[j] << " ";
    }
    std::cout << std::endl;
    std::cout << "%:   ";
    for (int j = 0; j < 11; j++) {
        std::cout << std::setprecision(3) << std::setw(5) << tallies[j] / 360.00 << "%";
    }
    std::cout << std::endl;
}

int main() {
    int mat[6][6] = { 0 };
    int tallies[11] = { 0 };

    rollDice(mat, tallies, 36000);
    printDiceArrays(mat, tallies, 36000);

    return 0;
}
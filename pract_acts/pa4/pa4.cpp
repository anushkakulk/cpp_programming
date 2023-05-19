// Anushka Kulkarni
// 5/17/2023
// c++ program that takes in a text file of numbers, calculates
// total sum, and neatly displays the numbers as a 2D vector and 3D array
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

// gets all nums from file and stores them in a vector
std::vector<double> readNumsFromFile(const std::string &filename)
{
    std::vector<double> numbers;
    std::ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        std::cout << "Cannot open the file: " << filename << std::endl;
        return numbers;
    }

    double num;
    while (inputFile >> num)
    {
        numbers.push_back(num);
    }

    inputFile.close();
    return numbers;
}

// calculates the sum of all vals in vector
double calcSum(const std::vector<double> &numbers)
{
    double sum = 0.0;
    for (double num : numbers)
    {
        sum += num;
    }
    return sum;
}

// Function to determine the dimensions of the 2D vector and 3D array
void determineDimensions(int numValues, int &two_rows, int &two_cols, int &three_rows, int &three_cols, int &layers)
{
    // Choose dimensions that minimize the number of empty cells
    if (numValues <= 16)
    {
        two_rows = 4;
        two_cols = 4;
        three_rows = 3;
        three_cols = 2;
        layers = 3;
    }
    else if (numValues <= 28)
    {
        two_rows = 4;
        two_cols = 7;
        three_rows = 3;
        three_cols = 4;
        layers = 3;
    }
    else if (numValues <= 45)
    {
        two_rows = 5;
        two_cols = 6;
        three_rows = 3;
        three_cols = 5;
        layers = 3;
    }
    else if (numValues <= 48)
    {
        two_rows = 8;
        two_cols = 6;
        three_rows = 3;
        three_cols = 4;
        layers = 4;
    }
    else
    {
        two_rows = 10;
        two_cols = 5;
        three_rows = 5;
        three_cols = 5;
        layers = 2;
    }
}

// Function to print the 2D vector and 3D array to file
void printToFile(const std::vector<std::vector<double>> &vec2D, const double arr3D[][4][4], int two_rows, int two_cols, int three_rows, int three_cols, int layers, double sum)
{
    std::ofstream outputFile("output.txt");

    // Print the sum of all values
    outputFile << "Sum of all Values is " << std::fixed << std::setprecision(1) << sum << std::endl;
    outputFile << " " << std::endl;
    // Print the 2D vector
    outputFile << "2D Vector:\n";
    outputFile << " " << std::endl;
    for (int i = 0; i < two_rows; i++)
    {
        for (int j = 0; j < two_cols; j++)
        {
            if (j != 0)
            {
                outputFile << " ";
            }
            if (j < vec2D[i].size())
            {
                outputFile << std::fixed << std::setprecision(1) << vec2D[i][j];
            }
            else
            {
                outputFile << "0.0";
            }
        }
        outputFile << "\n";
    }
    outputFile << " " << std::endl;
    //  3D array
    outputFile << "3D Array:\n";
    for (int k = 0; k < layers; k++)
    {
        outputFile << "\n";
        for (int i = 0; i < three_rows; i++)
        {
            for (int j = 0; j < three_cols; j++)
            {
                if (j != 0)
                {
                    outputFile << " ";
                }
                outputFile << std::fixed << std::setprecision(1) << arr3D[k][i][j];
            }
            outputFile << "\n";
        }
    }

    outputFile.close();
}

int main()
{
    std::string filename = "input.txt";
    std::vector<double> numbers = readNumsFromFile(filename);
    double sum = calcSum(numbers);

    int two_rows, two_cols, three_rows, three_cols, layers;
    determineDimensions(numbers.size(), two_rows, two_cols, three_rows, three_cols, layers);

    std::vector<std::vector<double>> vec2D(two_rows, std::vector<double>(two_cols, 0.0));

    double arr3D[4][4][4] = {0.0};

    int index = 0;
    // fills in the 2D array properly
    for (int i = 0; i < two_rows; i++)
    {
        for (int j = 0; j < two_cols; j++)
        {
            if (index < numbers.size())
            {
                vec2D[i][j] = numbers[index];

                index++;
            }
            else
            {
                break;
            }
        }
    }
    index = 0;
    // fills in the 3D array properly
    for (int k = 0; k < layers; k++)
    {
        for (int i = 0; i < three_rows; i++)
        {
            for (int j = 0; j < three_cols; j++)
            {
                if (index < numbers.size())
                {
                    arr3D[k][i][j] = numbers[index];

                    index++;
                }
                else
                {
                    break;
                }
            }
        }
    }

    printToFile(vec2D, arr3D, two_rows, two_cols, three_rows, three_cols, layers, sum);

    return 0;
}
/* PSEUDOCODE
-get input.txt (and check if you can open it)
-open an output file
-put all elems of output in a 2d vector (while input >> num, push num into 2d vector called numbers)

// SUM
-init a var sum to be 0.0, then for every elem in 2d vector of all vals, sum += num


// 2D and 3D
-have 5 vars, 2 vars for 2D row and col, and 3 vars for 3D row, col, and layers
-hardcode vars based on number of elems in input file (using numbers.size())
-init a 2d vector and a 3d array with 0s
-iterate over nums using the 5 variables and set each position appropriately
-write the calculated sum, the 2d vector, and the 3d array to the output file
*/
// Anushka Kulkarni
// 5/22/2023
// c++ program to randomly generate a maze (that may or may not be valid)
// of any positive size

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class MazeGenerator
{
public:
    // creates a maze of the given size (may or may not be valid)
    std::vector<std::vector<char> > generate(int size)
    {

        // init everything as walls at first
        std::vector<std::vector<char> > maze(size, std::vector<char>(size, '#'));

        srand(time(0));
        
        // then loop through and make paths by randomly choosing
        for (int row = 0; row < size; ++row)
        {
            for (int col = 0; col < size; ++col)
            {

                if (rand() % 2 == 1)
                {
                    maze[row][col] = '.';
                }
            }
        }

        return maze;
    }

    // prints out the given maze 
    void printMaze(const std::vector<std::vector<char> > &maze)

    {
        for (int i = 0; i < maze.size(); ++i)
        {
            for (int j = 0; j < maze[i].size(); ++j)
            {
                char currCell = maze[i][j];
                std::cout << currCell << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    MazeGenerator generatedMaze;

    int mazeSize = 0;
    while (mazeSize <= 0)
    {
        std::cout << "Enter the length (positive int) of the maze : ";
        std::cin >> mazeSize;

        // reprompts if the input wasnt a pos int
        if (mazeSize <= 0)
        {
            std::cout << "Invalid size! Size must be a positive int" << std::endl;
        }
    }
    std::cout << "-------------------------------------------" << std::endl;
    std::vector<std::vector<char> > maze = generatedMaze.generate(mazeSize);
 
    std::cout << "Generated Maze of size " << mazeSize << "x" << mazeSize << ":" << std::endl;
    generatedMaze.printMaze(maze);

    return 0;
}

/* VISUAL INSPECTION
for validity, i only checked if there was a valid left <-> right path
I printed out 7 different mazes, 3 times each:

TRIAL:          1                   2                   3          

- 5x5    : VALID MAZE           INVALID MAZE        INVALID MAZE
- 10x10  : INVALID MAZE         INVALID MAZE        INVALID MAZE 
- 12x12  : INVALID MAZE         VALID MAZE          INVALID MAZE 
- 15x15  : INVALID MAZE         INVALID MAZE        VALID MAZE
- 20x20  : VALID MAZE           VALID MAZE          INVALID MAZE
- 30x30  : VALID MAZE           VALID MAZE          VALID MAZE  
- 45x45  : VALID MAZE           VALID MAZE          VALID MAZE

The larget the maze, the more likely there was a valid path
*/
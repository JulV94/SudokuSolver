#include "resolver.h"

void resolver()
{
    int grid[9][9], pattern[9][9] = {{0}};
    int isValid;
    double deltaT = 0.0;
    clock_t initTime, EndTime;

    clearFile("sudoku.txt"); //Clear the file to write in a empty one (and create it if not).

    cout << "***************SUDOKU Resolver***************" << endl << endl;
    selectInput(grid, pattern);

    cout << "-----------Initial grid-----------" << endl << endl << "    ";
    consoleGridDisplay(grid);
    fileGridDisplay(grid, "sudoku.txt");
    cout << endl << "Processing..." << endl;

    initTime = clock();

    isValid = solve(grid, pattern);

    if (isValid)
    {
        cout << endl << "------------Solved grid-----------" << endl << endl << "    ";
        consoleGridDisplay(grid);
        fileGridDisplay(grid, "sudoku.txt");
    }
    else
    {
        cerr << endl << "Invalid initial grid!";
    }


    EndTime = clock();
    deltaT = (double)(EndTime-initTime)/CLOCKS_PER_SEC;
    cout << endl << endl << "Done in " << deltaT << " seconds" << endl << endl;
    timeFileDisplay(deltaT, "sudoku.txt");

    return;
}

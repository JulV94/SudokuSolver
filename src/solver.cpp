#include "solver.h"

int isInLine(int grid[9][9], int n, int i)
{
    int result = 0;
    int j = 0;
    while (j <= 8 && result == 0)
    {
        if (grid[i][j] == n)
        {
            result = 1;
        }
        else
        {
            result = 0;
        }
        j++;
    }
    return result;
}

int isInColumn(int grid[9][9], int n, int j)
{
    int result = 0;
    int i = 0;
    while (i <= 8 && result == 0)
    {
        if (grid[i][j] == n)
        {
            result = 1;
        }
        else
        {
            result = 0;
        }
        i++;
    }
    return result;
}

int isInSquare(int grid[9][9], int n, int i, int j)
{
    int c = 0;
    int result = 0;
    int squareLine, squareColumn, startSquareLine, startSquareColumn;
    squareLine = i/3;
    squareColumn = j/3;
    startSquareLine = squareLine*3;
    startSquareColumn = squareColumn*3;
    while (c <= 8 && result == 0)
    {
        if (grid[startSquareLine][startSquareColumn] == n)
        {
            result = 1;
        }
        else
        {
            result = 0;
        }
        startSquareColumn = startSquareColumn + 1;
        if (startSquareColumn % 3 == 0)
        {
            startSquareColumn = startSquareColumn - 3;
            startSquareLine = startSquareLine + 1;
        }
        c++;
    }
    return result;
}

int solve(int grid[9][9], int pattern[9][9])
{
    int i = 0, j = 0, n = 1, buffer;

    for (int k = 0 ; k<9 ; k++)
    {
        for (int l = 0 ; l<9 ; l++)
        {
            if (pattern[k][l] != 0)
            {
                buffer = grid[k][l];
                grid[k][l] = 0;
                if (isInLine(grid, buffer, k) != 0 || isInColumn(grid, buffer, l) != 0 || isInSquare(grid, buffer, k, l) != 0)
                {
                    grid[k][l] = buffer;
                    return 0; //INVALID!!!
                }
                else
                {
                    grid[k][l] = buffer;
                }
            }
        }
    }

    while (i<9 && j<9 && i>=0 && j>=0)
    {
        if (pattern[i][j] != 0)
        {
            if (j == 8)
            {
                j = 0;
                i++;
            }
            else
            {
                j++;
            }
        }
        else
        {
            if (isInLine(grid, n, i) == 0 && isInColumn(grid, n, j) == 0 && isInSquare(grid, n, i, j) == 0)
            {
                grid[i][j] = n;
                if (j == 8)
                {
                    j = 0;
                    i++;
                }
                else
                {
                    j++;
                }
                n = 1;
            }
            else
            {
                if (n == 9)
                {
                    grid[i][j] = 0;
                    if (j == 0)
                    {
                        j = 8;
                        i--;
                    }
                    else
                    {
                        j--;
                    }
                    while (pattern[i][j] == 1 || grid[i][j] == 9)
                    {
                        if (grid[i][j] == 9 && pattern[i][j] == 0)
                        {
                            grid[i][j] = 0;
                        }
                        if (j == 0)
                        {
                            j = 8;
                            i--;
                        }
                        else
                        {
                            j--;
                        }
                    }
                    n = grid[i][j] + 1;
                }
                else
                {
                    n++;
                }
            }
        }
    }
    //Check if the grid is valid or if there is something impossible -> invalid
    for (int k = 0 ; k<9 ; k++)
    {
        for (int l = 0 ; l<9 ; l++)
        {
            if (grid[k][l] == 0)
            {
                return 0;  //INVALID!!!
            }
        }
    }

    return 1;  //everything ok
}

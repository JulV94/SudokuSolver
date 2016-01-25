#ifndef SOLVER_INCLUDED
#define SOLVER_INCLUDED

#include <iostream>
using namespace std;

int isInLine(int grid[9][9], int n, int i);
int isInColumn(int grid[9][9], int n, int j);
int isInSquare(int grid[9][9], int n, int i, int j);
int solve(int grid[9][9], int pattern[9][9]);

#endif // SOLVER_INCLUDED

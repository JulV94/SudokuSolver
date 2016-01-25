#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

void selectInput(int pattern[9][9], int grid[9][9]);
void manualInput(int grid[9][9], int pattern[9][9]);
void fileInput(int grid[9][9], int pattern[9][9], string fileName);

#endif // INPUTS_H_INCLUDED

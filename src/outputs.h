#ifndef OUTPUTS_H_INCLUDED
#define OUTPUTS_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

void clearFile(string fileName);
void consoleGridDisplay(int grid[9][9]);
void fileGridDisplay(int grid[9][9], string fileName);
void timeFileDisplay(double temps, string fileName);

#endif // OUTPUTS_H_INCLUDED

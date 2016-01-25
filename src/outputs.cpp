#include "outputs.h"

void clearFile(string fileName)
{
    ofstream file(fileName.c_str(), ios::out | ios::trunc);
    if (!file)
    {
        cerr << "Cannot open file " << fileName << "!" << endl;
    }
    file.close();

    return;
}

void consoleGridDisplay(int grid[9][9])
{
    for (int i = 0; i<9 ; i++)
    {
        for (int j = 0; j<9 ; j++)
        {
            if (j == 2 || j == 5)
            {
                if (grid[i][j] == 0)
                {
                    cout << "  | ";
                }
                else
                {
                    cout << grid[i][j] << " | ";
                }
            }
            else
            {
                if (grid[i][j] == 0)
                {
                    cout << "   ";
                }
                else
                {
                    cout << grid[i][j] << "  ";
                }
            }
        }
        if (i == 2 || i == 5)
        {
            cout << endl << "    --------|---------|--------" << endl << "    ";
        }
        else
        {
            cout << endl << "            |         |" << endl << "    ";
        }
    }

    return;
}

void fileGridDisplay(int grid[9][9], string fileName)
{
    ofstream file(fileName.c_str(), ios::out | ios::app);
    if (!file)
    {
        cerr << "Cannot open file " << fileName << "!" << endl;
    }

    file << "    ";
    for (int i = 0; i<9 ; i++)
    {
        for (int j = 0; j<9 ; j++)
        {
            if (j == 2 || j == 5)
            {
                if (grid[i][j] == 0)
                {
                    file << "  | ";
                }
                else
                {
                    file << grid[i][j] << " | ";
                }
            }
            else
            {
                if (grid[i][j] == 0)
                {
                    file << "   ";
                }
                else
                {
                    file << grid[i][j] << "  ";
                }
            }
        }
        if (i == 2 || i == 5)
        {
            file << endl << "    --------|---------|--------" << endl << "    ";
        }
        else
        {
            file << endl << "            |         |" << endl << "    ";
        }
    }
    file << endl;
    file.close();

    return;
}

void timeFileDisplay(double temps, string fileName)
{
    ofstream file(fileName.c_str(), ios::out | ios::app);
    if (!file)
    {
        cerr << "Cannot open file " << fileName << "!" << endl;
    }
    file << endl << endl << "Sudoku solved in " << temps << " seconds" << endl << endl;
    file.close();

    return;
}

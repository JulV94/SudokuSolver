#include "inputs.h"

void selectInput(int pattern[9][9], int grid[9][9])
{
    int choice;
    string fileName;

    cout << "Input type?" << endl << endl;
    cout << "1. Manual" << endl;
    cout << "2. From a file" << endl;
    cout << "->";
    cin >> choice;
    cout << endl << endl;

    switch (choice)
    {
        case 1:
        cout << "-- Fill empty cells with 0 --" << endl << endl;
        manualInput(grid, pattern);
        break;

        case 2:
        cout << "File name : ";
        cin >> fileName;
        cout << endl << endl;
        fileInput(grid, pattern, fileName);
        break;

        default:
        cerr << "Invalid input!" << endl << endl;
        selectInput(grid, pattern);
        return;
        break;
    }

    return;
}

void manualInput(int grid[9][9], int pattern[9][9])
{
    cout << "Input :" << endl;

    for (int i = 0 ; i < 9 ; i++)
    {
        for (int j = 0 ; j < 9 ; j++)
        {
            cout << "Cell line " << i+1 << " column " << j+1 << " : ";
            cin >> grid[i][j];
            if (grid[i][j] < 0 || grid[i][j] > 9)
            {
                cerr << "Invalid value" << endl;
                if (j == 0)
                {
                    i--;
                    j = 8;
                }
                else
                {
                    j--;
                }
            }
            else if (grid[i][j] != 0)
            {
                pattern[i][j] = 1;
            }
        }
    }

    return;
}

void fileInput(int grid[9][9], int pattern[9][9], string fileName)
{
    ifstream file(fileName.c_str(), ios::in);
    if (!file)
    {
        cerr << "Cannot open " << fileName << " !" << endl;
        return;
    }

    for (int i = 0 ; i < 9 ; i++)
    {
        for (int j = 0 ; j < 9 ; j++)
        {
            file >> grid[i][j];
            if (grid[i][j] < 0 || grid[i][j] > 9)
            {
                cerr << "Invalid grid!" << endl;
                return;
            }
            else if (grid[i][j] != 0)
            {
                pattern[i][j] = 1;
            }
        }
    }

    file.close();
    return;
}

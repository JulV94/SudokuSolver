#include <iostream>
#include <fstream>
#include "inputs.h"
#include "solver.h"
#include "outputs.h"
#include "resolver.h"

using namespace std;

int main()
{
    char backToMenu;

    while (1)
    {
        resolver();

        cout << "Go back to the menu? (Y/N) : ";
        cin >> backToMenu;
        cout << endl << endl;
        if (backToMenu != 'y' && backToMenu != 'Y')
        {
            return 0;
        }
    }

    return 0;
}


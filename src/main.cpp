#include <iostream>
#include <fstream>
#include "entrees.h"
#include "solver.h"
#include "sorties.h"
#include "resolver.h"

using namespace std;

void menu();

int main()
{
    char retourMenu;

    while (1)
    {
        resolver();

        cout << "Retourner au menu? (O/N) : ";
        cin >> retourMenu;
        cout << endl << endl;
        if (retourMenu != 'o' && retourMenu != 'O' && retourMenu != 'y' && retourMenu != 'Y')
        {
            return 0;
        }
    }

    return 0;
}


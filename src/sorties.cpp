#include "sorties.h"

void viderFichier(string nomFichier)
{
    ofstream fichier(nomFichier.c_str(), ios::out | ios::trunc);
    if (!fichier)
    {
        cerr << "Impossible d'ouvrir le fichier " << nomFichier << "!" << endl;
    }
    fichier.close();

    return;
}

void affichageGrilleConsole(int grille[9][9])
{
    for (int i = 0; i<9 ; i++)
    {
        for (int j = 0; j<9 ; j++)
        {
            if (j == 2 || j == 5)
            {
                if (grille[i][j] == 0)
                {
                    cout << "  | ";
                }
                else
                {
                    cout << grille[i][j] << " | ";
                }
            }
            else
            {
                if (grille[i][j] == 0)
                {
                    cout << "   ";
                }
                else
                {
                    cout << grille[i][j] << "  ";
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

void affichageGrilleFichier(int grille[9][9], string nomFichier)
{
    ofstream fichier(nomFichier.c_str(), ios::out | ios::app);
    if (!fichier)
    {
        cerr << "Impossible d'ouvrir le fichier " << nomFichier << "!" << endl;
    }

    fichier << "    ";
    for (int i = 0; i<9 ; i++)
    {
        for (int j = 0; j<9 ; j++)
        {
            if (j == 2 || j == 5)
            {
                if (grille[i][j] == 0)
                {
                    fichier << "  | ";
                }
                else
                {
                    fichier << grille[i][j] << " | ";
                }
            }
            else
            {
                if (grille[i][j] == 0)
                {
                    fichier << "   ";
                }
                else
                {
                    fichier << grille[i][j] << "  ";
                }
            }
        }
        if (i == 2 || i == 5)
        {
            fichier << endl << "    --------|---------|--------" << endl << "    ";
        }
        else
        {
            fichier << endl << "            |         |" << endl << "    ";
        }
    }
    fichier << endl; //décallage (pas coller la suite du fichier)
    fichier.close();

    return;
}

void affichageTempsFichier(double temps, string nomFichier)
{
    ofstream fichier(nomFichier.c_str(), ios::out | ios::app);
    if (!fichier)
    {
        cerr << "Impossible d'ouvrir le fichier " << nomFichier << "!" << endl;
    }
    fichier << endl << endl << "Sudoku resolu en " << temps << " secondes" << endl << endl;
    fichier.close();

    return;
}

#include "entrees.h"

void selectionnerEntree(int grille[9][9], int patron[9][9])
{
    int choix;
    string nomFichier;

    cout << "Quel type d'entree?" << endl << endl;
    cout << "1. Manuelle" << endl;
    cout << "2. A partir d'un fichier" << endl;
    cout << "->";
    cin >> choix;
    cout << endl << endl; //on donne un peu d'espace

    switch (choix)
    {
        case 1:
        cout << "-- Remplir les cases vides avec des 0 --" << endl << endl;
        entreeManuelle(grille, patron);
        break;

        case 2:
        cout << "Nom du fichier : ";
        cin >> nomFichier;
        cout << endl << endl; //On donne de l'espace
        entreeFichier(grille, patron, nomFichier);
        break;

        default:
        cerr << "Veuillez entrer un choix valide!" << endl << endl;
        selectionnerEntree(grille, patron);
        return;
        break;
    }

    return;
}

void entreeManuelle(int grille[9][9], int patron[9][9])
{
    cout << "Enoncee :" << endl;

    for (int i = 0 ; i < 9 ; i++)
    {
        for (int j = 0 ; j < 9 ; j++)
        {
            cout << "Element ligne " << i+1 << " colonne " << j+1 << " : ";
            cin >> grille[i][j];
            if (grille[i][j] < 0 || grille[i][j] > 9)
            {
                cerr << "Valeur invalide, recommencer!" << endl;
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
            else if (grille[i][j] != 0)
            {
                patron[i][j] = 1;
            }
        }
    }

    return;
}

void entreeFichier(int grille[9][9], int patron[9][9], string nomFichier)
{
    ifstream fichier(nomFichier.c_str(), ios::in);
    if (!fichier)
    {
        cerr << "Impossible d'ouvrir " << nomFichier << " !" << endl;
        return;
    }

    for (int i = 0 ; i < 9 ; i++)
    {
        for (int j = 0 ; j < 9 ; j++)
        {
            fichier >> grille[i][j];
            if (grille[i][j] < 0 || grille[i][j] > 9)
            {
                cerr << "Grille indiquée invalide!" << endl;
                return;
            }
            else if (grille[i][j] != 0)
            {
                patron[i][j] = 1;
            }
        }
    }

    fichier.close();
    return;
}

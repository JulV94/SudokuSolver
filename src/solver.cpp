#include "solver.h"

int estDansLigne(int grille[9][9], int n, int i)
{
    int test = 0;
    int j = 0;
    while (j <= 8 && test == 0)
    {
        if (grille[i][j] == n)
        {
            test = 1;
        }
        else
        {
            test = 0;
        }
        j++;
    }
    return test;
}

int estDansColonne(int grille[9][9], int n, int j)
{
    int test = 0;
    int i = 0;
    while (i <= 8 && test == 0)
    {
        if (grille[i][j] == n)
        {
            test = 1;
        }
        else
        {
            test = 0;
        }
        i++;
    }
    return test;
}

int estDansCarre(int grille[9][9], int n, int i, int j)
{
    int c = 0;
    int test = 0;
    int carreligne, carrecolonne, debutcarreligne, debutcarrecolonne;
    carreligne = i/3;
    carrecolonne = j/3;
    debutcarreligne = carreligne*3;
    debutcarrecolonne = carrecolonne*3;
    while (c <= 8 && test == 0)
    {
        if (grille[debutcarreligne][debutcarrecolonne] == n)
        {
            test = 1;
        }
        else
        {
            test = 0;
        }
        debutcarrecolonne = debutcarrecolonne + 1;
        if (debutcarrecolonne % 3 == 0)
        {
            debutcarrecolonne = debutcarrecolonne - 3;
            debutcarreligne = debutcarreligne + 1;
        }
        c++;
    }
    return test;
}

int resoudre(int grille[9][9], int patron[9][9])
{
    int i = 0, j = 0, n = 1, buffer;

    for (int k = 0 ; k<9 ; k++)
    {
        for (int l = 0 ; l<9 ; l++)
        {
            if (patron[k][l] != 0)
            {
                buffer = grille[k][l];
                grille[k][l] = 0;
                if (estDansLigne(grille, buffer, k) != 0 || estDansColonne(grille, buffer, l) != 0 || estDansCarre(grille, buffer, k, l) != 0)
                {
                    grille[k][l] = buffer;
                    return 0; //INVALIDE!!!
                }
                else
                {
                    grille[k][l] = buffer;
                }
            }
        }
    }

    while (i<9 && j<9 && i>=0 && j>=0)
    {
        if (patron[i][j] != 0)
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
            if (estDansLigne(grille, n, i) == 0 && estDansColonne(grille, n, j) == 0 && estDansCarre(grille, n, i, j) == 0)
            {
                grille[i][j] = n;
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
                    grille[i][j] = 0;
                    if (j == 0)
                    {
                        j = 8;
                        i--;
                    }
                    else
                    {
                        j--;
                    }
                    while (patron[i][j] == 1 || grille[i][j] == 9)
                    {
                        if (grille[i][j] == 9 && patron[i][j] == 0)
                        {
                            grille[i][j] = 0;
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
                    n = grille[i][j] + 1;
                }
                else
                {
                    n++;
                }
            }
        }
    }
    //On vérifie si la grille est complétée ou si elle a généré une impossibilité -> invalide
    for (int k = 0 ; k<9 ; k++)
    {
        for (int l = 0 ; l<9 ; l++)
        {
            if (grille[k][l] == 0)
            {
                return 0;  //INVALIDE!!!
            }
        }
    }

    return 1;  //Tout est ok
}

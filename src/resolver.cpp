#include "resolver.h"

void resolver()
{
    int grille[9][9], patron[9][9] = {{0}};
    int estValide;
    double difTemps = 0.0;
    clock_t tempsInitial, tempsFinal;

    viderFichier("sudoku.txt"); //On vide le fichier pour réécrire dans un vide (et le créer si il n'existe pas).

    cout << "***************SUDOKU Resolver***************" << endl << endl;
    selectionnerEntree(grille, patron);

    cout << "----------Grille initiale-----------" << endl << endl << "    ";
    affichageGrilleConsole(grille);
    affichageGrilleFichier(grille, "sudoku.txt");
    cout << endl << "Calculs en cours..." << endl;

    tempsInitial = clock();

    estValide = resoudre(grille, patron);

    if (estValide)
    {
        cout << endl << "----------La grille finale----------" << endl << endl << "    ";
        affichageGrilleConsole(grille);
        affichageGrilleFichier(grille, "sudoku.txt");
    }
    else
    {
        cerr << endl << "La grille initiale est invalide!";
    }


    tempsFinal = clock();
    difTemps = (double)(tempsFinal-tempsInitial)/CLOCKS_PER_SEC;
    cout << endl << endl << "Fini en " << difTemps << " secondes" << endl << endl;
    affichageTempsFichier(difTemps, "sudoku.txt");

    return;
}

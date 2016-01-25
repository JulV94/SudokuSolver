#ifndef SORTIES_H_INCLUDED
#define SORTIES_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

void viderFichier(string nomFichier);
void affichageGrilleConsole(int grille[9][9]);
void affichageGrilleFichier(int grille[9][9], string nomFichier);
void affichageTempsFichier(double temps, string nomFichier);

#endif // SORTIES_H_INCLUDED

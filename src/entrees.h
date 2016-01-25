#ifndef ENTREES_H_INCLUDED
#define ENTREES_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

void selectionnerEntree(int grille[9][9], int patron[9][9]);
void entreeManuelle(int grille[9][9], int patron[9][9]);
void entreeFichier(int grille[9][9], int patron[9][9], string nomFichier);

#endif // ENTREES_H_INCLUDED

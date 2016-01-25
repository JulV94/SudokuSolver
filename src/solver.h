#ifndef SOLVER_INCLUDED
#define SOLVER_INCLUDED

#include <iostream>
using namespace std;

int estDansLigne(int grille[9][9], int n, int i);
int estDansColonne(int grille[9][9], int n, int j);
int estDansCarre(int grille[9][9], int n, int i, int j);
int resoudre(int grille[9][9], int patron[9][9]);

#endif // SOLVER_INCLUDED

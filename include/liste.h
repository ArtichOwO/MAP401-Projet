#include <stdio.h>
#include <stdlib.h>
#include "geom2d.h"

/* type liste de points */
typedef struct
{
    Point p;
    Cellule *n;
} Cellule;

typedef Cellule Contour;

/* type tableau */
typedef Point* Tableau_Points;

/* Cree une liste chaînee vide */
Cellule *creer_liste();

/* Ajoute un element dans la liste */
void ajouter_element_liste(Cellule *L, Point e);

/* supprime la liste */
void supprimer_liste(Cellule *L);

/* concatene L2 a L1 */
Cellule *concatener_liste(Cellule *L1, Cellule *L2);

/* supprime le premier element de la liste */
Cellule *supprimer_premier_element(Cellule *L);

/* convertit la liste en tableau */
Tableau_Points sequence_points_tableau(Cellule *L);

/* Affiche le contours de l'image */
void ecrire_contour(Cellule *L);
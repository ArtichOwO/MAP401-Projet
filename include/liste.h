#ifndef LISTE_H
#define LISTE_H

#include <stdio.h>
#include <stdlib.h>
#include "geom2d.h"

/* type liste de points */
typedef struct Cellule_s
{
    Point p;
    struct Cellule_s *n;
} Cellule;

typedef Cellule Contour;

/* type tableau */
typedef Point* Tableau_Points;

/* Cree une liste chaînee vide */
Cellule *creer_liste();

/* Renvoie la longueur */
int longueur_liste(Cellule *L);

/* Ajoute un element dans la liste */
void ajouter_element_liste(Cellule *L, Point e);

/* supprime la liste */
void supprimer_liste(Cellule *L);

/* concatene L2 a L1 */
void concatener_liste(Cellule *L1, Cellule *L2);

/* supprime le premier element de la liste */
void supprimer_premier_element(Cellule *L);

// /* convertit la liste en tableau */
// Tableau_Points sequence_points_tableau(Cellule *L);

/* Affiche le contours de l'image */
void imprimer_liste(Cellule *L);

#endif

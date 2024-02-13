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

typedef struct {
    Cellule *t;
} Liste;

typedef Cellule Contour;

/* type tableau */
typedef Point* Tableau_Points;

/* Renvoie la longueur */
int longueur_liste(Liste L);

/* Ajoute un element dans la liste */
void ajouter_element_liste(Liste * L, Point e);

/* supprime la liste */
void supprimer_liste(Liste * L);

/* concatene L2 a L1 */
void concatener_liste(Liste * L1, Liste * L2);

/* supprime le premier element de la liste */
void supprimer_premier_element(Liste * L);

// /* convertit la liste en tableau */
// Tableau_Points sequence_points_tableau(Liste L);

/* Affiche le contours de l'image */
void imprimer_liste(Liste L);

#endif

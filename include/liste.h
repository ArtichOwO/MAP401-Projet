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

/* Affiche le contours de l'image */
void imprimer_liste(Liste L);

#endif

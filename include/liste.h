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

/* Renvoie un pointeur vers la derniere cellule de la liste */
Cellule *dernier_element(Liste L);

/* Concatène la liste L2 à l1 */
Liste concatener_liste(Liste L1, Liste L2);

/* 
    Libere les cellules de la liste
    La liste L.t = NULL après execution
*/
void free_liste(Liste *L);

/* Ajoute un element dans la liste */
void ajouter_element_liste(Liste * L, Point e);

/* Affiche le contours de l'image */
void imprimer_liste(Liste L);

#endif

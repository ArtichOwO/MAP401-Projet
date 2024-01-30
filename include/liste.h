#include <stdio.h>
#include <stdlib.h>
#include "geom2d.h"

/* type liste de points */
typedef struct
{
} Liste_Point;

typedef Liste_Point Contour;

/* type tableau */
typedef Point* Tableau_Points;

/* Cree une liste chaînee vide */
Liste_Point creer_liste();

/* Ajoute un element dans la liste */
Liste_Point ajouter_element_liste(Liste_Point L, Point e);

/* supprime la liste */
Liste_Point supprimer_liste(Liste_Point L);

/* concatene L2 a L1 */
Liste_Point concatener_liste(Liste_Point L1, Liste_Point L2);

/* supprime le premier element de la liste */
Liste_Point supprimer_premier_element(Liste_Point L);

/* convertit la liste en tableau */
Tableau_Point sequence_points_tableau(Liste_Point L);

/* Affiche le contours de l'image */
void ecrire_contour(Liste_Point L);
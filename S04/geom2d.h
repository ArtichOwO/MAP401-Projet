#ifndef GEOM2D_H
#define GEOM2D_H

typedef struct Vecteur_
{
    double x, y; /* Coordonnées */
} Vecteur;

typedef struct Point_
{
    double x, y; /* Coordonnées */
} Point;

Point set_point(double x, double y);

Point add_point(Point P1, Point P2);

Vecteur vect_bipoint(Point A, Point B);

double produit_scalaire(Vecteur A, Vecteur B);

double point_norme(Point P1, Point P2);
double vect_norme(Vecteur V);

#endif

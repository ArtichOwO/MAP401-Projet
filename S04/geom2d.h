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

Point produit_reel(Point P, double l);

Vecteur vect_bipoint(Point A, Point B);

double prod_scalaire(Vecteur A, Vecteur B);

#endif

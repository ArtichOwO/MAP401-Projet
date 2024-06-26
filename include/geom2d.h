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
Vecteur set_vect(double x, double y);

Point add_point(Point P1, Point P2);
Point sub_point(Point P1, Point P2);

Vecteur add_vect(Vecteur A, Vecteur B);
Vecteur sub_vect(Vecteur A, Vecteur B);

Point produit_reel_point(Point P, double l);
Vecteur produit_reel_vecteur(Vecteur V, double l);

Vecteur vect_bipoint(Point A, Point B);

double produit_scalaire(Vecteur A, Vecteur B);

double point_norme(Point P1, Point P2);
double vect_norme(Vecteur V);

void afficher_point(Point P);
void afficher_vecteur(Vecteur V);

double distance_ps(Point P, Point A, Point B);

#endif

#include "geom2d.h"
#include <math.h>
#include <stdio.h>

Point origin = { 0, 0 };

Point set_point(double x, double y)
{
    Point P = {x ,y};
    return P;
}

Vecteur set_vect(double x, double y)
{
    Vecteur V = {x ,y};
    return V;
}

Point add_point(Point P1, Point P2)
{
    Point P = {P1.x + P2.x, P1.y + P2.y};
    return P;
}

Point sub_point(Point P1, Point P2)
{
    Point P = {P1.x - P2.x, P1.y - P2.y};
    return P;
}

Vecteur add_vect(Vecteur A, Vecteur B)
{
    Vecteur v = {
    	.x = A.x + B.x,
    	.y = A.y + B.y
    };
    return v;
}

Vecteur sub_vect(Vecteur A, Vecteur B)
{
    Vecteur v = {
        .x = A.x - B.x,
        .y = A.y - B.y
    };
    return v;
}

Point produit_reel_point(Point P, double l)
{
    Point P1 = {P.x * l, P.y * l};
    return P1;
}

Vecteur produit_reel_vecteur(Vecteur V, double l)
{
    Vecteur V1 = {V.x * l, V.y * l};
    return V1;
}

Vecteur vect_bipoint(Point A, Point B) {
	Vecteur v = {
		.x = B.x - A.x,
		.y = B.y - A.y
	};

	return v;
}

double produit_scalaire(Vecteur A, Vecteur B) {
	return A.x*B.x + A.y*B.y;
}

double point_norme(Point P1, Point P2) {
	return sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));
}

double vect_norme(Vecteur V) {
	return sqrt(pow(V.x, 2) + pow(V.y, 2));
}

void afficher_point(Point P)
{
    printf("(%lf, %lf)", P.x, P.y);
}

void afficher_vecteur(Vecteur V)
{
    printf("(%lf, %lf)", V.x, V.y);
}

double distance_ps(Point P, Point A, Point B) {
    Vecteur AP = vect_bipoint(A, P);
    Vecteur AB = vect_bipoint(A, B);

    if (A.x == B.x && A.y == B.y)
        return point_norme(A, P);

    double lambda = produit_scalaire(AP, AB) 
                  / produit_scalaire(AB, AB);

    if (lambda < 0)
        return point_norme(A, P);
    else if (lambda > 1)
        return point_norme(B, P);
    else {
        Point Q = add_point(A, 
            produit_reel_point(
                sub_point(B, A), lambda));
        return point_norme(Q, P);
    }
}

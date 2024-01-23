#include "geom2d.h"
#include <math.h>

Point set_point(double x, double y)
{
    Point P = {x ,y};
    return P;
}

Point add_point(Point P1, Point P2)
{
    Point P = {P1.x + P2.x, P1.y + P2.y};
    return P;
}

Point produit_reel_point(Point P, double l)
{
    Point P1 = {P.x * l, P.y * l};
    return P1;
}

Point produit_reel_point(Vecteur V, double l)
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

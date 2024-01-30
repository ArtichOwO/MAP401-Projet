# MAP401 Projet logiciel
## Tâche 2
> Maël Perrier, Léo Grange

### `geom2d.h`
```c
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
Vecteur add_vect(Vecteur A, Vecteur B);

Point produit_reel_point(Point P, double l);
Vecteur produit_reel_vecteur(Vecteur V, double l);

Vecteur vect_bipoint(Point A, Point B);

double produit_scalaire(Vecteur A, Vecteur B);

double point_norme(Point P1, Point P2);
double vect_norme(Vecteur V);

void afficher_point(Point P);
void afficher_vecteur(Vecteur V);

#endif
```

### `geom2d.c`
```c
#include "geom2d.h"
#include <math.h>
#include <stdio.h>

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

Vecteur add_vect(Vecteur A, Vecteur B)
{
    Vecteur v = {
    	.x = A.x + B.x,
    	.y = A.y + B.y
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
    printf("(%.0lf, %.0lf)", P.x, P.y);
}

void afficher_vecteur(Vecteur V)
{
    printf("(%.0lf, %.0lf)", V.x, V.y);
}
```

### `test_geom2d.c`
```c
#include "geom2d.h"
#include <stdio.h>

int main()
{
    Point P1 = set_point(-1, -2);
    Point P2 = set_point(10000, 154);
    Point P4 = set_point(10, 11);
    Point P5;

    Vecteur V1 = set_vect(-1454, 789);
    Vecteur V2 = set_vect(-125, 89);
    Vecteur V3 = set_vect(789, -45627);
    Vecteur V4 = set_vect(28, 30);
    Vecteur V5;

    printf("Ajout de deux points :\n");
    afficher_point(P1);
    printf(" + ");
    afficher_point(P2);
    printf(" = ");
    P5 = add_point(P1, P2);
    afficher_point(P5);
    printf("\n\n");

    printf("Produit d'un point par un scalaire :\n");
    afficher_point(P4);
    printf(" * 1.5 = ");
    P5 = produit_reel_point(P4, 1.5);
    afficher_point(P5);
    printf("\n\n");

    printf("Vecteur à partir de deux points :\n");
    afficher_point(P1);
    printf(" -> ");
    afficher_point(P4);
    printf(" = ");
    V3 = vect_bipoint(P1, P4);
    afficher_vecteur(V3);
    printf("\nDistance entre les points = %.0lf, norme du vecteur = %.0lf\n\n", 
        point_norme(P1, P4),
        vect_norme(V3));

    printf("Ajout de deux vecteurs :\n");
    afficher_vecteur(V1);
    printf(" + ");
    afficher_vecteur(V2);
    printf(" = ");
    V5 = add_vect(V1, V2);
    afficher_vecteur(V5);
    printf("\n\n");

    printf("Produit d'un vecteur par un scalaire :\n");
    afficher_vecteur(V4);
    printf(" * 1.5 = ");
    V5 = produit_reel_vecteur(V4, 1.5);
    afficher_vecteur(V5);
    printf("\n\n");

    printf("Produit scalaire :\n");
    afficher_vecteur(V1);
    printf(" * ");
    afficher_vecteur(V2);
    printf(" = %.0lf\n", produit_scalaire(V1, V2));

    return 0;
}
```

### Output de `test_geom2d`
```
$ ./test_geom2d
Ajout de deux points :
(-1, -2) + (10000, 154) = (9999, 152)

Produit d'un point par un scalaire :
(10, 11) * 1.5 = (15, 16)

Vecteur à partir de deux points :
(-1, -2) -> (10, 11) = (11, 13)
Distance entre les points = 17, norme du vecteur = 17

Ajout de deux vecteurs :
(-1454, 789) + (-125, 89) = (-1579, 878)

Produit d'un vecteur par un scalaire :
(28, 30) * 1.5 = (42, 45)

Produit scalaire :
(-1454, 789) * (-125, 89) = 251971
```

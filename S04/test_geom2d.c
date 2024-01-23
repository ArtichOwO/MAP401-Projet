#include "geom2d.h"
#include <stdio.h>

int main()
{
    Point P1 = set_point(-1.0001, -2);
    Point P2 = set_point(10000.223, 154.21);
    Point P3 = set_point(12355878.235, -7892.54);
    Point P4 = set_point(0, 0);
    Point P5;

    Vecteur V1 = set_vect(-1454.5, 789);
    Vecteur V2 = set_vect(-125.45789, 89.1);
    Vecteur V3 = set_vect(789, -45627);
    Vecteur V4 = set_vect(0, 0);
    Vecteur V5;

    P5 = add_point(P1, P2);
    afficher_point(P5);
    P5 = produit_reel_point(P4, 1.5);
    afficher_point(P4);
    V3 = vect_bipoint(P1, P3);
    afficher_vecteur(V3);
    printf("Norme = %f\n", point_norme(P2, P3));

    V5 = add_vect(V1, V2);
    afficher_vecteur(V5);
    V5 = produit_reel_vecteur(V4, 1.5);
    afficher_vecteur(V5);
    printf("Norme = %f\n", produit_scalaire(V1, V2));
    printf("Norme = %f\n", vect_norme(V2));

    return 0;
}
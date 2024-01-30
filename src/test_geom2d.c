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

#include "liste.h"

Cellule *creer_liste() {
    return (Cellule *)malloc(sizeof(Cellule));
}

int longueur_liste(Cellule *L) {
    int longueur = 0;
    Cellule *c = L;

    while (c != NULL) {
        longueur++;
        c = c->n;
    }
    return longueur;
}

void ajouter_element_liste(Cellule *L, Point e) {
    Cellule *c = (Cellule *)malloc(sizeof(Cellule));

    if (L == NULL) {
        L = c;
        L->n = NULL;
        L->p = e;
    }
}

void supprimer_liste(Cellule *L) {
    Cellule *c = (Cellule *)malloc(sizeof(Cellule));

    while (c != NULL) {
        
    }
}
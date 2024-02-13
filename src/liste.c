#include "liste.h"
#include "geom2d.h"
#include <stdio.h>

int longueur_liste(Liste L) {
    int longueur = 0;
    Cellule *c = L.t;

    while (c) {
        longueur++;
        c = c->n;
    }

    return longueur;
}

void ajouter_element_liste(Liste * L, Point e) {
    Cellule *current = L->t;
    Cellule *c = malloc(sizeof(Cellule));
    c->p = e;

    if (!current) L->t = c;
    else {
        while (current->n) current = current->n;
        current->n = c;
    }
}

void imprimer_liste(Liste L) {
    Cellule *current = L.t;

    while (current) {
        afficher_point(current->p);
        printf("\n");
        current = current->n;
    }
}

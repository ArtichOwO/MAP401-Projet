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

Cellule *dernier_element(Liste L) {
    Cellule *cell = L.t;

    if (!(cell->n))
        return cell;

    while (cell->n) {
        cell = cell->n;
    }

    return cell;
}

Liste concatener_liste(Liste L1, Liste L2) {
    dernier_element(L1)->n = L2.t;
    return L1;
}

void free_liste(Liste * L) {
    Cellule *cell;
    Cellule *back = L->t;

    if (!back) return;

    cell = back->n;
    while (cell->n) {
        free(back);
        back = cell;
        cell = cell->n;
    }
    free(cell);
    L->t = NULL;
}

void ajouter_element_liste(Liste * L, Point e) {
    Cellule *current = L->t;
    Cellule *c = malloc(sizeof(Cellule));
    c->p = e;
    c->n = NULL;

    if (!current) L->t = c;
    else {
        while (current->n) current = current->n;
        current->n = c;
    }
}

void imprimer_liste(Liste L) {
    Cellule *current = L.t;

    if (!(L.t)) {
        printf("NULL\n");
        return;
    }

    while (current) {
        afficher_point(current->p);
        printf("\n");
        current = current->n;
    }
}

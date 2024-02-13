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
        while (current->n != NULL) current = current->n;
        current->n = c;
    }
}

void supprimer_liste(Liste *L) {
    Cellule *c = malloc(sizeof(Cellule));

    while (c) {
        
    }
}

void concatener_liste(Liste *L1, Liste *L2) {
    Cellule *current = L1->t;

    if (current == NULL)
    {
        L1->t = L2->t;
    }

    while (current->n) {
        current = current->n;
    }
    current->n = L2->t;
}

void supprimer_premier_element(Liste *L) {
    if (L->t) {
        Cellule *c = L->t;
        L->t = L->t->n;
        free(c);
    }
}

// Tableau_Points sequence_points_tableau(Cellule *L) {
//     int Taille = longueur_liste(L);

//     if (Taille != 0) {
//         Tableau_Points tab = 
//         Cellule *current = L;

//         for (int i = 0; i < Taille; i++) {
//             Tab[i] = current->p;
//             current = current->n;
//         }
//     }
// }

void imprimer_liste(Liste L) {
    Cellule *current = L.t;

    while (current) {
        afficher_point(current->p);
        printf("\n");
        current = current->n;
    }
}

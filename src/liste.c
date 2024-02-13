#include "liste.h"

Cellule *creer_liste() {
    return malloc(sizeof(Cellule));
}

int longueur_liste(Cellule *L) {
    int longueur = 0;
    Cellule *c = L;

    while (c) {
        longueur++;
        c = c->n;
    }
    return longueur;
}

void ajouter_element_liste(Cellule *L, Point e) {
    Cellule *current = L;
    Cellule *c = malloc(sizeof(Cellule));

    while (!current->n) current = current->n;
    current->n = c;
}

void supprimer_liste(Cellule *L) {
    Cellule *c = malloc(sizeof(Cellule));

    while (c) {
        
    }
}

void concatener_liste(Cellule *L1, Cellule *L2) {
    Cellule *current = L1;

    if (current == NULL)
    {
        L1 = L2;
    }

    while (current->n) {
        current = current->n;
    }
    current->n = L2;
}

void supprimer_premier_element(Cellule *L) {
    
    if (L) {
        Cellule *c = L;
        L = L->n;
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

void imprimer_liste(Cellule *L) {
    Cellule *current = L;

    while (current) {
        afficher_point(current->p);
        printf("\n");
        current = current->n;
    }
}

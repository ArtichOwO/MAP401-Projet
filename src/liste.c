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

void concatener_liste(Cellule *L1, Cellule *L2) {
    Cellule *current = L1;

    if (current == NULL)
    {
        L1 = L2;
    }

    while (current->n != NULL) {
        current = current->n;
    }
    current->n = L2;
}

void supprimer_premier_element(Cellule *L) {
    
    if (L != NULL) {
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
#include "simplification.h"
#include "liste.h"
#include "geom2d.h"
#include <stdio.h>

Liste * douglas_peucker(Liste * L, double d) {
	Point A = L->t->p;
	Point B = dernier_element(*L)->p;

	Cellule * c = L->t;
	double Pk_d = distance_ps(c->p, A, B);
	Cellule * Pk_1 = c; // P_{k-1}

	while (c->n->n) {
		double Pk_d_temp = distance_ps(c->n->p, A, B);
		if (Pk_d_temp > Pk_d) {
			Pk_d = Pk_d_temp;
			Pk_1 = c;
		}
		c = c->n;
	}

	if (Pk_d <= d) {
		free_liste(L);
		ajouter_element_liste(L, A);
		ajouter_element_liste(L, B);
	} else {
		Liste * C1 = L;
		Liste L_C2 = { Pk_1->n };
		Liste * C2 = &L_C2;
		Point Pk_p = Pk_1->n->p;
		Pk_1->n = NULL;
		ajouter_element_liste(C1, Pk_p);

		C1 = douglas_peucker(C1, d);
		C2 = douglas_peucker(C2, d);
		dernier_element(*C1)->n = C2->t->n;
	}

	return L;
}

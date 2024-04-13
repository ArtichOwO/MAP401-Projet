#include "simplification.h"
#include "bezier.h"
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

Liste * douglas_peucker_b2(Liste * L, double d) {
	int n = longueur_liste(*L) - 1;
	Bezier2 B2 = approx_bezier2(*L);

	Cellule * Pk_1 = L->t; // P_{k-1}
	Cellule * current = L->t;
	double dmax = 0;
	for (int i = 1; i < n+1; i++) {
		double ti = (double) i / n;
		double di = distance_point_bezier2(B2, current->n->p, ti);
		if (dmax < di) {
			Pk_1 = current;
			dmax = di;
		}
		current = current->n;
	}

	if (dmax <= d) {
		free_liste(L);
		ajouter_element_liste(L, B2.C0);
		ajouter_element_liste(L, B2.C1);
		ajouter_element_liste(L, B2.C2);
	} else {
		Liste * C1 = L;
		Liste L_C2 = { Pk_1->n };
		Liste * C2 = &L_C2;
		Point Pk_p = Pk_1->n->p;
		Pk_1->n = NULL;
		ajouter_element_liste(C1, Pk_p);

		douglas_peucker_b2(C1, d);
		douglas_peucker_b2(C2, d);
		dernier_element(*C1)->n = C2->t->n;
		L = C1;
	}

	return L;
}

Liste * douglas_peucker_b3(Liste * L, double d) {
	int n = longueur_liste(*L) - 1;
	Bezier3 B3 = approx_bezier3(*L);

	Cellule * Pk_1 = L->t; // P_{k-1}
	Cellule * current = L->t;
	double dmax = 0;
	for (int i = 1; i < n+1; i++) {
		double ti = (double) i / n;
		double di = distance_point_bezier3(B3, current->n->p, ti);
		if (dmax < di) {
			Pk_1 = current;
			dmax = di;
		}
		current = current->n;
	}

	if (dmax <= d) {
		free_liste(L);
		ajouter_element_liste(L, B3.C0);
		ajouter_element_liste(L, B3.C1);
		ajouter_element_liste(L, B3.C2);
		ajouter_element_liste(L, B3.C3);
	} else {
		Liste * C1 = L;
		Liste L_C2 = { Pk_1->n };
		Liste * C2 = &L_C2;
		Point Pk_p = Pk_1->n->p;
		Pk_1->n = NULL;
		ajouter_element_liste(C1, Pk_p);

		douglas_peucker_b3(C1, d);
		douglas_peucker_b3(C2, d);
		dernier_element(*C1)->n = C2->t->n;
		L = C1;
	}

	return L;
}

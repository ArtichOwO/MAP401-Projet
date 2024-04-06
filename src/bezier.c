#include "bezier.h"
#include "geom2d.h"
#include "liste.h"
#include <iso646.h>
#include <math.h>
#include <stdio.h>

Point CalculBezier2(Bezier2 B, double t) {
	return add_point(
		produit_reel_point(B.C0, pow(1-t, 2)), 
		add_point(
			produit_reel_point(B.C1, 2*t*(1-t)), 
			produit_reel_point(B.C2, pow(t, 2))));
}

Point CalculBezier3(Bezier3 B, double t) {
	return add_point(
		add_point(
			produit_reel_point(B.C0, pow(1-t, 3)), 
			produit_reel_point(B.C1, 3*t*pow(1-t, 2))),
		add_point(
			produit_reel_point(B.C2, 3*pow(t, 2)*(1-t)), 
			produit_reel_point(B.C3, pow(t, 3))));
}

Bezier3 Bezier2to3(Bezier2 B) {
	Bezier3 B3 = {
		.C0 = B.C0,
		.C1 = produit_reel_point(
			add_point(B.C0, 
				produit_reel_point(B.C1, 2)), 
			1.0f/3.0f),
		.C2 = produit_reel_point(
			add_point(B.C2, 
				produit_reel_point(B.C2, 2)), 
			1.0f/3.0f),
		.C3 = B.C2
	};

	return B3;
}

Bezier2 approx_bezier2(Liste L) {
	Bezier2 B = { 
		origin,
		origin,
		origin
	};
	int n = longueur_liste(L)-1;

	if (n == 1) {
		B.C0 = L.t->p;
		B.C1 = produit_reel_point(
			add_point(L.t->p, L.t->n->p), 
			1.0f/2.0f);
		B.C2 = L.t->n->p;
	} else if (n >= 2) {
		double alpha = 3*n / (pow(n, 2) - 1);
		double beta = (1.0f - 2*n) / (2*(n + 1));
		Point sum = origin;

		Cellule * current = L.t;
		while (current->n->n) {
			current = current->n;
			sum = add_point(sum, current->p);
		}

		Point Pj1 = L.t->p;
		Point Pj2 = dernier_element(L)->p;

		B.C0 = Pj1;
		B.C1 = add_point(
			produit_reel_point(sum, alpha), 
			produit_reel_point(
				add_point(
					Pj1, 
					Pj2), 
				beta));
		B.C2 = Pj2;
	}

	return B;
}

void print_bezier2(Bezier2 B) {
	printf("{ ");
	afficher_point(B.C0);
	printf(" ");
	afficher_point(B.C1);
	printf(" ");
	afficher_point(B.C2);
	printf(" }");
}

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
	Bezier2 B;
	int n = longueur_liste(L)-1;

	if (n == 1) {
		B.C0 = L.t->p;
		B.C1 = produit_reel_point(
			add_point(L.t->p, L.t->n->p), 
			1.0f/2.0f);
		B.C2 = L.t->n->p;
	} else {
		double alpha = 3*n / (pow(n, 2) - 1);
		double beta = (1.0f - 2*n) / (2*(n + 1));
		Point sum = { 0, 0 };

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

double b3_gamma(int n, double k) {
	return 6*pow(k, 4)
		 - 8*n*pow(k, 3)
		 + 6*pow(k, 2)
		 - 4*n*k
		 + pow(n, 4)
		 - pow(n, 2);
}

Bezier3 approx_bezier3(Liste L) {
	Bezier3 B;
	int n = longueur_liste(L)-1;

	if (n < 3)
		B = Bezier2to3(approx_bezier2(L));
	else {
		double alpha = (-15*pow(n, 3) + 5*pow(n, 2) + 2*n + 4)
					 / (3*(n + 2)*(3*pow(n, 2) + 1));
		double beta = (10*pow(n, 3) - 15*pow(n, 2) + n + 2)
					/ (3*(n + 2)*(3*pow(n, 2) + 1));
		double lambda = (70.0*n)
					  / (3*(pow(n, 2) - 1)*(pow(n, 2) - 4)*(3*pow(n, 2) + 1));
		Point sum1 = { 0, 0 };
		Point sum2 = { 0, 0 };

		Cellule * current = L.t;
		for (int i = 1; current->n->n; i++) {
			current = current->n;
			sum1 = add_point(
				produit_reel_point(
					current->p, 
					b3_gamma(n, i)), 
				sum1);
			sum2 = add_point(
				produit_reel_point(
					current->p, 
					b3_gamma(n, n - i)), 
				sum2);
		}



		Point Pj1 = L.t->p;
		Point Pj2 = dernier_element(L)->p;

		B.C0 = Pj1;
		B.C1 = add_point(
			produit_reel_point(Pj1, alpha), 
			add_point(
				produit_reel_point(sum1, lambda), 
				produit_reel_point(Pj2, beta)));
		B.C2 = add_point(
			produit_reel_point(Pj1, beta), 
			add_point(
				produit_reel_point(sum2, lambda), 
				produit_reel_point(Pj2, alpha)));
		B.C3 = Pj2;
	}

	return B;
}

double distance_point_bezier2(Bezier2 B, Point Pj, double ti) {
	return point_norme(Pj, CalculBezier2(B, ti));
}

double distance_point_bezier3(Bezier3 B, Point Pj, double ti) {
	return point_norme(Pj, CalculBezier3(B, ti));
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

void print_bezier3(Bezier3 B) {
	printf("{ ");
	afficher_point(B.C0);
	printf(" ");
	afficher_point(B.C1);
	printf(" ");
	afficher_point(B.C2);
	printf(" ");
	afficher_point(B.C3);
	printf(" }");
}

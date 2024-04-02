#include "bezier.h"
#include "geom2d.h"
#include <math.h>

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
};

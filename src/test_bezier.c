#include "bezier.h"
#include "geom2d.h"
#include "liste.h"
#include <stdio.h>

int main(int argc, char * argv[]) {
	Point P0 = set_point(0, 0);
	Point P1 = set_point(1, 0);
	Point P2 = set_point(1, 1);
	Point P3 = set_point(1, 2);
	Point P4 = set_point(2, 2);
	Point P5 = set_point(3, 2);
	Point P6 = set_point(3, 3);
	Point P7 = set_point(4, 3);
	Point P8 = set_point(5, 3);

	printf("+----------+\n"
		   "| Bézier 2 |\n"
		   "+----------+\n");

	Liste L = { NULL };
	ajouter_element_liste(&L, P0);
	ajouter_element_liste(&L, P1);

	printf("## Liste ##\n");
	imprimer_liste(L);

	printf("### N=1 ###\n");
	Bezier2 B1 = approx_bezier2(L);
	print_bezier2(B1);
	printf("\n");

	ajouter_element_liste(&L, P2);
	ajouter_element_liste(&L, P3);
	ajouter_element_liste(&L, P4);
	ajouter_element_liste(&L, P5);
	ajouter_element_liste(&L, P6);
	ajouter_element_liste(&L, P7);
	ajouter_element_liste(&L, P8);

	printf("## Liste ##\n");
	imprimer_liste(L);

	printf("### N≥2 ###\n");
	Bezier2 B2 = approx_bezier2(L);
	print_bezier2(B2);
	printf("\n");

	printf("+----------+\n"
		   "| Bézier 3 |\n"
		   "+----------+\n");

	free_liste(&L);
	ajouter_element_liste(&L, P0);
	ajouter_element_liste(&L, P1);

	printf("## Liste ##\n");
	imprimer_liste(L);

	printf("### N=1 ###\n");
	Bezier3 B3 = approx_bezier3(L);
	print_bezier3(B3);
	printf("\n");

	ajouter_element_liste(&L, P2);

	printf("## Liste ##\n");
	imprimer_liste(L);

	printf("### N=2 ###\n");
	Bezier3 B4 = approx_bezier3(L);
	print_bezier3(B4);
	printf("\n");

	ajouter_element_liste(&L, P3);
	ajouter_element_liste(&L, P4);
	ajouter_element_liste(&L, P5);
	ajouter_element_liste(&L, P6);
	ajouter_element_liste(&L, P7);
	ajouter_element_liste(&L, P8);

	printf("## Liste ##\n");
	imprimer_liste(L);

	printf("### N≥3 ###\n");
	Bezier3 B5 = approx_bezier3(L);
	print_bezier3(B5);
	printf("\n");

	return 0;
}

#include "eps.h"
#include "bezier.h"
#include "contour.h"
#include "liste.h"
#include "masque.h"
#include "simplification.h"

#include <stdio.h>

void generate_eps(FILE * fd, Image I, bool fill, double d) {
	Liste contours[2048];
	int nb_contours = 0;
	Image masque = creer_masque(I);
	int L = largeur_image(I);
	int H = hauteur_image(I);
	int somme = 0;

	for (int i = 0; i < L * H; i++) {
		if (get_pixel_image(masque, i%L+1, i/L+1) == NOIR) {
			Liste contour = trouver_contour(I, masque);
			contours[nb_contours++] = *douglas_peucker_b2(&contour, d);
			somme += longueur_liste(contours[nb_contours-1]);
		}
	}
	printf("segments : %i\n", somme+1);

	fprintf(fd, "%%!PS-Adobe-3.0 EPSF-3.0\n"
		   "%%%%BoundingBox: 0 0 %i %i\n\n"
		   "0 0 0 setrgbcolor 0.0 setlinewidth\n\n",
		   I.la_largeur_de_l_image, I.la_hauteur_de_l_image);

	int somme_courbes = 0;
	for (int i = 0; i < nb_contours; i++) {
		Cellule * c = contours[i].t;

		fprintf(fd, "%.0lf %.0lf moveto\n", c->p.x,
			I.la_hauteur_de_l_image - c->p.y);
		while (c->n) {
			somme_courbes++;
			Bezier2 B2 = {
				.C0 = c->p,
				.C1 = c->n->p,
				.C2 = c->n->n->p
			};
			Bezier3 B3 = Bezier2to3(B2);
			fprintf(fd, "%lf %lf  %lf %lf  %.0lf %.0lf curveto\n", 
				B3.C1.x, I.la_hauteur_de_l_image - B3.C1.y,
				B3.C2.x, I.la_hauteur_de_l_image - B3.C2.y,
				B3.C3.x, I.la_hauteur_de_l_image - B3.C3.y);
			c = c->n->n;
		}
		fprintf(fd, "\n");
	}
	printf("courbes : %i\n", somme_courbes);

	fprintf(fd, "\n%s\n\n"
			"showpage\n",
			fill ? "fill" : "stroke");
}

#include "eps.h"
#include "contour.h"
#include "liste.h"
#include "masque.h"
#include "simplification.h"

#include <stdio.h>

void generate_eps(FILE * fd, Image I, bool fill) {
	Liste contours[2048];
	int nb_contours = 0;
	Image masque = creer_masque(I);
	int L = largeur_image(I);
	int H = hauteur_image(I);

	for (int i = 0; i < L * H; i++) {
		if (get_pixel_image(masque, i%L+1, i/L+1) == NOIR) {
			Liste contour = trouver_contour(I, masque);
			contours[nb_contours++] = *douglas_peucker(&contour, 5);
		}
	}

	fprintf(fd, "%%!PS-Adobe-3.0 EPSF-3.0\n"
		   "%%%%BoundingBox: 0 0 %i %i\n\n"
		   "0 0 0 setrgbcolor 0.0 setlinewidth\n\n",
		   I.la_largeur_de_l_image, I.la_hauteur_de_l_image);

	for (int i = 0; i < nb_contours; i++) {
		Cellule * c = contours[i].t;
		fprintf(fd, "%.0lf %.0lf moveto\n", c->p.x,
			I.la_hauteur_de_l_image - c->p.y);
		while (c->n) {
			fprintf(fd, "%.0lf %.0lf lineto\n", c->n->p.x,
				I.la_hauteur_de_l_image - c->n->p.y);
			c = c->n;
		}
		fprintf(fd, "\n");
	}

	fprintf(fd, "\n%s\n\n"
			"showpage\n",
			fill ? "fill" : "stroke");
}

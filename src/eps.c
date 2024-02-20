#include "eps.h"
#include "contour.h"
#include "liste.h"
#include <stdio.h>

void generate_eps(FILE * fd, Image I, bool fill) {
	Liste contour = trouver_contour(I);

	fprintf(fd, "%%!PS-Adobe-3.0 EPSF-3.0\n"
		   "%%%%BoundingBox: 0 0 %i %i\n\n"
		   "0 0 0 setrgbcolor 1.0 setlinewidth\n\n",
		   I.la_largeur_de_l_image, I.la_hauteur_de_l_image);

	Cellule * c = contour.t;
	fprintf(fd, "%.0lf %.0lf moveto\n", c->p.x,
		I.la_hauteur_de_l_image - c->p.y);
	while (c->n) {
		fprintf(fd, "%.0lf %.0lf lineto\n", c->n->p.x,
			I.la_hauteur_de_l_image - c->n->p.y);
		c = c->n;
	}

	fprintf(fd, "\n%s\n\n"
			"showpage\n",
			fill ? "fill" : "stroke");
}

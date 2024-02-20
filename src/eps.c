#include "eps.h"
#include "contour.h"
#include "liste.h"
#include <stdio.h>

void generate_eps(FILE * fd, Image I) {
	Liste contour = trouver_contour(I);

	fprintf(fd, "%%!PS-Adobe-3.0 EPSF-3.0\n"
		   "%%%%BoundingBox: 0 0 %i %i\n\n"
		   "1 1 1 setrgbcolor 2.0 setlinewidth\n\n",
		   I.la_largeur_de_l_image, I.la_hauteur_de_l_image);

	Cellule * c = contour.t;
	fprintf(fd, "%.0lf %.0lf moveto", c->p.x, c->p.y);
	while (c->n) 
		fprintf(fd, " %.0lf %.0lf lineto", c->n->p.x, c->n->p.y);

	fprintf(fd, "\n\nstroke\n\n"
			"showpage\n");
}

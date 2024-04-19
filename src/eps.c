#include "eps.h"
#include "bezier.h"
#include "contour.h"
#include "liste.h"
#include "masque.h"
#include "simplification.h"

#include <stdio.h>

void generate_eps(FILE * fd, Image I, bool fill, double d, BezierType bt) {
	Liste contours[2048];
	int nb_contours = 0;
	Image masque = creer_masque(I);
	int L = largeur_image(I);
	int H = hauteur_image(I);
	int somme = 0;

	for (int i = 0; i < L * H; i++)
		if (get_pixel_image(masque, i%L+1, i/L+1) == NOIR) {
			Point depart = { i%L, i/L };
			Liste contour = trouver_contour(I, masque, depart);
			switch (bt) {
				case B1:
					contours[nb_contours++] = *douglas_peucker(&contour, d);
					break;
				case B2:
					contours[nb_contours++] = *douglas_peucker_b2(&contour, d);
					break;
				case B3:
					contours[nb_contours++] = *douglas_peucker_b3(&contour, d);
			}
			somme += longueur_liste(contours[nb_contours-1]);
		}
	if (bt == B1) printf("segments : %i\n", somme+1);
	printf("contours : %i\n", nb_contours);

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
			Bezier2 b2;
			Bezier3 b3;
			switch (bt) {
				case B1:
					fprintf(fd, "%.0lf %.0lf lineto\n", 
						c->n->p.x, I.la_hauteur_de_l_image - c->n->p.y);

					c = c->n;
					break;
				case B2:
					b2.C0 = c->p;
					b2.C1 = c->n->p;
					b2.C2 = c->n->n->p;
					b3 = Bezier2to3(b2);

					c = c->n->n;
					break;
				case B3:
					b3.C0 = c->p;
					b3.C1 = c->n->p;
					b3.C2 = c->n->n->p;
					b3.C3 = c->n->n->n->p;

					c = c->n->n->n;
			}


			if (bt == B2 || bt == B3)
				fprintf(fd, "%lf %lf  %lf %lf  %.0lf %.0lf curveto\n", 
					b3.C1.x, I.la_hauteur_de_l_image - b3.C1.y,
					b3.C2.x, I.la_hauteur_de_l_image - b3.C2.y,
					b3.C3.x, I.la_hauteur_de_l_image - b3.C3.y);
		}
		fprintf(fd, "\n");
	}
	if (bt != B1) printf("courbes : %i\n", somme_courbes);

	fprintf(fd, "\n%s\n\n"
			"showpage\n",
			fill ? "fill" : "stroke");
}

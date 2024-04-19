#include "contour.h"
#include "image.h"
#include "liste.h"
#include "masque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <image>", argv[0]);
		exit(1);
	}

	Image I = lire_fichier_image(argv[1]);

	char * ext = ".contours";
	*strrchr(argv[1], '.') = 0;
	char * filename = malloc(strlen(argv[1])+strlen(ext));
	strcpy(filename, argv[1]);
	filename = strcat(argv[1], ext);
	FILE * fd = fopen(filename, "w");

	Liste listes[2048];
	int nb_contours = 0;
	Image masque = creer_masque(I);
	int L = largeur_image(I);
	int H = hauteur_image(I);

	for (int i = 0; i < L * H; i++) {
		if (get_pixel_image(masque, i%L+1, i/L+1) == NOIR) {
			Point depart = { i%L, i/L };
			listes[nb_contours++] = trouver_contour(I, masque, depart);
		}
	}

	int somme = 0;
	fprintf(fd, "%i\n\n", nb_contours);
	for (int i = 0; i < nb_contours; i++) {
		int longueur = longueur_liste(listes[i])-1;
		somme += longueur;
		fprintf(fd, "%i\n", longueur);
		Cellule * c = listes[i].t;
		while (c) {
			fprintf(fd, " %.1lf %.1lf\n", c->p.x, c->p.y);
			c = c->n;
		}
		fprintf(fd, "\n");
	}

	printf("Nombre de contours : %i\n", nb_contours);
	printf("Nombre de segments au total : %i\n", somme);

	fclose(fd);

	return 0;
}

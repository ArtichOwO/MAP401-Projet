#include "contour.h"
#include "geom2d.h"
#include "image.h"
#include "liste.h"
#include <stdio.h>

char * orientation_to_string(Orientation o) {
	switch (o) {
		case NORD:
			return "NORD";
		case SUD:
			return "SUD";
		case EST:
			return "EST";
		case OUEST:
			return "OUEST";
	}
}

static inline void memoriser_position(RobotContour rc, Liste * ListePos) {
	ajouter_element_liste(ListePos, rc.pos);
}

static inline void tourner_gauche(RobotContour * rc) {
	rc->o = (rc->o - 1) % 4;
	if (rc->o < 0) rc->o += 4;
}

static inline void tourner_droite(RobotContour * rc) {
	rc->o = (rc->o + 1) % 4;
	if (rc->o < 0) rc->o += 4;
}

static inline void avancer(RobotContour * rc) {
	if (rc->o % 2) // NS || EO
		rc->pos.x += rc->o-1 ? -1 : 1; // O || E
	else
		rc->pos.y += rc->o ? 1 : -1; // S || N
}

static inline void nouvelle_orientation(Image I, RobotContour * rc) {
	Pixel G = get_pixel_image(I, rc->pos.x + (rc->o == SUD || rc->o == EST), 
								 rc->pos.y + (rc->o == SUD || rc->o == OUEST));
	Pixel D = get_pixel_image(I, rc->pos.x + (rc->o == NORD || rc->o == EST),
								 rc->pos.y + (rc->o == SUD || rc->o == EST));

	if (G == NOIR)
		tourner_gauche(rc);
	else if (D == BLANC)
		tourner_droite(rc);
}

Point trouver_pixel_depart(Image I) {
	int L = largeur_image(I);
	int H = hauteur_image(I);
	Point P = {0, 0};

	for (int i = 0; i < L * H; i++)
		if (get_pixel_image(I, i%L + 1, i/L) == BLANC
			&& get_pixel_image(I, i%L + 1, i/L + 1) == NOIR) {
			P.x = i % L;
			P.y = i / L;
			return P;
		}

	return P;
}

Liste trouver_contour(Image I, Image masque, Point depart) {
	Liste L = { NULL };

	RobotContour rc = {
		.pos = depart,
		.o = EST
	};

	do {
		memoriser_position(rc, &L);
		avancer(&rc);
		nouvelle_orientation(I, &rc);
		if (rc.o == EST)
			set_pixel_image(masque, 
				rc.pos.x + 1, rc.pos.y + 1, BLANC);

		if (rc.pos.x == depart.x 
			&& rc.pos.y == depart.y 
			&& rc.o == EST)
			break;
	} while (true);

	memoriser_position(rc, &L);
	return L;
}

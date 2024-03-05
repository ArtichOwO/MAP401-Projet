#include "masque.h"
#include "image.h"

Image masque(Image I) {
	Image m;

	int L = largeur_image(I);
	int H = hauteur_image(I);

	for (int i = 0; i < L * H; i++) {
		set_pixel_image(m, i%L+1, i/L+1, 
			get_pixel_image(I, i%L + 1, i/L) == BLANC
			&& get_pixel_image(I, i%L + 1, i/L + 1) == NOIR 
			? NOIR : BLANC);
	}

	return m;
}

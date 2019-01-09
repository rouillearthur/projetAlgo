#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "histogram.h"
#include "quantification.h"

void testQuantification() {
    int i;
    int* tab;
    histo histogram = create_histo();
    image img = FAIRE_image();
    char *nomImage = "../IMAGES/zelda.ppm";

    image_charger(img,nomImage);
    init_histo(histogram, img);

    quantification(histogram, tab, 100);
    
    for (i = 0; i < 400; i += 4) {
	printf("La fréquence de la couleur %d %d %d est %d\n",tab[i], tab[i+1], tab[i+2], tab[i+3]);
    }
	
}


int main() {
	printf("\nTESTS RELATIFS À LA FONCTION \"QUANTIFICATION\"\n");
	testQuantification();
	printf("\n");
	return 0;
}

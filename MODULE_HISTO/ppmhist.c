#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"

int main(int argc, char* argv[]) {
	char* nomImage=argv[1];
	histo histogram;
	histo_iter h_iter;
	image image;
	int pixel[3];


	printf("Chargement de l'image \"%s\"\n",nomImage);
	image_charger(image,nomImage);
	printf("* Chargement ok\n");
	init_histo(histogram,image);
	printf("* Initialisation de histogram ok\n");
	create_histo_iter(histogram);
	printf("* Initialisation de h_iter ok\n");

}
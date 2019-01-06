#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"

int main(int argc, char* argv[]) {
	char* nomImage=argv[1];
	histo histogram=create_histo();
	histo_iter h_iter=create_histo_iter(histogram);
	image image=FAIRE_image();

	int i,j;
	printf("Chargement de l'image \"%s\"\n",nomImage);
	image_charger(image,nomImage);
	printf("* Chargement ok\n");

	init_histo(histogram,image);
	printf("* Initialisation de histogram ok\n");

	create_histo_iter(histogram);
	printf("* Initialisation de h_iter ok\n");

	for (i = 0; i < 256; i++) {
		for (j = 0; j < 256; j++) {
			if(!histogram[i][j]) {
				freq=give_freq_histo(histogram , i, j, k);
					printf("(R=%d,V=%d,B=%d,lum=%d,nb=%d)",i,j,histogram[i][j]->B,(i+j+histogram[i][j]->B)/3,give_freq_histo(histogram , i, j, histogram[i][j]->B));
			}
		}
	}

}
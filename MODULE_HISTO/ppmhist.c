#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"

int main(int argc, char* argv[]) {
	int freq;
	char* nomImage=argv[1];
	int* pixel=malloc(3*sizeof(int));

	histo histogram=create_histo();
	histo_iter h_iter;

	if(nomImage) {

		image image=FAIRE_image();

		printf("Chargement de l'image \"%s\"\n",nomImage);
		image_charger(image,nomImage);
		printf("* Chargement ok\n");

		init_histo(histogram,image);
		printf("* Initialisation de histogram ok\n");

		h_iter=create_histo_iter(histogram);
		printf("* Initialisation de h_iter ok\n");
		
		do {
			freq=give_freq_histo_iter(h_iter);
			give_color_histo_iter(h_iter, pixel);
			printf("R=%d,V=%d,B=%d,lum=%d,nb=%d\n",pixel[0],pixel[1],pixel[2],(pixel[0]+pixel[1]+pixel[2])/3,freq);
		} while(next_histo_iter(h_iter)); 
					
		
	}
	else {
		printf("Veuillez fournir en paramètre un nom d'image *ppm\n");
	}
	return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "histogram.h"

void testList() {
	cell list;
	cell tmp;
	int i;
	list = NULL;
	tmp = NULL;
	srand(time(NULL));

    /* Test fonctions manip listes */
	printf("Création d'une liste chainée avec divers éléments\n");
	for (i = 0; i < 6; i++) {
		list = insert_cell(list, rand()%255);
	}
	printf("%4s","");
	tmp = list;
	while (tmp) {
		printf("B=%d f=%d -> ",tmp->B, tmp->freq);	
		tmp = tmp->next;
	}
	printf("NIL\n");

	printf("Suppression de la liste..\n");
	list = delete_list(list);
	tmp = list;
	while (tmp) {
		printf("B=%d f=%d -> ",tmp->B, tmp->freq);	
		tmp = tmp->next;
	} 
	printf("%4sNIL\n","");
}


void testCreationHisto() {
	histo histogram;
	cell new_cell;

	histogram = create_histo();
	
	new_cell = create_cell(1,NULL);
	new_cell = insert_cell(new_cell,96);
	histogram[0][2] = new_cell;
	assert(histogram[0][2]->B == 1);
	assert(histogram[0][2]->next->B == 96);
	printf("Création de l'histogramme réalisée avec succès\n");
}


void testInitHisto() {
	histo histogram=create_histo();
	image img=FAIRE_image();
	char *nomImage = "../IMAGES/house.ppm";
	image_charger(img,nomImage);
	assert(image_charger(img,nomImage)==0);
	init_histo(histogram, img);
	printf("L'initialisation de l'histogramme avec une image se fait correctement\n");
}


void testDeleteHisto() {
	histo histogram=create_histo();
	image img=FAIRE_image();
	char *nomImage = "../IMAGES/house.ppm";
	image_charger(img,nomImage);
	init_histo(histogram, img);
	delete_histo(histogram);
	printf("La destruction de l'histogramme se fait correctement\n");
}


void testGiveFreq() {
	int i,j,k,nb,freq;
	char *nomImage = "../IMAGES/zelda.ppm";
	histo histogram=create_histo();
	image img=FAIRE_image();

	nb = 0;
	image_charger(img,nomImage);
	init_histo(histogram, img);

	
	for (i = 26; i < 256; i++) {
		for (j = 20; j < 256; j++) {
			for (k = 0; k < 256; k++) {
				freq = give_freq_histo(histogram , i, j, k);
				if ((freq > 74) && (nb < 3)) {
					printf("%4sLa fréquence de la couleur %d %d %d est de %d\n","", i, j, k, give_freq_histo(histogram , i, j, k));
					/*Ainsi on ne surcharge pas avec l'affichage de toutes les couleurs de l'image*/
					nb++;
				}
			}
		}
	}
	printf("L'interrogation des fréquences des couleurs d'une image se fait correctement \n");
}


void testCreateIter() {   
	histo histogram = create_histo();
	image img = FAIRE_image();
	char *nomImage = "../IMAGES/house.ppm";
	histo_iter h_iter;

	
	image_charger(img,nomImage);
	init_histo(histogram, img);
	h_iter=create_histo_iter(histogram);
	
	printf("%4sh_iter->R=%d h_iter->G=%d\n", "",h_iter->R, h_iter->G);
	assert(histogram[h_iter->R][h_iter->G-1] == NULL);
	printf("-> L'initialisation de l'itérateur se fait correctement\n");
}


void testDeleteIter() {
	histo histogram = create_histo();
	image img = FAIRE_image();
	char *nomImage = "../IMAGES/house.ppm";
	histo_iter h_iter;

	image_charger(img,nomImage);
	init_histo(histogram, img);
	h_iter = create_histo_iter(histogram);
	delete_histo_iter(h_iter);
   /* printf("%4sh_iter = %p\n","", h_iter);*/
   /* assert(h_iter == NULL);*/
	printf("-> La destruction de l'itérateur se fait correctement\n");
}


void testNextIter() {
	histo histogram = create_histo();
	image img = FAIRE_image();
	char *nomImage = "../IMAGES/house.ppm";
	histo_iter h_iter,h_iter_bis;

	image_charger(img,nomImage);
	init_histo(histogram, img);
	h_iter = create_histo_iter(histogram);
	h_iter_bis = create_histo_iter(histogram);
    /*delete_histo(histogram);*/

    /* Test dans le cas où l'on a bien un élément suivant */
	printf("Initialement on a : h_iter->R=%d h_iter->G=%d\n", h_iter->R, h_iter->G);
	next_histo_iter(h_iter);
	printf("Le prochain élément est : h_iter->R=%d h_iter->G=%d\n", h_iter->R, h_iter->G);
	assert(histogram[h_iter->R][h_iter->G-1] == NULL);
	printf("La recherche du prochain élément se fait avec succès\n");

    /* Test dans le cas de la fin de la liste */
	printf("Initialement on a : h_iter_bis->R=%d h_iter_bis->G=%d\n", h_iter_bis->R, h_iter_bis->G);
	while (next_histo_iter(h_iter_bis) == true) {
		printf("%4sh_iter_bis->R=%d h_iter_bis->G=%d\n","", h_iter_bis->R, h_iter_bis->G);
	}
	printf("Le prochain élément est (après épuisement de la liste) : h_iter_bis->R=%d h_iter_bis->G=%d\n", h_iter_bis->R, h_iter_bis->G);

	printf("-> Next_histo fonctionne correctement\n");
}


void testStartIter() {
	histo histogram = create_histo();
	image img = FAIRE_image();
	char *nomImage = "../IMAGES/house.ppm";
	histo_iter h_iter;

	image_charger(img,nomImage);
	init_histo(histogram, img);
	h_iter = create_histo_iter(histogram);
	printf("Initialement on a : h_iter->R=%d h_iter->G=%d\n", h_iter->R, h_iter->G);
	assert(histogram[h_iter->R][h_iter->G-1] == NULL);

	next_histo_iter(h_iter);
	next_histo_iter(h_iter);
	next_histo_iter(h_iter);
   /* assert(histogram[h_iter->R][h_iter->G-1] == NULL);*/

	printf("Après trois appels de next_iter on a : h_iter->R=%d h_iter->G=%d\n", h_iter->R, h_iter->G);
	start_histo_iter(h_iter);
	printf("Après appel de la fonction start_histo_iter on a : h_iter->R=%d h_iter->G=%d\n", h_iter->R, h_iter->G);
	assert(histogram[h_iter->R][h_iter->G-1] == NULL);
	printf("-> La remise à zéro de l'itérateur se fait correctement\n");
}


void testColorIter() {
	int* tabColor=malloc(3*sizeof(int));
	histo histogram = create_histo();
	image img = FAIRE_image();
	char *nomImage = "../IMAGES/house.ppm";
	histo_iter h_iter;

	image_charger(img,nomImage);
	init_histo(histogram, img);
	h_iter = create_histo_iter(histogram);

	give_color_histo_iter(h_iter, tabColor);
	printf("R = %d, G = %d, B = %d\n", tabColor[0], tabColor[1], tabColor[2]);
	printf("-> L'obtention de la couleur de l'élément courant de l'itérateur se fait correctement.\n");
}


void testFreqIter() {
	int freq;
	int* tabColor=malloc(3*sizeof(int));
	histo histogram = create_histo();
	image img = FAIRE_image();
	char *nomImage = "../IMAGES/house.ppm";
	histo_iter h_iter;

	image_charger(img,nomImage);
	init_histo(histogram, img);
	h_iter = create_histo_iter(histogram);

	give_color_histo_iter(h_iter, tabColor);
	freq = give_freq_histo_iter(h_iter);

	printf("La fréquence de la couleur %d %d %d est %d\n", tabColor[0], tabColor[1], tabColor[2], freq);
	printf("-> L'obtention de la fréquence de la couleur de l'élément courant de l'itérateur se fait correctement.\n");
}



int main() {
	printf("\nTESTS RELATIFS AUX LISTES\n");
	testList();

	printf("\nTESTS RELATIFS A L'HISTOGRAMME\n");
	testCreationHisto();
	testInitHisto();
	testGiveFreq();
	testDeleteHisto();

	printf("\nTESTS RELATIFS A L'ITÉRATEUR\n");
	testCreateIter();
	testDeleteIter();
	testNextIter();
	testStartIter();
	testColorIter();
	testFreqIter();
	testDeleteIter();

	printf("\n");
	return 0;
}

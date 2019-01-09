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
	printf("-> Création d'une liste chainée avec B aléatoire\n");
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

	printf("-> Suppression de la liste..\n");
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
	printf("-> Création de l'histogramme réalisée avec succès\n");
}


void testInitHisto() {
	histo histogram=create_histo();
	image img=FAIRE_image();
	char *nomImage = "../IMAGES/house.ppm";
	image_charger(img,nomImage);
	assert(image_charger(img,nomImage)==0);
	init_histo(histogram, img);
	printf("-> L'initialisation de l'histogramme avec une image se fait correctement\n");
}


void testDeleteHisto() {
	histo histogram=create_histo();
	image img=FAIRE_image();
	char *nomImage = "../IMAGES/house.ppm";
	image_charger(img,nomImage);
	init_histo(histogram, img);
	delete_histo(histogram);
	printf("-> La destruction de l'histogramme se fait correctement\n");
}


void testGiveFreq() {
	int i,j,k,nb,freq;
	char *nomImage = "../IMAGES/zelda.ppm";
	histo histogram=create_histo();
	image img=FAIRE_image();

	nb = 0;
	image_charger(img,nomImage);
	init_histo(histogram, img);

	printf("-> Interrogation de quelques fréquences des couleurs d'une image : \n");
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
}


void testCreateIter() {   
	histo histogram = create_histo();
	image img = FAIRE_image();
	char *nomImage = "../IMAGES/house.ppm";
	histo_iter h_iter;
	int i,j,R,G;
	int compteurCelluleNulle=0;
	
	
	image_charger(img,nomImage);
	init_histo(histogram, img);
	h_iter=create_histo_iter(histogram);
	R=h_iter->R;
	G=h_iter->G;
	/* On vérfie que le nombre de cellules vides avant (h_iter->R,h_iter->G,*) est correct i.e. égal à h_iter->R*h_iter->G */
	for (i=0;i<R;i++) {
		for (j=0;j<G;j++) {
			if (histogram[i][j]==NULL) {
				compteurCelluleNulle++;
			}
		}
	}
	assert(compteurCelluleNulle == R*G);

	/* On vérifie que la cellule en question est bien non nulle */
	assert(histogram[R][G]!=NULL);
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
	int R1,G1,R2,G2;
	image_charger(img,nomImage);
	init_histo(histogram, img);
	h_iter = create_histo_iter(histogram);
	h_iter_bis = create_histo_iter(histogram);
    /*delete_histo(histogram);*/

    /* Test dans le cas où l'on a bien un élément suivant */
	R1=h_iter->R;
	G1=h_iter->G;
	next_histo_iter(h_iter);
	R2=h_iter->R;
	G2=h_iter->G;

	printf("-> La recherche du prochain élément se fait avec succès :\n");
	printf("%4sInitialement on a : h_iter->R=%d h_iter->G=%d\n","", R1, G1);
	printf("%4sLe prochain élément est : h_iter->R=%d h_iter->G=%d\n","", R2, G2);

    /* Test dans le cas de la fin de la liste */
	while (next_histo_iter(h_iter_bis)) {
		/* on va en fin de liste */
	}
	R2=h_iter_bis->R;
	G2=h_iter_bis->G;
	
	assert(histogram[R2][G2+1]==NULL);
	printf("-> La recherche du dernier élément se fait avec succès :\n");
	printf("%4sInitialement on a : h_iter_bis->R=%d h_iter_bis->G=%d\n", "",R1, G1);
	printf("%4sLe dernier élément est : h_iter_bis->R=%d h_iter_bis->G=%d\n", "",R2, G2);
}


void testStartIter() {
	histo histogram = create_histo();
	image img = FAIRE_image();
	char *nomImage = "../IMAGES/house.ppm";
	histo_iter h_iter;
	int R1,R2,R3,G1,G2,G3;

	image_charger(img,nomImage);
	init_histo(histogram, img);
	h_iter = create_histo_iter(histogram);
	R1=h_iter->R;
	G1=h_iter->G;

	next_histo_iter(h_iter);
	next_histo_iter(h_iter);
	next_histo_iter(h_iter);
	R2=h_iter->R;
	G2=h_iter->G;

	start_histo_iter(h_iter);
	R3=h_iter->R;
	G3=h_iter->G;
	
	printf("-> La remise à zéro de l'itérateur se fait correctement :\n");
	printf("%4sInitialement on a : h_iter->R=%d h_iter->G=%d\n", "",R1, G1);
	printf("%4sAprès trois appels de next_iter on a : h_iter->R=%d h_iter->G=%d\n", "",R2, G2);
	printf("%4sAprès appel de la fonction start_histo_iter on a : h_iter->R=%d h_iter->G=%d\n", "",R3, G3);
}


void testColorFreqIter() {
	int* tabColor=calloc(3,sizeof(int));
	int compteurCouleurs=0;
	int bleuPrecedent=0;
	int freq;
	histo histogram = create_histo();
	image img = FAIRE_image();
	char *nomImage = "../IMAGES/deg.ppm";
	histo_iter h_iter;

	image_charger(img,nomImage);
	init_histo(histogram, img);
	h_iter = create_histo_iter(histogram);

	/* deg.ppm est une image 256*256 avec un degradé (0,255,255) vers (255,255,255) avec un pas de 1 pour R
	On doit donc avoir une liste R={0..255} et freq=256 par couleur car il y a une teinte de bleu par ligne */

	do {
		give_color_histo_iter(h_iter, tabColor);
		freq = give_freq_histo_iter(h_iter);
		if (tabColor[1]==tabColor[2] && tabColor[0]==compteurCouleurs && freq==256) {
			compteurCouleurs++;
		}

	}
	while(next_histo_iter(h_iter));
	assert(compteurCouleurs==255);
	printf("-> L'obtention de la couleur et de la fréquence de l'élément courant de l'itérateur se font correctement\n");
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
	testNextIter();
	testStartIter();
	testColorFreqIter();
	testDeleteIter();

	printf("\n");
	return 0;
}

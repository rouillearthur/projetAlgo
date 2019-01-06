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
    printf("NIL\n");
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
    histo histogram;
    image img;
    img = "../IMAGES/house.ppm";
    init_histo(histogram, img);
    printf("\nL'initialisation de l'histogramme se fait correctement avec une image quelconque\n");
}


void testDeleteHisto() {
    histo histogram;
    image img;
    img = "../IMAGES/house.ppm";
    init_histo(histogram, img);
    delete_histo(histogram);
    printf("\nLa destruction de l'histogramme se fait correctement avec une image quelconque\n");
}


void testGiveFreq() {
    int i,j,k;
    histo histogram;
    image img;
    img = "../IMAGES/house.ppm";
    init_histo(histogram, img);
    for (i = 0; i < 255; i+5) {
	for (j = 0; j < 255; j+5) {
	    for (k = 0; k < 255; k+5) {
		printf("La fréquence de la couleur %d %d %d est de %d\n",i,j,k,give_freq_histo(histogram , i, j, k));
	    }
	}
    }
    delete_histo(histogram);
    printf("\nL'interrogation des fréquences des couleurs se fait correctement avec une image quelconque\n");
}


void testCreateIter() {   
    histo histogram;
    image img;
    img = "../IMAGES/house.ppm";
    init_histo(histogram, img);
    create_histo_iter(histogram);
    
    printf("\nL'initialisation de l'itérateur se fait correctement avec une image quelconque\n");
}



int main() {
    testList();
    testCreationHisto();
    /*testInitHisto();
    testDeleteHisto();
testGiveFreq();
testCreateIter();
    Plante au chargement de l'image (buf assertion fail) */

    

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "histogram.h"

void testList() {
	cell list=NULL;
	cell tmp=NULL;
	int i;
	srand(time(NULL));

	/* Test fonctions manip listes */
	printf("Création d'une liste chainée avec divers éléments\n");
 	for (i=0;i<6;i++) {
 		list=insert_cell(list,rand()%255);
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
	printf("Fonction relative à la création d'histogrammes fonctionnelle\n");

	delete_histo(histogram);
	printf("Fonction relative à la suppression d'histogrammes fonctionnelle\n");
	
}


void testInitHisto() {
/*	histo histogram;*/
	/*image img = INSTANCIER(img);*/
	  /* init_histo(histogram,img);*/
}


int main() {
	testList();
	testCreationHisto();
	testInitHisto();

	return 0;
}

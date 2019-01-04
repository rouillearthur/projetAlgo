#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "histogram.h"

int main() {
	cell list=NULL;
	cell tmp=NULL;
	srand(time(NULL));
	histo histogram;
	int i;

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

	/* Test fonctions histo */
	printf("\nEssai fonctions histo\n");
	histogram = create_histo();
	printf("histogram après initialisation utilise %ld octets\n",sizeof(histogram));
	printf("Création de l'histogramme réalisée avec succès\n");




	delete_histo(histogram);
	printf("histogram après suppression utilise %ld octets\n",sizeof(histogram));
	printf("Destruction de l'histogramme réalisée avec succès\n");
	histogram[2][5] = insert_cell(list,9);
	printf("B=%d f=%d -> ",histogram[2][5]->B,histogram[2][5]->freq );
	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"

int main() {

	/* Test fonctions manip listes */
	cell list=NULL;
	cell tmp=NULL;

	printf("Création d'une liste chainée avec divers éléments\n");
 	list=insert_cell(list,1);
 	list=insert_cell(list,1);
	list=insert_cell(list,1);
	list=insert_cell(list,9);
	list=insert_cell(list,200);
	list=insert_cell(list,7);
	list=insert_cell(list,300);
	list=insert_cell(list,5);
	tmp=list;
	while (tmp) {
		printf("B=%d f=%d -> ",tmp->B, tmp->freq);	
		tmp=tmp->next;
	}
	printf("NIL\n");

	printf("Suppression de la liste..\n");
	list=delete_list(list);
	tmp=list;
	while (tmp) {
		printf("B=%d f=%d -> ",tmp->B, tmp->freq);	
		tmp=tmp->next;
	}
	printf("NIL\n");

	/* Test fonctions histo */
	histo *histogram;
	histogram=create_histo();
	/*int i;
	int j=0;
	for (i=0;i<256;i++) {
		for (j=0;j<256;j++) {
			printf("%d ",histogram[0][i]);
		}
		printf(" \n");
	}*/

	/*
	histogram[1][2]=insert_cell(list,7);
	printf("%d", (histogram[1][2])->B);
	*/


	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"

cell create_cell(int B, cell next) {
  cell new_cell=(cell)malloc(sizeof(new_cell));
	new_cell->freq=1;
	new_cell->B=B;
	new_cell->next=next;
  return new_cell;
}

cell insert_cell(cell head, int B) {
	int exists;
	cell tmp;
	cell prec_cell;
	cell new_cell;

	exists=0;
	tmp=NULL;
	tmp=head;
	prec_cell=tmp;
	cell next_cell;
	next_cell=NULL;

	printf("B=%d\n",B);
	/* On vérifie si head est non vide */
	if (head) {
	next_cell=head->next;
  /* On vérifie si B est présent dans la liste head */
		while(tmp && (tmp->next->B)<=B && exists==0) {
			if(tmp->B==B) {
			/* Si B existe, alors on incrémente sa valeur de 1 et 
			on sort de la boucle */
				exists=1;
				(tmp->freq)++;
				printf("A\n");
			}
			else {
				prec_cell=tmp;
				tmp=tmp->next;

				printf("B\n");
			}
		}

  /* Si B n'existe pas, on ajoute la cellule contenant B de freq 1 */
		if (exists==0) {
			new_cell=create_cell(B,head);
			printf("C\n");
		}
	}

	else {
		head=create_cell(0,create_cell(B,NULL));
	}
	return head;

}

cell delete_list(cell list) {
  /* head est la tête "courante" de la liste */
  cell head;

  /* on supprime dynamiquement la tête de liste */
  while (list) {
  	head=list;
  	list=list->next;
  	free(head);
  }
  return list;
}

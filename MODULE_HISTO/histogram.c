#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"

cell create_cell(int B, cell next) {
  cell new_cell=malloc(sizeof(new_cell));
	new_cell->freq=1;
	new_cell->B=B;
	new_cell->next=next;
  return new_cell;
}

cell insert_cell(cell head, int B) {
  int exists;

  cell prec_cell;
  cell new_cell;
  cell next_cell;

  exists=0;
  prec_cell=head;
  new_cell=NULL;
  next_cell=head->next;

  /* On vérifie si B est présent dans la liste head */
 	while(next_cell!=NULL && (next_cell->B)<=B && exists==0) {
    if(next_cell->B==B) {
    	/* Si B existe, alors on incrémente sa valeur de 1 et 
    	on sort de la boucle */
      exists=1;
    	(prec_cell->B)++;
    	printf("A %d\n",prec_cell->B);
    }
    else {
    	prec_cell=next_cell;
    	next_cell=next_cell->next;
    	printf("B\n");
    }
  }

  /* Si B n'existe pas, on ajoute la cellule contenant B de freq 1 
  entre prec_cell et next_cell */
  if (exists==0) {
    prec_cell->next=new_cell;
    new_cell=create_cell(B,next_cell);
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

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


  return cell;
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

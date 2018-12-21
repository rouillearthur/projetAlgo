#include <stdlib.h>
#include "histogram.h"

cell create_cell(int B, cell next) {
  cell new_cell=malloc(sizeof(new_cell));
  new_cell->freq=1;
  new_cell->B=B;
  new_cell->next=next;
  return new_cell;
}

cell insert_cell(cell head, int B) {
  int exists=0;
  cell cell;

  /* On vérifie si B est présent dans la liste head */
  while(head->next!=NULL && exists==0) {
    if(head->B==B)
      exists=1;
    else
      head=head->next;
  }

  /* Si B existe, alors on incrémente sa valeur de 1 */
  if (exists==1) {
    head->B=B+1;
    cell=head;
  }
  /* Sinon on ajoute la cellule contenant B de freq 1*/
  else {
    cell=create_cell(1,head);
  }
  return cell;
}

cell delete_list(cell list) {

  return list;
}

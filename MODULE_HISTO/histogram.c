#include <stdlib.h>
#include "histogram.h"

cell create_cell(int B, cell next) {
  cell *new_cell=malloc(sizeof(new_cell));
  new_cell->freq=1;
  new_cell->B=B;
  new_cell->next=next;
  return new_cell;
}

cell insert_cell(cell head, int B) {
  int exists=0;
  cell next_cell=head;
  while(next_cell.next!=NULL && exists==0) {
    if(next_cell.B==B)
      exists=1;
    else
      next_cell=next_cell.next;
  }
}

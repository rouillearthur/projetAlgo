#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"

int main() {
	cell list=NULL;
	cell tmp=NULL;
  list=create_cell(1,NULL);
 	list=insert_cell(list,1);
 	list=insert_cell(list,1);
	list=insert_cell(list,10);
	/*list=insert_cell(list,5);
	list=insert_cell(list,7);
	list=insert_cell(list,7);*/

	tmp=list;
	while (tmp) {
		printf("%d %d -> ",list->B, list->freq);	
		tmp=tmp->next;
	}
	printf("\n");

  return 0;
}

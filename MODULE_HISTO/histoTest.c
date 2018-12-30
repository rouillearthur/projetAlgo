#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"

int main() {
	cell list=NULL;
	cell tmp=NULL;
 	/*list=insert_cell(list,1);
 	list=insert_cell(list,1);*/
	list=insert_cell(list,10);
	/*list=insert_cell(list,9);*/
	/*list=insert_cell(list,7);
	list=insert_cell(list,7);*/

	tmp=list;
	while (tmp) {
		printf("%d %d %p -> ",list->B, list->freq, list->next);	
		tmp=tmp->next;
	}
	printf("\n");

  return 0;
}

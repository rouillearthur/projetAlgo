#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"

int main() {
	cell list=NULL;
	cell tmp=NULL;

	list=create_cell(20,NULL);
  list=insert_cell(list,2);

	tmp=list;
	while (tmp) {
		printf("%d %d -> ",list->B, list->freq);	
		tmp=tmp->next;
	}
	printf("\n");

  return 0;
}

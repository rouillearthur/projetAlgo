#include "histogram.h"
#include <stdlib.h>
#include <stdio.h>


int* triSelection(int* tabToSort, int n, int max) {
    int i;
    int j;
    int min;
    int echange;
    int* out;
    i = 0;
    j = 0;
    min = 0;
    echange = 0;

    for(i = 3; i < (n-4); i += 4) {
	min = i;
	for(j = i+4; j < n; j += 4) {
	    if(tabToSort[j] < tabToSort[min]) {
		min = j;
	    }
	    if(min != i) {
		echange = tabToSort[i];
		tabToSort[i] = tabToSort[min];
		tabToSort[min] = echange;

		echange = tabToSort[i-1];
		tabToSort[i-1] = tabToSort[min-1];
		tabToSort[min-1] = echange;

		echange = tabToSort[i-2];
		tabToSort[i-2] = tabToSort[min-2];
		tabToSort[min-2] = echange;

		echange = tabToSort[i-3];
		tabToSort[i-3] = tabToSort[min-3];
		tabToSort[min-3] = echange;
	    }
	}
    }

    for (i = 0; i < (4*max); i++) {
	out[i] = tabToSort[i];
    }
    return out;
}


void quantification(histo h, int* tab, int K) {
    int ctr;
    int* occ;
    histo_iter h_iter;
    ctr = 0;
    h_iter = create_histo_iter(h);

    occ[ctr] = h_iter->R;
    occ[ctr+1] = h_iter->G;
    occ[ctr+2] = h_iter->current->B;
    occ[ctr+3] = give_freq_histo_iter(h_iter);
    ctr += 4;

    while (next_histo_iter(h_iter) == true) {
	occ[ctr] = h_iter->R;
	ctr++;
	occ[ctr] = h_iter->G;
	ctr++;
	occ[ctr] = h_iter->current->B;
	ctr++;
	occ[ctr] = give_freq_histo_iter(h_iter);
	ctr++;
	printf("ctr=%d\n",ctr);
    }
    printf("Out\n");
    /* On a donc une liste avec toutes les couleurs de l'image ainsi que leur fréquence. On va alors trier jusqu'à obtenir les K premières valeurs */

    tab = triSelection(occ, sizeof(occ)/sizeof(int), K);

    /* L'algorithme de tri par sélection (un peu modifié pour convenir à notre cas) récupère les K plus grandes occurences de couleurs */
}

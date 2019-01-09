#include "histogram.h"
#include <stdlib.h>
#include <stdio.h>

int* tri(int* tabToSort, long n, long max) {
    long i, j;
    int	echange, bufR, bufG, bufB;
    int* out;
    i = 0;
    j = 0;
    echange = 0;
    bufR = 0;
    bufG = 0;
    bufB = 0;
    out = (int*) malloc(4*256*256*256*sizeof(int));

    for(i = 3; i < (n-1); i += 4) {
	echange = tabToSort[i];
	bufR = tabToSort[i-3];
	bufG = tabToSort[i-2];
	bufB = tabToSort[i-1];
	j = i;
	while((j > 3) && (tabToSort[j-4] > echange)) {
	    tabToSort[j] = tabToSort[j-4];
	    j = j-4;
	}
	tabToSort[j] = echange;
	tabToSort[i-1] = tabToSort[j-1];
	tabToSort[i-2] = tabToSort[j-2];
	tabToSort[i-3] = tabToSort[j-3];
	tabToSort[j-1] = bufB;
	tabToSort[j-1] = bufG;
	tabToSort[j-1] = bufR;
    }

    for (i = 0; i < (4*max); i++) {
	out[i] = tabToSort[i];
    }
    return out;
    /* On pourrait améliorer le code car on ne libère à aucun moment out */
}


void quantification(histo h, int* tab, long K) {
    long ctr;
    int* occ;
    histo_iter h_iter;
    ctr = 0;
    occ = (int*) malloc(4*256*256*256*sizeof(int));
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
	printf("R=%d, G=%d, B=%d, ctr=%ld\n",h_iter->R, h_iter->G, h_iter->current->B, ctr);
    }
    printf("Out\n");
    /* On a donc une liste avec toutes les couleurs de l'image ainsi que leur fréquence. On va alors trier jusqu'à obtenir les K premières valeurs */

    tab = tri(occ, sizeof(occ)/sizeof(int), K);

    /* L'algorithme de tri par sélection (un peu modifié pour convenir à notre cas) récupère les K plus grandes occurences de couleurs */
    free(occ);
}

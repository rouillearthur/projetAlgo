#include "histogram.h"
#include <stdlib.h>
#include <stdio.h>

cell create_cell(int B, cell next) {
	cell new_cell = (cell)malloc(sizeof(new_cell));
	new_cell->freq = 1;
	new_cell->B = B;
	new_cell->next = next;
	return new_cell;
}

cell insert_cell(cell head, int B) {
	int exists;
	cell tmp;
	cell prev_cell;
	cell new_cell;

	exists = 0;
	tmp = head;
	prev_cell = tmp;

 	/* On vérifie si head est non vide */
	if (head) {
   		/* On vérifie si B est présent dans la liste head */
		while(tmp && (tmp->B) <= B && exists == 0) {
			if(tmp->B == B) {
			/* Si B existe, alors on incrémente sa valeur de 1 et 
	   		on sort de la boucle */
				exists = 1;
				(tmp->freq)++;
			}
			else {
				prev_cell = tmp;
				tmp = tmp->next;
			}
		}
    	/* Si B n'existe pas, on ajoute la cellule contenant B de freq 1 */
		if (exists == 0) {
			/* Si on doit rajouter la cellule en tête de liste */
			if (tmp==head) {
				new_cell=create_cell(B,head);
				head=new_cell;
			}
			else {
				prev_cell->next = create_cell(B,tmp);
			}
		}
	}
	else {
		/* Si la liste est vide, on crée la cellule contenant B*/
		head=create_cell(B,NULL);
	}
	return head;

}

cell delete_list(cell list) {
  /* head est la tête "courante" de la liste */
	cell head;
  /* on supprime dynamiquement la tête de liste */
	while (list) {
		head = list;
		list = list->next;
		free(head);
	}
	return list;
}


histo create_histo(void) {
	int i;
	int j;
	histo **output=(histo**)malloc(256*sizeof(histo*));
	for (i=0;i<256;i++) {
		*(output+i)=(histo*)malloc(256*sizeof(histo));
		for (j=0;j<256;j++) {
			output[i][j]=NULL;
		}
	}
	return **output;

/*	histo* output;
	int i;
	int j;

	output = (histo*)malloc(256*256*8);
	output = NULL;*/
    /* On alloue puis on initialise le pointeur output  */
	/*for (i = 0; i < 256; i++) {
		output[i] = (histo)malloc(256*8);
		output[i] = NULL;
		for (j = 0; j < 256; j++) {
			output[i+j] = NULL;
		}
	}*/
    /* On alloue puis on initialise chaque case du tableau  */
	/*return *output;*/
}


void init_histo(histo hist, image img) {
	int i;
	int j;
	int B;
	int* pixel;
	for (i = 0; i < image_give_hauteur(img) ; i++) {
		for (j = 0; j < image_give_largeur(img) ; j++) {
			if (hist[i][j] == NULL) {
		/* Cree une liste a l’entree histo[R][G] si celle-ci est vide.  
		Cette liste contient la valeur de B avec une frequence egale a 1 */
			}
			else {
				pixel=image_read_pixel(img, i, j, img->courant);
				B=pixel[2];
				hist[i][j]=insert_cell(hist[i][j], B);
			}
		}
	}
}
/*
void delete_histo(histo hist) {
    int i;
    int j;
    for (i = 0; i < 256; i++) {
	for (j = 0; j < 256; j++) {
	    delete_list(*hist[i][j]);
	    }
	free(hist[i]);
    }
    free(hist);
}*/
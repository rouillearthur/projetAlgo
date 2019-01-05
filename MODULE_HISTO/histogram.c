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
	histo output = malloc(256*sizeof(cell*));
	for (i=0;i<256;i++) {
		output[i]=malloc(256*sizeof(cell));
		for (j=0;j<256;j++) {
			output[i][j]=NULL;
		}
	}
	return output;
}

void init_histo(histo hist, image image) {
	int i;
	int j;
	int B;
	unsigned char* pixel;
	pixel = 0;
	for (i = 0; i < image_give_hauteur(image) ; i++) {
		for (j = 0; j < image_give_largeur(image) ; j++) {
			image_read_pixel(image, i, j, pixel);
			B=pixel[2];
			if (hist[i][j] == NULL) {
				hist[i][j]=create_cell(B,NULL);
			}
			else {
				hist[i][j]=insert_cell(hist[i][j], B);
			}
		}
	}
}

void delete_histo(histo hist) {
    int i;
    int j;
    for (i = 0; i < 256; i++) {
		for (j = 0; j < 256; j++) {
		    if (hist[i][j] != NULL) {
				hist[i][j]=delete_list(hist[i][j]);
		    }
		}
    }
    free(hist);
    hist=NULL;
}

int give_freq_histo(histo h, int R, int G, int B) {
	int freq_histo;
	int exists;

	cell cell;
	cell=h[R][G];
	exists=0;
	/* On parcours h[R][G] pour vérifier si B existe */
	while (cell && exists==0) {
		if (cell->B==B) {
			/* Si B existe */
			exists=1;
			freq_histo=cell->freq;
		}
		cell=cell->next;
	}
	/* Si B n'existe pas */
	if (exists==0) {
		freq_histo=0;
	}

	return freq_histo;
}

histo_iter create_histo_iter() {
	/* EN CONSTRUCTION, JE PENSE QUIL FAUT CREER UN HISTO COMME VARIABLE GLOBALE */
	histo_iter new_histo;
	static histo histo;
	int R;
	int G;

	/* On cherche la première entrée non nulle */
	for (R=0;R<256;R++) {
		for (G=0;G<256;G++) {
			if (/*histo[R][G]!=NULL*/1) {
				break;
			}
		}
	}

	new_histo->R=R;
	new_histo->G=G;
	new_histo->current=histo[R][G];

	return new_histo;
}


void start_histo_iter(histo_iter *histo) {
	/* C'est si facile ??*/
	*histo=create_histo_iter();
}

boolean next_histo_iter(histo_iter histo) {
	boolean bool;

	return bool;
}

void give_color_histo_iter(histo_iter histo, int* pixel) {
	pixel[0]=histo->R;
	pixel[1]=histo->G;
	pixel[2]=histo->current->B;
}

int give_freq_histo_iter(histo_iter histo) {
	int freq;
	while (histo->current) {

	}
	return freq;
}

void delete_histo_iter(histo_iter histo) {

}

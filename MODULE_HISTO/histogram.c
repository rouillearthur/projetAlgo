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


void init_histo(histo h, image image) {
	int R,G,B;
	int* pixel;
	image_debut(image);
	do {
		do {
				pixel=image_lire_pixel(image);
				R = pixel[0];
				G = pixel[1];
				B = pixel[2];
				if (h[R][G]) {
					/* Autrement on incrémente la fréquence de la couleur de composante B ou on ajoute une cellule B */
					h[R][G]=insert_cell(h[R][G], B);
				}
				else {
					/* On crée une cellule si la couleur du pixel n'est pas encore présente dans l'histogramme */
					h[R][G]=create_cell(B,NULL);
				}
			} while(image_pixel_droite(image));/* On  parcourt la ligne de gauche à droite*/
	} while(image_pixel_suivant(image)); 
	
}


void delete_histo(histo h) {
	int i;
	int j;
	for (i = 0; i < 256; i++) {
		for (j = 0; j < 256; j++) {
	    /* On parcourt tout le tableau et si une liste ne correspond pas au pointeur NULL (si elle est non vide), alors on la supprime  */
			if (h[i][j] != NULL) {
				h[i][j] = delete_list(h[i][j]);

			}
		}
	}
	free(h);
	h = NULL;
    /* Une fois tous les éléments supprimés, on supprime le tableau en lui-même */
}


int give_freq_histo(histo h, int R, int G, int B) {
	int freq_histo;
	int exists;

	cell cell=h[R][G];
	exists=0;
    /* On parcours h[R][G] pour vérifier si B existe */
	while (cell && exists==0) {
		if (cell->B==B) {
	    /* Si B existe */

			exists=1;
			freq_histo=cell->freq;
		}
		else {
			cell=cell->next;
		}
	}
    /* Si B n'existe pas */
	if (exists==0) {
		freq_histo=0;
	}

	return freq_histo;
}


histo_iter create_histo_iter(histo h) {
	int exists,R,G;
	histo_iter h_iter = malloc(sizeof(histo_iter));

	R = 0;
	G = 0;
	exists=0;

	/* On cherche la première entrée non nulle */
	while (exists==0) {
		/* On regarde si la prochaine liste est non vide */
		if (h[R][G]!=NULL) {
			exists=1;		
		}
		/* Lecture colonne par colonne puis ligne par ligne */
		else {
			if (G<256-1) {
				G++;
			}
			else {
				R++;
				G=0;
			}
		}
	}
	
	h_iter->R = R;
	h_iter->G = G;
	h_iter->current = h[R][G];
	h_iter->histo=h;

	return h_iter;
}


void start_histo_iter(histo_iter h_iter) {
	/*h_iter = create_histo_iter(h_iter->histo);*/
	int exists,R,G;
	h_iter->R=0;
	h_iter->G=0;
	h_iter->current = NULL;

	
	exists=0;
	R=h_iter->R;
	G=h_iter->G;

	/* On cherche la première entrée non nulle */
	while (exists==0) {
		/* On regarde si la prochaine liste est non vide */
		if (h_iter->histo[R][G]) {
			exists=1;		
		}
		/* Lecture colonne par colonne puis ligne par ligne */
		else {
			if (G<256-1) {
				G++;
			}
			else {
				R++;
				G=0;
			}
		}
	}

	h_iter->R=R;
	h_iter->G=G;
	h_iter->current = h_iter->histo[R][G];
}


boolean next_histo_iter(histo_iter h_iter) {
	boolean bool;
	cell next_cell;
	int R,G,exists;
	
	bool = false;
	next_cell = h_iter->current->next;
	R = h_iter->R;
	G = h_iter->G;
	exists = 0;

	if (next_cell != NULL) {
		/* On passe à l'élément suivant dans l'histogramme */
		h_iter->current = next_cell;
		/* On vérifie si on n'est pas en fin de liste */
		if (next_cell->next) 
			bool = true;
	}
	else {
		/* On passe à l'élément suivant dans l'histogramme */
		if (G < 255) {
			G++;
		}
		else {
			R++;
			G = 0;
		}
	
		while (exists == 0) {
			/* On regarde si la prochaine liste est non vide */
			if (h_iter->histo[R][G]) {
				exists = 1;
				/* Dans ce cas, la prochaine liste h[R][G] existe et on est pas en fin de liste */
				bool = true;	
			}
			/* Lecture colonne par colonne puis ligne par ligne */
			else {
				if (G < 255) {
					G++;
				}
				else {
					R++;
					G = 0;
				}
			}
		}
	}
	h_iter->R=R;
	h_iter->G=G;
	h_iter->current=h_iter->histo[R][G];
	/* Si la liste h[R][G] suivante n'existe pas ou si on est en fin de liste on renvoie false */ 
	return bool;
}


void give_color_histo_iter(histo_iter h_iter, int* pixel) {
	pixel[0] = h_iter->R;
	pixel[1] = h_iter->G;
	pixel[2] = h_iter->current->B;
}


int give_freq_histo_iter(histo_iter h_iter) {
	int freq = h_iter->current->freq;
	return freq;
}


void delete_histo_iter(histo_iter h_iter) {
	free(h_iter);
	h_iter = NULL;
}

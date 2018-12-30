#include "histogram.h"
#include "../MODULE_IMAGE/objet.h"
#include "../MODULE_IMAGE/classe.h"
#include "../MODULE_IMAGE/point.h"
#include "../MODULE_IMAGE/move_type.h"
#include "../MODULE_IMAGE/image.h"

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
  cell prec_cell;
  cell new_cell;

  exists = 0;
  tmp = NULL;
  tmp = head;
  prec_cell = tmp;
  cell next_cell;
  next_cell = NULL;

  printf("B = %d\n",B);
  /* On vérifie si head est non vide */
  if (head) {
    next_cell = head->next;
    /* On vérifie si B est présent dans la liste head */
    while(tmp && (tmp->next->B) <= B && exists == 0) {
      if(tmp->B == B) {
	/* Si B existe, alors on incrémente sa valeur de 1 et 
	   on sort de la boucle */
	exists = 1;
	(tmp->freq)++;
	printf("A\n");
      }
      else {
	prec_cell = tmp;
	tmp = tmp->next;

	printf("B\n");
      }
    }

    /* Si B n'existe pas, on ajoute la cellule contenant B de freq 1 */
    if (exists == 0) {
      new_cell = create_cell(B,head);
      printf("C\n");
    }
  }

  else {
    head = create_cell(0,create_cell(B,NULL));
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


histo create_histo() {
    
    histo* output;
    int i;
    int j;
    
    output = (histo*)malloc(256*256*8);
    output = NULL;
    /* On alloue puis on initialise le pointeur output  */
    for (i = 0; i < 256; i++) {
	output[i] = (histo)malloc(256*8);
	output[i] = NULL;
	for (j = 0; j < 256; j++) {
	    output[i+j] = NULL;
	}
    }
    /* On alloue puis on initialise chaque case du tableau  */
    return *output;
}


void init_histo(histo hist, image img) {
    int i;
    int j;
    int B;
    for (i = 0; i < img->hauteur ; i++) {
	for (j = 0; j < img->largeur ; j++) {
	    if ((*hist)[i] == NULL) {
		/* Cree  une  liste  a  l’entree histo[R][G]  si  celle-ci  est  vide.  Cette  liste contient la valeur de B avec une frequence egale a 1 */
	    }
	    else {
		B = image_read_pixel(img, i, j, img->courant);
		insert_cell((*histo)[i], B);
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
}
*/

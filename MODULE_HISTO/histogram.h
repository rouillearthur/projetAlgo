/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @author Arthur ROUILLÉ <arouille@ecole.ensicaen.fr>
 * @author Bastien HUBERT <bhubert@ecole.ensicaen.fr>
 * @version     1.0.0 - 2018-12-28
 *
 * @bug
 */


/**
 * @file histogram.h
 */

#ifndef __HISTOGRAM_H
#define __HISTOGRAM_H

#include "../MODULE_IMAGE/objet.h"
#include "../MODULE_IMAGE/classe.h"
#include "../MODULE_IMAGE/point.h"
#include "../MODULE_IMAGE/move_type.h"
#include "../MODULE_IMAGE/image.h"

typedef struct cell * cell;
struct cell
{
  unsigned char B;
  int           freq;
  cell          next;
};

typedef struct cell ***histo;

typedef struct histo_iter * histo_iter;
struct histo_iter
{
	int R,G;
	cell current;
};

typedef enum {false,true} boolean;

/**
 * Alloue dynamiquement une cellule en initialisant les champs B et next. Le champ freq est initialisé à 1.
 * @param B Intensité du bleu compris entre 0 et 255 d'un pixel donné
 * @param next Cellule suivante
 * @return Retourne la cellule contenant B de fréquence 1 et le pointeur vers la cellule suivante
 */
cell create_cell(int B, cell next);


/**
 * Ajoute une cellule contenant B avec la fréquence 1 si B n'est pas présent dans la liste head. 
 * Incrémente la fréquence de la cellule contenant B si celle ci existe. 
 * @param head Pointeur sur la liste chainée
 * @param B Intensité du bleu compris entre 0 et 255 d'un pixel donné
 * @return Retourne la liste head modifiée
 */
cell insert_cell(cell head, int B);


/**
 * Supprime toute les cellules d'une liste en libérant la mémoire.
 * @param list Pointeur sur la liste chainée
 * @return Retourne une liste vide.
 */
cell delete_list(cell list);


/**
 * @return 
 */
histo create_histo(void);


/**
 * @param  
 * @param 
 * @return 
 */
void init_histo(histo hist, image img);


/**
 * @param
 * @return 
 */
void delete_histo(histo hist);

/**
 * @param  
 * @param 
 * @return 
 */
int give_freq_histo(histo h, int R, int G, int B);

/**
 * @param  
 * @param 
 * @return 
 */
histo_iter create_histo_iter();

/**
 * @param  
 * @param 
 * @return 
 */
void start_histo_iter(histo_iter);

/**
 * @param  
 * @param 
 * @return 
 */
boolean next_histo_iter(histo_iter);

/**
 * @param  
 * @param 
 * @return 
 */
void give_color_histo_iter(histo_iter,int*);

/**
 * @param  
 * @param 
 * @return 
 */
int give_freq_histo_iter(histo_iter);

/**
 * @param  
 * @param 
 * @return 
 */
void delete_histo_iter(histo_iter);

#endif